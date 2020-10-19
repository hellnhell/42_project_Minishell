# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<errno.h>


int		main(int argc, char **argv, char **env)
{
    printf("%s\n", env[0]);
    int j = execve("/bin/echo", argv, env);
    return (0);
}