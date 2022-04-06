8 processes will be creates (2^n, n = 3).

- The first fork (inside the main process) will create a new process

- This new process will be executing from the same point of its parent, so, afterwards both process will create a new process having a total of 4 processes

- Now, each of this processes will create a new one and we will then have a total of 8 processes.