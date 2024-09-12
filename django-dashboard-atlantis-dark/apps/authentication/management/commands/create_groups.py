import logging
from django.contrib.contenttypes.models import ContentType
from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from django.contrib.auth.models import Permission
from apps.authentication.models import Role, ServiceLocation
from apps.authentication.models import User

GROUPS = ['Analyst', 'Task creator', 'Task distributer', 'Task executor', 'Admin']
SERVICE_LOCATION = ['Yerevan', 'Gyumri', 'Vanadzor', 'Goris', 'Stepanavan']
perm = {"Admin":
            {"add": "users",
             "edit": "user_information",
             "deactivate": "users",
             "delete": "users"},
        "Analyst": {'view': "upload_page",
                    'upload': "files_into_the_system",
                    'view': "reports_pages",
                    'generate': "reports",
                    'export': "xlsx/pdf_files",
                    'view': "analyst_specific_dashboard"
                    },
        "Task creator": {'view': "tasks_tab",
                         'view': "task_list",
                         'create': "new_task",
                         'edit': "own_tasks",
                         'assign': "task_to_the_user_with_task_distributor_role",
                         'view': 'only_users_with_role_tasks_distributor'},

        'Task distributer': {'view': "tasks_tab",
                             'view': "task_list",
                             'add': "new_subtask",
                             'edit': "own_subtask",
                             'assign': "subtask_to_user_with_role_task executor"
                             },
        'Task executor': {'view': "only_assigned_subtasks",
                          'edit': "assigned_tasks_only_status_field",
                          'view': "task_counts_according_to_statuses "}
        }


class Command(BaseCommand):
    help = 'Creates read only default permission groups for users'

    def handle(self, *args, **options):

        i = 9
        Role.objects.all().delete()
        ServiceLocation.objects.all().delete()
        for group in GROUPS:
            new_group, created = Role.objects.get_or_create(name=group)
            for p in perm:
                for b in perm[p]:
                    name = 'can_{}_{}'.format(b, perm[p][b])
                    print(name)
                    content_type = ContentType.objects.get(app_label="authentication", model='role')
                    permission = Permission.objects.create(codename=name + str(i),
                                                           name=name,
                                                           content_type=content_type)
                    new_group.permissions.add(permission)
                    i += 1
            for service_location in SERVICE_LOCATION:
                ServiceLocation.objects.get_or_create(name=service_location)

    print("Created default group and permissions.")
