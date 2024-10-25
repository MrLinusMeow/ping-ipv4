#!/bin/bash

#file=$1
file="ipv4-list.hex"

while read -r line;
do
	printf "%0d.%0d.%0d.%0d\n" "$((16#${line:0:2}))" "$((16#${line:2:2}))" "$((16#${line:4:2}))" "$((16#${line:6:2}))" >> ipv4-list.txt
done < "$file"
