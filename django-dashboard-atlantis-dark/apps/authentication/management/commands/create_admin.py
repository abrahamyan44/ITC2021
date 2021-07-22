from django.core.management.base import BaseCommand, CommandError
from django.db.utils import IntegrityError
from apps.authentication.models import User


class Command(BaseCommand):
    def handle(self, *args, **options):
        try:
            User.objects.create_superuser(
                email='admin@gmail.com',
                password='admin'
            )
        except IntegrityError:
            print('User with this email is already exists')
