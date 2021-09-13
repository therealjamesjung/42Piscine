RES=$(cat /etc/passwd | grep -v "#" | awk 'NR%2==0' | sed -e "s/:\*:.*//g" | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p")
RES=$(echo ${RES} | sed -e "s/ /, /g")
echo ${RES}"." | tr -d '$\n'