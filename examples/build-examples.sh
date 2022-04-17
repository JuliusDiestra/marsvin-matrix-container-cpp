#!/bin/bash

STRING="Start building all examples"
echo $STRING
# Array of directories
array=($(ls -d */))

# Loop
for i in ${array[@]}
do
    cd $i
    bash build-code.sh
    cd ..
done

