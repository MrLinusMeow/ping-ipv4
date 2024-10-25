#!/bin/bash
chmod +xrw build.sh format.sh ping.sh
chmod +rw generate-binary-ipv4-list.c
echo -e "building...\n" && ./build.sh && echo -e "building... done\n"
echo -e "generating 'ipv4-list.hex'...\n" && ./a.out && echo -e "ipv4-list.hex done\n" && echo -e "generating 'ipv4-list.txt'..." && ./format.sh && echo -e "ipv4-list.txt done\n"
