#!/bin/bash
echo -n "Gretting : "
read name
bash ex1.bash
echo "Today is $(date '+%A, %B %d, %Y')."
echo "With time `date +%H:%M:%S`. How do you feel today."
echo "You can write here and has a visual about today."
while read text 
do
	if [ "$text" != "exit" ]
	then
		echo "$text" >> "newDayFile";
	else
		break
	fi
done
