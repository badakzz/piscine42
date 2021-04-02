var=$(ip addr show lo | awk '$1 == "inet" {gsub(/\/.*$/, "", $2); print $2}')
if test -z "$var"
then
	echo "Je suis perdu!"
else
	echo $var | tr ' ' '\n'
fi	