## 1
- /home/$USER
- /home/$USER

## 2

```bash
mkdir -p dir1/dir2/dir4/dir6
mkdir dir1/dir2/dir5
mkdir dir1/dir3
```

## 3
- dir1 parent
- dir2

## 4

```bash
cd dir1/dir2
touch f1.txt h22.txt g368.txt ../dir3/f3a.txt ../dir3/g56.doc ../dir3/g3x.pdf dir4/g23.doc
```

## 5

- The text files (with a `.txt` extension) that are inside `dir2` and the ones who start by `f` or `g` followed by a `3` or a `5` followed bya number between `4` and `7` or a lowercase letter

- The text files (with a `.txt` extension) that are inside `dir3` and the ones who start by `f` or `g` followed by a `3` or a `5` followed bya number between `4` and `7` or a lowercase letter


## 6 

```
dir1
└── dir3
    ├── f3a.txt
    ├── g3x.pdf
    └── g56.doc
```

## 7

| Perms        | Owner     | Creation Date |
|--------------|-----------|---------------|
| 644          | lblopes   | 29-12 15:43   |

Note: The date is not necessarily the creation date, but instead, the date when the file was last modified.

## 8

>- 1
>
>>    - User: Read, Write, Execute
>>    - Group: Read, Execute
>>    - Others: Read, Execute
>- 2
>
>>    - User: Read 
>>    - Group: Read, Execute
>>    - Others: Read, Execute
>- 3
>
>>    - User: Read
>>    - Group: 
>>    - Others: 
>- 4
>
>>    - User: Read, Write
>>    - Group: Read
>>    - Others: Read

## 9

- The first and fourth fields in each line, delimited by ':'

- The first and fourth fields in each line, delimited by ':' (sorted alphabetically)

## 10

- All strings `Rings` will be substituted by `Sword`

- All lines that contain the string 'Mordor': `In the Land of Mordor where the Shadows lie.`

- The number of lines (7)


## 11

```diff
- half as well as I should like;
- and I like less than half of you
---
+ half as well as I should do not like;
+ and I do not like like less than half of you
```

## 12

- The penultimate command of this sequence orders the numbers numerically in a new file (`numbers2.txt`).

- The last should (there is a typo) order the words in `words1.txt` alphabetically.

## 13

- The command `ps -A | wc -l` displays the number of active processes.

## 14

- The last command sends a SIGKILL to the emacs processes running in the background.