You can't execute commands with arguments, because in the function call `execlp(command, command, (char *)0)`, `command` is the string that the user inputs to the buffer, so if you input a command with arguments, following the documentation of `execlp`, you should pass firstly the file, and then one argument per parameter in the call. 

However, in this case, we have 2 problems:
```
For example, let's assume command is "touch a" (we have 2 problems)

    - The file "touch a" will not be found;

    - All the arguments are passed to the 2nd parameter, instead of being divided in the 2nd and 3rd arguments.
```