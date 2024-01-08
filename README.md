
# Pipex
Proyecto pipex de 42Málaga

Este proyecto va sobre el manejo de pipes,tu programa deberá ejecutarse de la siguiente forma:
./pipex archivo1 comando1 comando2 archivo2
Deberá utilizar 4 argumentos:
• archivo1 y archivo2 son nombres de arhivos.
• comando1 y comando2 son comandos de shell con sus respectivos parámetros.
La ejecución del programa pipex deberá hacer lo mismo que el siguiente comando de shell:
$> < archivo1 comando1 | comando2 > archivo2

Ejemplos
$> ./pipex infile "ls -l" "wc -l" outfile
deberá hacer lo mismo que “<infile ls -l | wc -l >outfile”
$> ./pipex infile "grep a1" "wc -w" outfile
deberá hacer lo mismo que “<infile grep a1 | wc -w >outfile”

Allowed functions:
open, close, read, write,malloc, free, perror,
strerror, access, dup, dup2,execve, exit, fork, pipe,
unlink, wait, waitpid.
Libft & ft_printf and any equivalent I coded.
