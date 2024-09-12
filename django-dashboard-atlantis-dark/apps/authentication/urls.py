# -*- encoding: utf-8 -*-
"""
Copyright (c) 2019 - present AppSeed.us
"""

from django.urls import path

from .views import login_view, forgot_password, reset_password
from django.contrib.auth.views import LogoutView

urlpatterns = [
    path('login/', login_view, name='login'),
    path('reset-password/<str:hash>/', reset_password, name='reset-password'),
    path('logout/', LogoutView.as_view(), name='logout'),
    path('forgot-password/', forgot_password, name='forgot-password'),
]
