#!/bin/bash
printf "[%60s] 0\045\r" " "
for ((i=1;i<=10;i++)) {
sleep 0.6
printf "[%60s] $((i*10))\045\r" " "
printf "[%$((i*6))s\r" " " | tr ' ' '#'
}
echo -e "\nDone."


