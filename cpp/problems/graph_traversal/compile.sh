#!/bin/bash

if [ "$CXX" != "" ]; then
	$CXX -std=c++11 -Wall -Wextra -pedantic -O2 -lm -o "${1%".cpp"}.out" $1
else
	echo "Set your C++ compiler by CXX environment variable. Example: export CXX=g++"
fi

