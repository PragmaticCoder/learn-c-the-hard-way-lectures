set history save on
set print pretty on
set pagination off

set logging file output.txt
set logging on

set args 100 4 3 55 23 2

b main
r

refresh
