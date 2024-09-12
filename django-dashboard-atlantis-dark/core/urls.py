# -*- encoding: utf-8 -*-
"""
Copyright (c) 2019 - present AppSeed.us
"""

from django.conf.urls import url
from django.contrib import admin
from django.contrib.auth import views as auth_views
from django.urls import path, include  # add this

urlpatterns = [
    path('admin/', admin.site.urls),
    # path('admin/', admin.site.urls, name="admin"),  # Django admin route
    path("tasks/", include("apps.tasks.urls")),
    path("reports/", include("apps.reports.urls")),
    path("upload/", include("apps.upload.urls")),  # Auth routes - login / register
    path("", include("apps.authentication.urls")),
    path("", include("apps.dashboard.urls")),

]
