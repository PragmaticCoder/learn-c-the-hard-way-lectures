set history save on
set print pretty on
set pagination off

set logging file output.txt
set logging on

set arg hello
b main
r

refresh
