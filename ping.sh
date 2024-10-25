#!/bin/bash

#file=$1
file="ipv4-list.txt"

while read -r line
do
	wait $!
	if ping -c 1 $line &> /dev/null
	then
		echo -e "$line \e[92msuccess\e[0m\n" >&1
	else
		echo -e "$line \e[91mtimeout\e[0m\n" >&2
	fi
done < "$file"

