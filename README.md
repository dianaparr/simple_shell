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
|`read_path`             | reads the paths that the user enters                             |
|`create_child_path` | create the child process to execute path                                  |
|`read_commands`         | reads the commands that the user enters                             |
|`create_child_commands`   | create the child process to execute commands                          |


* **functions_helper.c**: Contains functions that help the shell to perform well.


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`**alloc_double_pointer`   | create and store information in a double pointer                         |
|`_words` | word count                                |
|`*_calloc`         | function that allocates memory for an array                            |
|`*_getenv`   | scans the environment until a environment variable is found                          |
|`_spaces`   | confirms if there are only space at the entrance                          |


* **functions_strings.c and functions_strings_2.c**: Contains functions for string handling


|     FUNCTION       |        SHORT DESCRIPTION         |
|--------------------|---------------------------------|
|`_strlen`           | length of a string                |
|`*_strcpy`           | copy string for destination      |
|`*_strchr`           | function locates the first ocurrence of character                                                |
|`_strncmp`          | compare the first n bytes of the string|
|`_strcmp`           | compare two strings                 |
|`*str_concat`           | concatenates two strings                 |
|`*_strcat`          | concatenate two strings             |
|`relative_path`          | execute a relative path             |
|`signal_ctrl_c`             | change a integer to string          |
|`*_strdup`          | sends a signal when ctrl+c is pressed            |


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
|`free_dp` | free a double pointer    |


* **built_in.c**: functions for handling built-ins


|     FUNCTION       |     SHORT DESCRIPTION           |
|--------------------|---------------------------------|
|`_functions_shell_own` | function that stores the built-in functions |
|`func_exit`   | function for exit of the program     |
|`func_env`   | function that print the environment     |


## Shell usage :memo:
Our simple shell can be used in two modes which are divided based on the way a user could interact in it, that is, in the interactive mode the user interacts as many times as he wants in the shell as long as the -#shellDB$ - prompt appears on the screen.
On the contrary, in the non-interactive mode, the user enters a command without waiting for the prompt to appear, simply by using pipe | and ./hsh

### Mode interactive
![Mode_interactive](https://raw.githubusercontent.com/dianaparr/simple_shell/pics_flowchart/mode_interactive.png)

### Mode no-interactive
![Mode_no_interactive](https://raw.githubusercontent.com/dianaparr/simple_shell/pics_flowchart/Mode_no_interactive.png)

## Compilation :checkered_flag:

This super shell is compiled with all these flags:
   
     gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Created on `Ubuntu 14.04 LTS`, compiled with the version `gcc 4.8.4`
## More information about our shell :speaking_head:
You can click on the following [link](https://drive.google.com/file/d/19gYtjMn_bGpWHC7_6iKJU1Dh9mSxMwCZ/view?usp=sharing) to view our program flowchart . You can also read a short [article](https://www.linkedin.com/post/edit/6788296403128000512/) about what happens when we type in the shell, the command "ls -l *.c". 

## Authors :registered:
:woman_technologist: **Diana Parra**
* [GitHub](https://github.com/dianaparr)
* [Twitter](https://twitter.com/dianaparra017)

:man_technologist: **Brian Zapata**
* [GitHub](https://github.com/brian-1989)
* [Twitter](https://twitter.com/BrianZa03390210)

**Project to:** 
![](https://www.holbertonschool.com/holberton-logo.png)
