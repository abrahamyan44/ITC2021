def number_of_digits():
    input_num = input("Enter any integer: ")
    num = int(input_num);
    count = 0;
    while(num > 0):
        count = count + 1;
        num = (num - num%10)/10;
    print("Count of digits is ", count);

number_of_digits();
