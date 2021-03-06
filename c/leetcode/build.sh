#!/bin/bash

if [ "$CC" != "" ]; then
	$CC -Wall -Wextra -std=c99 -pedantic-errors -O0 -ggdb -lm -o "${1%".c"}.out" $1
else
	echo "Set your C compiler by CC environment variable. Example: export CC=gcc"
fi

