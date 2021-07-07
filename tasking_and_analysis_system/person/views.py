from django.shortcuts import render, redirect
from person.models import Person


def home_page(request):
    return render(request, "home_page.html")


def create_user(request):
    person1 = Person.objects.create(first_name = "Vardges", last_name = "Karapetyan")
    person1.save()
    return render(request, "home_page.html")


def show_all(request):
    users = Person.objects.all()
    return render(request, "show_all.html", {
        'aa': users
    })
