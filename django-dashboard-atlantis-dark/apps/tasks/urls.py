from django.urls import path
from .views import tasks_view, edit, create

urlpatterns = [
    path('', tasks_view, name="tasks"),
    path('create/<int:parent_id>/', create, name="subtask_create"),
    path('create/', create, name="task_create"),
    path('edit/<int:task_id>/', edit, name="task_edit"),
]
