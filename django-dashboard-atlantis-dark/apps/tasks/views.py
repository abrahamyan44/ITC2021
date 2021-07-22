from django.contrib.auth.decorators import login_required
from django.shortcuts import render, redirect
from django.core.exceptions import ObjectDoesNotExist
from django.template.exceptions import TemplateDoesNotExist
from .models import *
from .forms import TaskForm
from apps.dashboard.views import pages


@login_required(login_url='/login/')
def tasks_view(request):
    # TODO add docstrings and comments for reviewers
    context = {
        'segment': 'tasks',
        'tasks': Task.objects.all()}
    return render(
        request,
        'main_templates/tasks/task_index.html',
        context
    )


@login_required(login_url='/login/')
def create(request, parent_id=None):
    parent_task = None
    if parent_id:
        try:
            parent_task = Task.objects.get(id=parent_id)
        except ObjectDoesNotExist:
            return pages(request)
        initial_dict = {
            'pid': parent_id,
            'creator': request.user,
            'create_date': datetime.today()
        }
    else:
        initial_dict = {
            'creator': request.user.name + " " + request.user.last_name,
            'create_date': datetime.today()
        }

    form = TaskForm(initial=initial_dict)

    if request.method == 'POST':
        request_dict = request.POST.copy()
        request_dict['creator'] = request.user
        form=TaskForm(request_dict)
        if form.is_valid():
            task = form.save()
            if not parent_id:
                task.pid = task.id
            task.save()
            return redirect('tasks')
    context = {
        'segment': ['tasks', 'create'],
        'form': form,
        'parent_task': parent_task,
    }
    return render(
        request,
        'main_templates/tasks/task_create_or_edit.html',
        context,
    )


@ login_required(login_url='/login/')
def edit(request, task_id):
    try:
        task = Task.objects.get(id=task_id)
    except ObjectDoesNotExist:
        return pages(request)

    form=TaskForm(
        instance=task, 
        initial={
            'creator': request.user.name + " " + request.user.last_name,
        }
    )
    if request.method == 'POST':
        request_dict = request.POST.copy()
        request_dict['creator'] = request.user
        form=TaskForm(request_dict, instance=task)
        if form.is_valid():
            form.save()
            return redirect('tasks')
    context={
        'segment': ['tasks', 'edit'],
        'form': form,
        'task_id': task_id,
    }
    return render(
        request,
        'main_templates/tasks/task_create_or_edit.html',
        context
    )
