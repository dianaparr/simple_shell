# Simple shell (#shellDB$ ) 
## Description :spiral_notepad:

We create a shell (command line interpreter) similar to the Bourne shell (sh), whose general and main function is to receive what a user enters by terminal and interpret that set of instruction that are expected to be executed in the kernel of the OS.
This was quite a challenging project, but one in which we learned a lot. We hope you enjoy our shel!


## List of allowed functions and system calls :pushpin:


|     FUNCTION       |         MANUAL                  |
|--------------------|---------------------------------|
|`exceve(2)`         |[Execute program](https://man7.org/linux/man-pages/man2/execve.2.html)                         |
|`close(2)`          |[Close a file descriptor](https://man7.org/linux/man-pages/man2/close.2.html)   |
|`fork(2)`           |[Create a child process](https://man7.org/linux/man-pages/man2/fork.2.html)    |
|`malloc(3), free(3)`|[allocate and free dynamic memory](https://man7.org/linux/man-pages/man3/free.3.html)    |
|`getline(3)`        |[Delimited string input](https://man7.org/linux/man-pages/man3/getline.3.html) |
|`isatty(3)`         |[Test whether a FD refers to a terminal](https://man7.org/linux/man-pages/man3/isatty.3.html)  |
|`stat(2)`           |[Get file status](https://man7.org/linux/man-pages/man2/lstat.2.html)                          |
|`strtok(3)`         |[Extract tokens from strings](https://man7.org/linux/man-pages/man3/strtok.3.html)  |
|`wait(2)`           |[Wait for process to change](https://man7.org/linux/man-pages/man2/waitid.2.html)  |
|`write(2)`          |[Write to a FD](https://man7.org/linux/man-pages/man2/write.2.html)                          |


## List of own functions and files :ledger:
* **main.c**: Entry point of our simple shell. In this file you will find two key functions: getline() and isatty(), the first is perfect for shell usage (reading what a user passes through the command line) and the second is ideal for understanding the two modes in which our shell works (interactive and non-interactive [*see shell usage*], as it helps to determine if the standard input and output are directed to a terminal (TTY).

* **functions_shell.c**: Contains functions necessary for reading the path and commands, with the creation of child processes.


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`read_path`             |                             |
|`create_child_path` |                                 |
|`read_commands`         |                             |
|`create_child_commands`   |                          |


* **functions_helper.c**: Contains functions that help the shell to perform well.


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`**alloc_double_pointer`    |                         |
|`_words` |                                 |
|`*_calloc`         |                             |
|`*_getenv`   |                           |


* **functions_strings.c and functions_strings_2.c**: Contains functions for string handling


|     FUNCTION       |        SHORT DESCRIPTION         |
|--------------------|---------------------------------|
|`_strlen`           | length of a string                |
|`*_strcpy`           | copy string for destination      |
|`*_strchr`           | function locates the first ocurrence of character                                                |
|`_strncmp`          | compare the first n bytes of the string|
|`_strcmp`           | compare two strings                 |
|`*_strcat`          | concatenate two strings             |
|`_itoa`             | change a integer to string          |
|`*_strdup`          | duplicate of the string            |
|`*str_concat`       | concatenates two strings           |


* **tokenizer.c**


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`*_strtok`    | tokenizes word for word               |
|`*_strtok_v2` | tokenizes a complete string           |


* **errors.c**: here you will find the most common errors that can print our shell.


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`error_execve_paths` | error printed when execve fails |
|`error_stat_paths` | when stat fails, it does not find the command    |


## Shell usage :memo:
### Mode interactive

### Mode no-interactive

## Compilation :checkered_flag:

This super shell is compiled with all these flags:
   
     gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Created on `Ubuntu 14.04 LTS`, compiled with the version `gcc 4.8.4`

## Authors :registered:
:woman_technologist: **Diana Parra**
* [GitHub](https://github.com/dianaparr)
* [Twitter](https://twitter.com/dianaparra017)

:man_technologist: **Brian Zapata**
* [GitHub](https://github.com/brian-1989)
* [Twitter](https://twitter.com/BrianZa03390210)

**Project to:** 
![](https://www.holbertonschool.com/holberton-logo.png)

