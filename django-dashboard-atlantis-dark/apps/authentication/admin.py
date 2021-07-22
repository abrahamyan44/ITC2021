from django.contrib import admin
from django.contrib.auth.models import  Group
from .models import User, Role, ServiceLocation
from django.contrib.auth.models import Permission


@admin.register(ServiceLocation)
class ServiceLocationAdmin(admin.ModelAdmin):
    search_fields = ['name']

    def has_module_permission(self, request):
        return False


@admin.register(User)
class UserAdmin(admin.ModelAdmin):
    fields = ['name',
              'last_name',
              'email',
              'role',
              'is_active',
              'service_location',
              'date_registered']

    def Service_location(self, obj):
        return ", ".join([str(p) for p in obj.service_location.all()])

    autocomplete_fields = ['service_location']

    list_display_links = ['email']

    list_display = ['name',
                    "last_name",
                    "email",
                    "role",
                    "is_active",
                    'Service_location']


@admin.register(Role)
class RoleAdmin(admin.ModelAdmin):
    def has_add_permission(self, request, obj=None):
        return False

    def has_delete_permission(self, request, obj=None):
        return False

    def has_change_permission(self, request, obj=None):
        return False


admin.site.unregister(Group)
