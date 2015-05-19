#!/bin/bash

libs=quicksort.c

failures=0
for src in 1_*.c; do
  gcc $src $libs -o a.out
  ./a.out
  if [ $? -ne 0 ]; then
    failures=$(( failures + 1 ))
  fi
done

exit $failures
