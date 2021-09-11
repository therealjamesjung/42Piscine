aaa="asdf:*:asd"

aaa="$(echo "$aaa" | sed -e 's/:\*:.*/ /g')"

echo ${aaa}