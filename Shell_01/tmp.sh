#IFS=$'\n'
arr=( $(cat tmp.txt) )

for data in ${arr[@]}; do
	echo ${data}
done