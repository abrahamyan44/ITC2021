from django.urls import path
from .views import reports, reports2

urlpatterns = [
    path('', reports, name="reports"),
    path('reports/', reports2, name="reports2")
]
