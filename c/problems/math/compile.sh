#!/bin/bash

if [ "$CC" != "" ]; then
	$CC -std=c90 -Wall -Wextra -pedantic -O2 -lm -o ${1%".c"} $1
else
	echo "Set your C compiler by CC environment variable. Example: export CC=gcc"
fi

