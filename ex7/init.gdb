set history save on
set print pretty on
set pagination off

set logging file output.txt
set logging on
set confirm off

dashboard -enabled on

b main.c:14
r

refresh
