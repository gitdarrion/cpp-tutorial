#!/bin/bash

make product 

array=( 1 2 3 4)

for i in "${array[@]}"	
do
	for j in "${array[@]}"
	do
		./product $i $j
	done
done 	
			
