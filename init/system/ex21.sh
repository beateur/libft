cat /etc/passwd | awk -F ':' '$3 >= 1000 && $3 < 65534 {print $1 " " $3 " " $6}'
