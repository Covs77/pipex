
# So_long 
Proyecto pipex de 42Málaga

Emulador de comportamiento de pipe en shell.

./pipex archivo1 comando1 comando2 archivo2
<archivo1 comando1 | comando2 archivo2>

Ej:
./pipex infile "ls -l" "wc -l" outfile

"<infile ls -l | wc -l > outfile"


archivo: nombre de archivo.
comando: comandos de shell con sus parámetros.

Allowed functions:

open, close, read, write,malloc, free, perror,
strerror, access, dup, dup2,execve, exit, fork, pipe,
unlink, wait, waitpid.
Libft & ft_printf and any equivalent I coded.
