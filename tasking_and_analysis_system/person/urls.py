from django.urls import path
from .views import home_page,show_all,create_user

app_name = 'person'

urlpatterns = {
    path('', home_page, name='home'),
    path('show_all/', show_all, name='show_all')
}
