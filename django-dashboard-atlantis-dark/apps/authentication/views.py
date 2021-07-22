# -*- encoding: utf-8 -*-
"""
Copyright (c) 2019 - present AppSeed.us
"""

from django.contrib.auth import authenticate, login, logout
from django.core.mail import send_mail, EmailMessage
from django.db.models.signals import post_save
from django.dispatch import receiver
from django.http import HttpResponse
# Create your views here.
from django.shortcuts import render, redirect
from django.template.loader import render_to_string

from core.settings import EMAIL_HOST_USER
from .forms import *
from .models import User


@receiver(post_save, sender=User)
def send_new_officer_notification_email(sender, instance, created, **kwargs):
    if created:
        subject, from_email, to = 'Invitation Email', EMAIL_HOST_USER, [instance.email]
        text_content = 'This is an important message.'
        html_content = render_to_string('accounts/password/invitation_email.html')
        msg = EmailMessage(subject, html_content, from_email, to)
        msg.content_subtype = 'html'
        msg.send(fail_silently=False)


def send_invitation(subject, email, email_template_name):
    email_template = render_to_string(email_template_name)
    try:
        send_mail(subject, email_template, EMAIL_HOST_USER, [email], fail_silently=False)
        return "Sent"
    except:
        return "Can`t send"


def forgot_password(request):
    email_send_form = EmailForm()
    message = ""
    if request.method == "POST":
        email_send_form = EmailForm(request.POST)
        if email_send_form.is_valid():
            email = email_send_form.cleaned_data['email']
            try:
                User.objects.get(email=email)
                subject = "Password Reset Requested"
                email_template_name = "accounts/password/password_reset_email.txt"
                message = send_invitation(subject, email, email_template_name)
            except:
                message = "Email not valid"

    context = {
        'msg': message,
        "email_send_form": email_send_form,
    }

    return render(request, "accounts/login.html", context)


def login_view(request):
    logout(request)

    form = LoginForm(request.POST or None)
    msg = None
    if request.method == "POST":
        if form.is_valid():
            username = form.cleaned_data.get("username")
            password = form.cleaned_data.get("password")
            user = authenticate(username=username, password=password)
            if user is not None:
                login(request, user)
                print('hsldfhskdhfksdhf =>>>>>>', request.user)
                return redirect("/")
            else:
                msg = 'Invalid credentials'
        else:
            msg = 'Error validating the form'

        
    return render(request, "accounts/login.html", {"form": form, "msg": msg})


def register_user(request):
    success = False

    if request.method == "POST":
        form = SignUpForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get("username")
            raw_password = form.cleaned_data.get("password1")
            user = authenticate(username=username, password=raw_password)

            msg = 'User created - please <a href="/login">login</a>.'
            success = True

            # return redirect("/login/")

        else:
            msg = 'Form is not valid'
    else:
        form = SignUpForm()

    return render(request, "accounts/register.html", {"form": form, "msg": msg, "success": success})


def reset_password(request, hash):
    return HttpResponse(hash)

