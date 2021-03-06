#!/bin/bash

if [ "$CC" != "" ]; then
	$CC -std=c99 -Wall -Wextra -pedantic -O2 -lm -o "${1%".c"}.out" $1
else
	echo "Set your C compiler by CC environment variable. Example: export CC=gcc"
fi

