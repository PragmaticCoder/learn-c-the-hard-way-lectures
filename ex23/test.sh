#!/bin/bash

# This script is used to automate debugging
usage() {
  echo "Usage ${0} [-d][-v]" >&2
  echo 'Debug with automated tools'
  echo '-d Runs in debug mode with GDB.'
  echo '-v Runs in debug mode with Valgrind.'
  exit 1
}

debug_gdb() {
  echo 'Debugging with GDB'
  gdb -x .gdbinit ./ex22_main_alvi
  exit 0
}

debug_valgrind() {
  echo 'Debugging with Valgrind'
  valgrind ./ex23_alvi
  exit 0
}

make clean && clear && make

while getopts dv OPTION; do
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

./ex23_alvi
exit 0
