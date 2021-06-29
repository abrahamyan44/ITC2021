import re

def password_validation():
    text = input("Enter example of password ");
    valid = re.compile("(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*#?&])[\w/g\d@$!%*#?&]{8,}$")
    result = re.fullmatch(valid, text);
    if result:
        print("It's a valid example of password");
    else:
        print("It's not a valid example of password");

password_validation();
