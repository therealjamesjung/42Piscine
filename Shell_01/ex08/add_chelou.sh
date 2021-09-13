N1=$FT_NBR1
N2=$FT_NBR2

N1=$(echo ${N1} | tr "'" '0' | tr '\\"?!' '1234')
N2=$(echo ${N2} | tr 'mrdoc' '01234')

RES=$(echo 'obase=13; ibase=5;' {${N1}+${N2}} | bc)
RES=$(echo ${RES} | tr '0123456789ABC' 'gtaio luSnemf')

echo ${RES}