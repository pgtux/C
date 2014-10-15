#!/bin/bash

echo "File list:"
ls
echo "Present working directory:"
pwd

if [ $? -eq 0 ] ; then
	echo "Last executed command is sucessful"

else
	echo "Command failed"
fi

echo "Printing system info:"
uname -a

echo "!! This way automate your routine work !!"


echo "Bye bye"
