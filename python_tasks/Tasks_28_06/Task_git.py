import sys

command = sys.argv[1];
argument_count = len(sys.argv);
if (argument_count > 2):
        print("Sorry, I will do only first command.")

def git_command(command):
    if ("co" == command):
        command = "checkout";

    if ("st" == command):
        command = "status";

    if ("com" == command):
        command = "commit";

    if ("br" == command):
        command = "branch";

    print ("git ", command);

git_command(command)
