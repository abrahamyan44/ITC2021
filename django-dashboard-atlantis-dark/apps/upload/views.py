from django.http.response import HttpResponse
from django.shortcuts import render
from django.contrib.auth.decorators import login_required



@login_required(login_url='/login/')
def upload(request):
    context = {}
    context['segment'] = 'upload'
    return render(request, 'main_templates/index.html', context)
