from django import forms
from .models import Task

# TODO make constants Uppercase
#  move constants under corresponding module/classes
WHOLE_STYLE = 'border-radius: 5px; padding: 5px; border: 1px solid rgb(241, 241, 241);'
READONLY_STYLE = 'background: rgb(241, 241, 241); border-radius: 0; color: black;'


class DateInput(forms.DateInput):
    input_type = 'date'


class TaskForm(forms.ModelForm):
    class Meta:
        model = Task
        fields = ['pid', 'creator', 'executor', 'task_title',
                  'task_description', 'create_date', 'deadline', 'progress',
                  'current_state', 'target_state']
        widgets = {
            'pid': forms.NumberInput(
                attrs={
                    'readonly': 'readonly',
                    'style': READONLY_STYLE + WHOLE_STYLE + "width: 100%;",
                }
            ),
            'creator': forms.TextInput(
                attrs={
                    'readonly': 'readonly',
                    'style': READONLY_STYLE + WHOLE_STYLE + "width: 100%",
                }
            ),
            'executor': forms.Select(
                attrs={
                    'class': 'form-control',
                    'style': WHOLE_STYLE,
                }
            ),
            'task_title': forms.TextInput(
                attrs={
                    'class': 'form-control',
                    'style': WHOLE_STYLE,
                }
            ),
            'task_description': forms.Textarea(
                attrs={
                    'class': 'form-control',
                    'style': 'resize: none;' + WHOLE_STYLE,
                    'rows': 5, 'cols': 35,
                }
            ),
            'progress': forms.Select(
                attrs={
                    'class': 'form-control',
                    'style': WHOLE_STYLE,
                }
            ),
            'current_state': forms.NumberInput(
                attrs={
                    'readonly': 'readonly',
                    'min': 0, 'max': 100,
                    'style': 'width: 90%;' + WHOLE_STYLE + READONLY_STYLE
                }
            ),
            'target_state': forms.NumberInput(
                attrs={
                    'min': 0,
                    'max': 100,
                    'style': 'width: 90%;' + WHOLE_STYLE
                }
            ),
            'create_date': DateInput(
                attrs={
                    'readonly': 'readonly',
                    'style': READONLY_STYLE + 'width: 100%;' + WHOLE_STYLE
                }
            ),
            'deadline': DateInput(
                attrs={
                    'style': 'width: 100%;' + WHOLE_STYLE
                }
            ),
        }

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.fields['pid'].required = False
        self.fields['creator'].required = False
