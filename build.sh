make


if [ $? -eq 0 ]
then
	make unix_install
fi

#valgrind -s  --leak-check=full <program>
