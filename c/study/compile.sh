#!/bin/bash

CC=gcc

$CC -std=c99 -Wall -Wextra -pedantic-errors -O2 -lm $@

