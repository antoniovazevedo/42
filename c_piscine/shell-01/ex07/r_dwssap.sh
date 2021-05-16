cat /etc/passwd | grep -E '(.*):\*' -o | awk '0  == NR % 2' | sed "s/:\*//" | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | xargs echo -n
