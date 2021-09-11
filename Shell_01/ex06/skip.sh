IFS=$'\n'
arr=( $(ls -l) )
cnt=0


for data in ${arr[@]}; do
    if ((${cnt} % 2 == 0)); then
        echo "${data}"
    fi
    cnt=$((${cnt} + 1))
done