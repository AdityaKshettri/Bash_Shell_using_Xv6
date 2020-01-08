# Bash_Shell_using_Xv6
Bash Shell Scripting using Xv6 OS

# XV6 :

Xv6 is a teaching operating system. Xv6's use of the x86 makes it more relevant to students' experience than V6 was and unifies the course around a single architecture.

Xv6 is a nifty operating system that is essentially a reimplementation of Sixth Edition Unix that, unlike most of the huge montholithic Linux or BSD distributions that you'd run on your workstation or server, is simple enough to be used as a learning tool. Though xv6 lacks in functionality that you'd expect from a modern operating system, much of the core unix concepts and structure remain the same. xv6 is also very lightweight, only taking a few seconds to compile and allows remote debugging. This all makes it great for understanding how modern operating systems hang together.

# Bash Shell :

Bash is a Unix shell and command language written by Brian Fox for the GNU Project as a free software replacement for the Bourne shell. First released in 1989, it has been distributed widely as the default login shell for most Linux distributions and Apple's macOS (formerly OS X). A version is also available for Windows 10. 

Bash is a command processor that typically runs in a text window, where the user types commands that cause actions. Bash can also read and execute commands from a file, called a shell script. Like all Unix shells, it supports filename globbing (wildcard matching), piping, here documents, command substitution, variables, and control structures for condition-testing and iteration. The keywords, syntaxand other basic features of the language are all copied from sh. Other features, e.g., history, are copied from csh and ksh. Bash is a POSIX-compliant shell, but with a number of extensions.

# Classification :

The Shell Implementation Is Divided Into 3 Parts:

1 Input Processing:

•	Interactive mode:
            Reading input from terminal interactive mode
            
•	Non interactive mode:
             Reading from a script file in non interactive mode

Shell Programs:

A shell program is an application that allows interacting with the computer. In a shell the user can run programs and also redirect the input to come from a file and output to come from a file. Shells also provide programming constructions such as if, for, while, functions, variables


2 Parsing :

•	parsing reads the command line and creates a command table with all the arguments which will be executed
eg ls -l

•	here ls is the command –l (long listing) is the argument

•	tools like lex and yacc for parsing

•	Also strtok can be used

•	Eg token = strtok(NULL, LSH_TOK_DELIM);

•	In parsing we check for inbuilt system unix functions

•	Eg ls , grep , echo are inbuilt system functions, 

•	In case of bash shell commands like for or while loop we implement this using a c file and also check for syntax errors


3 Executing The Command :

•	executing the command generated by the parser:

•	fork and wait 

•	Fork will ensure that the child process will be executed and only then the parent process will continue its execution

•	The parent process must be kept on hold in the meanwhile

•	Also for standard input output and error conditions must be check and must be redirected accordingly

Piping :

Piping occurs when the output of one process is given to the input of another process 
Eg ls –l | grep  ‘abc’. So piping of functions is implemented.



# Adding a system call :

•	To add a system call that can be called in xv6's shell, you should so something with the five files
•	sysproc.c add the real implementation of your method here
•	syscall.h define the position of the system call vector that connect to your implementation
•	user.h define the function that can be called through the shell
•	syscall.c external define the function that connect the shell and the kernel, use the position defined in syscall.h to add the function to the system call vector
•	usys.S use the macro to define connect the call of user to the system call function
•	defs.h add a forward declaration for your new system call
•	sysfunc.h add the new system call handler into this file too like "int sys_newsystemcall(void)"

# Bash shell with functionalities for xv6

1.	Bsh – bash shell which contains all system calls.

 

2. Editor – text editor just like gedit in linux
3. Echo – to input the contents into the file.
4. mkdir – for making new directory.

 
5. Ls – the list of all the system calls.

 

6. cat – to display the contents of the file.

 

7. grep – for searching a word or a letter in the given file.

 

8. wc – line count, word count, letter count in the file.

 

9. cp – for copying the contents from one file to another.
 

10. rm – deletes the respective file.
11. exit – to exit from current file.

 
12. ps – to tell the program status of the functions or commands used.

 

13. ascsort – sorting the contents in file in ascending order.

 

20. fact -  to print factorial of a given number
 

17. NumToWord – to convert number into words.
 

14. descsort – sorting the contents in file in descending order.

 

15. bs – binary search for the contents in the file.

 

16. tt – to print truth table for a given positive integer input.

 


18. fib – for printing given number of the Fibonacci series.

 

19. toh – a code to solve towers of Hanoi problem.

 


21. pat – for pattern printing with help of “#”

 


# HARD & SOFT REQUIREMENTS :

For this project, we need linux either directly as Operating System in the computer system or installed in the VM Ware. Then we need to install xv6 in linux along with qemu which helps to run our bash shell.


