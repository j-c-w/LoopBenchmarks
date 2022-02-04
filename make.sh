#!/bin/bash

for file in $(find -name "loop*.c"); do
	echo "Looking at $file"
	gcc $file
done
