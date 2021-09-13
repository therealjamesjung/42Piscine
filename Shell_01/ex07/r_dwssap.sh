IFS=$'\n'
arr=( $(cat /etc/passwd) )
result=()

for data in ${arr[@]}; do
    if [ "${data:0:1}" != "#" ]; then
        trim="$(echo "$data" | sed "s/:\*:.*//g" | rev)"
        result+=(${trim})
    fi
done

sorted=($(sort <<<"${result[*]}"))

flag=0

final_res=""
index=1
for data in ${sorted[@]}; do
    if ((${index} == $FT_LINE1)); then
        flag=1
    fi
    if ((${flag} == 1)); then
        final_res="${data}, "${final_res}
    fi
    if ((${index} == $FT_LINE2)); then
        flag=0
    fi
    index=$((${index}+1))
done

final_res="$(echo "${final_res}" | rev | cut -c3- | rev)""."


echo "${final_res}" | tr -d '$\n' | cat -e

#cat /etc/passwd | sed '/#/d' | sed 's/:.*//' | sed -n '2,$ p' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'