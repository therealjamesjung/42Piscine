GRP=$(id -p $FT_USER)

GRP=$(echo ${GRP} | sed -e "s/.*groups //"g | sed -e 's/ /,/g')

echo ${GRP} | tr -d '$\n'| cat -e
