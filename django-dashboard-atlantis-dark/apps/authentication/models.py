from datetime import datetime

from django.contrib.auth.base_user import AbstractBaseUser
from django.contrib.auth.models import Group, PermissionsMixin
from django.db import models

from .managers import UserManager


class Role(Group):
    class Meta:
        verbose_name = "Role"
        permissions = ()


class ServiceLocation(Group):
    class Meta:
        verbose_name = "Service_Location"


class User(AbstractBaseUser, PermissionsMixin):
    name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    email = models.EmailField(max_length=100, unique=True)
    role = models.ForeignKey(Role, on_delete=models.PROTECT,
                             related_name='Role',
                             null=True)
    is_active = models.BooleanField(default=False, db_index=True)
    service_location = models.ManyToManyField(ServiceLocation,
                                              related_name='Service_Location')
    date_registered = models.DateTimeField(default=datetime.now, blank=True)
    is_superuser = models.BooleanField(default=False)
    is_staff = models.BooleanField(default=False)
    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['name']
    objects = UserManager()

    def __str__(self):
        return f'{self.name} {self.last_name}'

    class Meta:
        verbose_name = 'User'
        verbose_name_plural = 'Users'
