The destination string (`str`) is contained in a 8 chars buffer. So, the string can only be of 8 chars length max or else the src string will be copied to the destination without the NULL terminator

Note: We are actually warned of this in `strcpy()` manpage:

```
Beware of buffer overruns!
```

To solve this problem we could use the function `strlcpy` and specify the destiny size, while making sure that the string will be null terminated.