## 2
- The error was that `sin` and `cos` were not defined. But even after including the header file `math.h` they weren't, because `math.h` is not a part of the standard C library, so it has to be linked.

    To do it you have to pass the flags `-lm`. 
    - `-l` searches the library library while linking. 
    - `-m` stands for libm, the library that contains <math.h>.

    So, to fully compile the file you can use `gcc -Wall -lm -o trig trig.c`.

## 3

| Mem   |  1 - Stack| 2 - Stack   | 3 - Stack  |
--------|-----------|-------------|------------|
| +0    |  i = 5    |  i = 7      |  i = 7     |
| +4    |  j = 0    |  j = 3      |  j = 2     |
| +8    |  p -> i   |  p -> j     |  p -> j    |
| +16   |  q -> ?   |  q -> j     |  q -> j    |

## 4

- Yes, it does, because `msg` is a pointer to the beginning of the array (base pointer), so, by adding the loop counter, we are doing pointer arithmetics and are increment by `sizeof(char)` in each iteration. Doing this and de-referencing afterwards is exactly the same as doing `msg[i]`. We don't need to divide sizeof(msg) by sizeof(char) since it is 1

- Yes, it does, because `primes` is a pointer to the beginning of the array (base pointer), so, by adding the loop counter, we are doing pointer arithmetics and are increment by `sizeof(int)` in each iteration. Doing this and de-referencing afterwards is exactly the same as doing `primes[i]`. Since `sizeof(int)` is 4 bytes, we have `sizeof(primes) / sizeof(int)` iterations. 

## 5

| Mem   |  1 - Stack| 2 - Stack   | 3 - Stack  |
--------|-----------|-------------|------------|
| +0    |  n1 = 1   |  n1 = 1     |  i = 2     |
| +4    |  n2 = 2   |  n2 = 2     |  j = 1     |
| +8    |           |  p1 -> n1   |            |
| +16   |           |  p2 -> n2   |            |

- In the first program the values aren't swapped because the function makes a shallow copy of them, in other words, when the function is called, 2 new variables (not related to the ones in main) are created and those are changed. On the other hand, on the second example, the actual memory positions are passed and we deference the real values to swap them, having, in that case, success.

## 6

- In the first example, the variable i is local to the function stack frame, which will be destroyed after the function call. So, we are trying to retrieve a pointer of a non-existing integer

## 7

- Initially the program runs as expected, firstly creating a stack frame for f1, then for f2 and finnally for f3 and after that destroying the frame from f3, then from f2 and then from f1, printing the stack strace in each of the calls.

- One more stack frame will be created after f3's call and, destroyed after its return.

## 8

1. Yes, because since the function has no return, the local variable `x` will be used in the function `g` call before it is destroyed.

2. No, because `x` is a local variable, so we are passing an invalid pointer to outside the function's scope.

3. Yes, because we are allocation space in the heap for our variable, so it will be valid and won't be destroyed until we free that space.

4. Yes, because we are not even affecting any value, we are just calling g, then f creating 2 stack frames and then destroying f and g and returning (y + 2) ^ 2