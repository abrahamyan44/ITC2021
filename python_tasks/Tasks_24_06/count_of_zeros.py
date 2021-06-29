def count_of_zeros():
    input_num = input("Enter any integer: ")
    num = int(input_num);
    count = 0;
    while(num > 0):
        if(0 == num%10):
            count = count + 1;
        num = (num - num%10)/10;
    print("Count of zeros is ", count);

count_of_zeros();
