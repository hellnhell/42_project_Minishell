# Minishell

The objective of this project is to create a simple shell from scratch. Replicating bash functionalities, using processes and file descriptors.

### Mandatory Part

Implemented builtins:

* echo with option '-n'.
* pwd without any options.
* export without any options.
* cd with only a relative or absolute path.
* unset without any options.
* env without any options.
* exit without any options.
* ';' in the command separate commands like in bash.
* Redirections '<', '>' and '>>' work like in bash except for file descriptor aggregation.
* Pipe lines '|' work like in bash except for multiline commands.
* Envairoment variables '$'.
