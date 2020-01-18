#!/bin/bash

# This script is used to automate debugging
usage() {
  echo "Usage ${0} [-d][-v]">&2
  echo 'Debug with automated tools'
  echo '-d Runs in debug mode with GDB.'
  echo '-v Runs in debug mode with Valgrind.'
  exit 1
}

debug_gdb() {
  echo 'Debugging with GDB'
  gdb -x .gdbinit ./ex20_alvi
  exit 0
}

debug_valgrind() {
  echo 'Debugging with Valgrind'
  valgrind ./ex20_alvi 1 82 39 44 1 2 3 4 9 8 01 10 11
  exit 0
}

make clean && clear && make

while getopts dv OPTION
do
  case ${OPTION} in
    d)
      debug_gdb
      ;;
    v)
      debug_valgrind
      ;;
    ?)
      usage
      ;;
  esac
done

./ex20_alvi 1 82 39 44 1 2 3 4 9 8 01 10 11
exit 0