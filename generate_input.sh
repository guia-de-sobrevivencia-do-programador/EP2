#!/bin/bash

NUM_OF_FILES=$((1000 * 8))
FILE_SIZE_IN_KB=1

populate_dir() {
	DIR=$1
	echo Populating $DIR
	for ((I=0; I<${NUM_OF_FILES}; I++))
	do
		FILENAME=${DIR}/$(openssl rand -hex 2)
		dd bs=1K count=${FILE_SIZE_IN_KB} if=/dev/urandom of=${FILENAME} 2>/dev/null
	done
}

populate_dirs() {
	populate_dir $1
	populate_dir $2
}

setup() {
	rm -rf $*
	mkdir $*
}

if [ $# != 3 ]
then
	echo "Usage: $0 <input1> <input2> <output>"
	exit 0
fi

setup $*
populate_dirs $1 $2
echo Done
