#!/bin/bash
if [ -z $1 ]; then
echo "usage: " $0 "<directory>"
exit
fi

num_dirs=0
num_files=0
for entry in "$search_dir"$1/*
do
	if [ -d $entry ] 
	then
	  	((num_dirs = num_dirs + 1))
	elif [ -f $entry ] 
	then
		((num_files = num_files + 1))
	fi
done

echo "total number of directories:" $num_dirs
echo "total number of files:" $num_files

alias testsearch='./testSearch.sh' 
