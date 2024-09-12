from django.db import models
from django.contrib import admin
from apps.authentication.models import User
from datetime import datetime


class Progress(models.Model):
    """
    Intended to show the current status of the task.Can be 'New', 'In progress', 'Rejected', 'Complete'
    """
    name = models.CharField(
        max_length=15,
        default="new")

    def __str__(self):
        return self.name


class Task(models.Model):
    pid = models.PositiveIntegerField(
        blank=True,
        null=True)
    creator = models.ForeignKey(
        User,
        on_delete=models.CASCADE,
        related_name="task_creator",
    )
    executor = models.ForeignKey(
        User,
        on_delete=models.CASCADE,
        related_name="task_executor"
    )
    progress = models.ForeignKey(
        Progress,
        on_delete=models.CASCADE,
        blank=True,
        null=True)
    # TODO read about BLANK and NULL constraints
    create_date = models.DateField()
    deadline = models.DateField()
    task_title = models.CharField(
        max_length=30)
    task_description = models.TextField(
        blank=False)
    current_state = models.SmallIntegerField(
        default=0)
    target_state = models.SmallIntegerField(
        default=100)

    def __str__(self):
        return self.task_title

    class Meta:
        verbose_name = "Task"
        verbose_name_plural = "Tasks"
        ordering = ["deadline"]
