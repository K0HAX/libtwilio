#!/bin/bash

# This file exists because I made libtwilio a shared library and it doesn't get installed.
# Just run this file.

LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH valgrind ./page $1 "$2"
