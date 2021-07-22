# -*- encoding: utf-8 -*-
"""
Copyright (c) 2019 - present AppSeed.us
"""

from django import template
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, HttpResponse
from django.template import loader

from ..authentication.models import User


@login_required(login_url='/login/')
def index(request):
    users = User.objects.all()
    context = {
        'users': users,
        'segment': 'index',
        'all_user_count': User.objects.count(),
        'active_user_count': User.objects.filter(is_active=True).count()
    }

    return render(request, 'main_templates/index.html', context)


@login_required(login_url="/login/")
def pages(request):
    # context = {}
    # All resource paths end in .html.
    # Pick out the html file name from the url. And load that template.

    html_template = loader.get_template('page-404.html')
    return HttpResponse(html_template.render({}, request))
