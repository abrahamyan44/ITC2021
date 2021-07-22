from django.shortcuts import render
from django.contrib.auth.decorators import login_required


@login_required(login_url='/login/')
def reports(request):
    if request.method == "POST":
        select1 = request.POST.get('select1')
        start_date = request.POST.get('start_date')
        # model.Objects.create(
        #     s_date=start_date,
        #
        # )
    context = {
        'segment': 'reports',
        'type': '1',
    }
    return render(request, 'main_templates/reports/report1.html', context)


@login_required(login_url='/login/')
def reports2(request):
    context = {
        'segment': 'reports',
        'type': '1',
    }
    return render(request, 'main_templates/reports/report2.html', context)
