#!/bin/bash

array=( 1 2 3 4 )

for i in "${array[@]}"
do 
	for j in "${array[@]}"
	do
		product=$(($i * $j))
		printf "$i*$j=$product\n"
	done
done		
