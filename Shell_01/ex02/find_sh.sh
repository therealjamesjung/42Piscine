RES=$(find . -type f -name "*.sh" -exec basename {} \;)
RES=$(echo ${RES} | sed -e "s/[.]sh /\\\n/g")

echo ${RES}"\n" | cat -e