Since the function `execlp` doesn't change the pid of the child process, if it executes successfully, `waitpid` in the parent will return a value of the process (usually a child) whose status information has been obtained.

That is different from -1, so we will get the message `child exited` printed.