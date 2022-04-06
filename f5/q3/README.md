The `fork()` call is made in line 10 creating a new process. This new process
will run before its parent and, since it's a child process, making a new `fork()` call will return the value 0, setting `value` to 1 and printing `CHILD: value = 1, addr = 0x...`.

Afterwards, the main process will have its thread unlocked and will continue running. However, since the return value of this call will be its child pid, it will go to the `else` branch and print `PARENT: value = 0, addr = 0x...`.

The memory addresses of both `value` variables will be the same since the variable `value` was created before the fork was created.