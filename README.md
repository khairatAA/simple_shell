# SIMPLE SHELL PROJECT

## Description

The simple shell is a custom shell with unique features. It as exact same output as `sh (/bin/sh)` as well as the exact same error output.

## Features

- Supports a list of allowed functions and system calls:
	- access (man 2 access)
	- chdir (man 2 chdir)
	- close (man 2 close)
	- closedir (man 3 closedir)
	- execve (man 2 execve)
	- exit (man 3 exit)
	- _exit (man 2 _exit)_
	- fflush (man 3 fflush)
	- fork (man 2 fork)
	- free (man 3 free)
	- getcwd (man 3 getcwd)
	- getline (man 3 getline)
	- getpid (man 2 getpid)
	- isatty (man 3 isatty)
	- kill (man 2 kill)
	- malloc (man 3 malloc)
	- open (man 2 open)
	- opendir (man 3 opendir)
	- perror (man 3 perror)
	- read (man 2 read)
	- readdir (man 3 readdir)
	- signal (man 2 signal)
	- stat (__xstat) (man 2 stat)__
	- lstat (__lxstat) (man 2 lstat)__
	- fstat (__fxstat) (man 2 fstat)__
	- strtok (man 3 strtok)
	- wait (man 2 wait)
	- waitpid (man 2 waitpid)
	- wait3 (man 2 wait3)
	- wait4 (man 2 wait4)
	- write (man 2 write)

- Supports both interactive mode and non-interactive mode.

## Testing

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Output
The has the exact same output as `sh (/bin/sh)` as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See example below)

Example of error with `sh`:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with the `hsh` program:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Installation

1. Clone the repository `https://github.com/khairatAA/simple_shell.git`
2. Navigate to the directory `cd simple_shell`
3. Compile the files using a C compiler to build the shell executable:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Usage

Execute the generated `hsh` binary to start the shell.

	- To execute in interactive mode:`./hsh`
	- To execute in non-interactive mode: `echo "command" | ./hsh`
	- Pass in commands as you would in the `sh` shell.

## Contributors

	- Khairat Adesina <khairatadesina01@gmail.com>
	- Joshua Oseghale <aigbokhaebholojoshua@gmail.com>
