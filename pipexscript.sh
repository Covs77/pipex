#!/bin/sh

echo
echo
echo 'Examples with one pipe:'
echo

touch infile
echo 'Pipex: '
./pipex infile "ls -l" "grep ft" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe: '
< infile ls -l | grep ft > outfile_norm
cat -e outfile_norm
echo

touch infile
echo 'Pipex: '
./pipex infile "ls -l" "grep \"May 29 10\"" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe: '
< infile ls -l | grep "May 29 10" > outfile_norm
cat -e outfile_norm
echo

echo 'Pipex: '
./pipex infile "find ." "wc -l" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile find . | wc -l > outfile_norm
cat -e outfile_norm
echo

echo 'Pipex:'
./pipex infile "ls -l" "awk 'NR%2'" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe: '
< infile ls -l | awk 'NR%2' > outfile_norm
cat -e outfile_norm
echo







echo 'Examples with errors:'
echo

echo 'Wrong order: '
echo '1.Pipex: '
./pipex "ls -l" infile "grep file" outfile_pipex
cat -e outfile_pipex
echo '2.Pipex:'
./pipex infile "ls -l" outfile_pipex "grep file"
cat -e outfile_pipex
rm "grep file"
echo

rm infile
echo 'No infile:'
echo 'Pipex:'
./pipex infile "ls -l" "grep file" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe: '
< infile ls -l | grep file > outfile_norm
cat -e outfile_norm
echo

touch infile
chmod 000 infile
echo 'Infile without permission: '
echo 'Pipex:'
./pipex infile "ls -l" "grep file" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe: '
< infile ls -l | grep file > outfile_norm
cat -e outfile_norm
echo

chmod 644 infile
echo 'Wrong command:'
echo 'Pipex:'
./pipex infile "la -l" "grep file" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile la -l | grep file > outfile_norm
cat -e outfile_norm
echo

echo 'Wrong flag:'
echo 'Pipex:'
./pipex infile "ls -y" "grep file" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile /bin/ls -y | grep file > outfile_norm
cat -e outfile_norm
echo









echo 'Examples with multiple pipes: '
echo

echo 'Pipex:'
./pipex_bonus infile "ls -l" "grep file" "wc -l" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile ls -l | grep file | wc -l > outfile_norm
cat -e outfile_norm
echo

echo 'Pipex:'
./pipex_bonus infile "ls -l" "grep file" "wc -l" "bc" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile ls -l | grep file | wc -l | bc > outfile_norm
cat -e outfile_norm
echo

echo 'Pipex:'
./pipex_bonus infile "cat /etc/passwd" "grep -v '#'" "awk 'NR%2==0'" "cut -f 1 -d ':'" "rev" "sort -r" "sed -n -e \"1,20p\"" "sed '\$!s/$/,/'" "tr '\n' ' '" "sed '\$s/$/./'" outfile_pipex
cat -e outfile_pipex
echo 'Normal pipe:'
< infile cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | cut -f 1 -d ':' | rev | sort -r | sed -n -e "1,20p" | sed '$!s/$/,/' | tr '\n' ' ' | sed '$s/$/./' > outfile_norm
cat -e outfile_norm
echo

rm infile outfile_pipex outfile_norm

Heredoc examples:

./pipex_bonus here_doc abc "ls -l" "grep ft" outfile_pipex
cat -e outfile_pipex
ls -l << abc | grep ft >> outfile_norm
cat -e outfile_norm

./pipex_bonus here_doc abc "grep h" "tr 'h' 'H'" "sed 's/$/./'" outfile_pipex
cat -e outfile_pipex
grep h << abc | tr 'h' 'H' | sed 's/$/./' >> outfile_norm
cat -e outfile_norm

./pipex_bonus here_doc abc "grep h" "tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" "sed 's/$/./'" outfile_pipex