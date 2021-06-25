'''
Program to find sum of Fibonacci numbers.
'''

#Cache values
fibo_dict = {}


def fibonacci(input_value): 
    if input_value in fibo_dict:
        return fibo_dict[input_value]
    
    if input_value == 1:
            value = 1
    elif input_value == 2:
            value = 1
    elif input_value > 2:
            value =  fibonacci(input_value-1) + fibonacci(input_value-2)
    
    fibo_dict[input_value] = value
    return value


def sum_of_fibos():
    sum = 0
    for i in range(1, 10):
        sum += fibonacci(i)
    
    print(sum)


sum_of_fibos()

