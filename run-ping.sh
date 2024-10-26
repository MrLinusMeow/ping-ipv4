#!/bin/bash

for ((a = 0; a < 256; ++a))
do
	for ((b = 0; b < 256; ++b))
	do
		for ((c = 0; c < 256; ++c))
		do
			for ((d = 0; d < 256; ++d))
			do
				wait $!
				if ping -c 1 "$a.$b.$c.$d" &> /dev/null
				then
					echo -e "$a.$b.$c.$d \e[92msuccess\e[0m\n" >&1
				else
					echo -e "$a.$b.$c.$d \e[91mtimeout\e[0m\n" >&2
				fi
			done
		done
	done
done

