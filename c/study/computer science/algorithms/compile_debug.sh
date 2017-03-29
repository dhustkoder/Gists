#!/bin/bash

if [ "$CC" != "" ]; then
	$CC -std=c11 -Wall -Wextra -pedantic -O0 -ggdb -fsanitize=address -lm -o "${1%".c"}-d.out" $@
else
	echo "Set your C compiler by CC environment variable. Example: export CC=gcc"
fi

