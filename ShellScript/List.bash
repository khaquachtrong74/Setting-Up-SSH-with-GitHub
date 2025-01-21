#!/bin/bash
# make a to do list

menu(){
	echo "============================"
	echo "1. Create a new job to do."
	#echo "2. View all job are have."
	echo "2. Complete one job of list."
	echo "0. Exit program."
}
TODO_FILE="toDoList.txt"
COMPLETE_TASK="completeTask.txt"
touch "$TODO_FILE"

while true
do
	nl "$TODO_FILE"
	menu
	read -p "Chose an option (0-3):" action
	case "$action" in
		1)
			echo "Enter your job you want to create."
			read -p "Enter your job: " job
			if [ -n "$job" ]; then
				echo "$job" >> "$TODO_FILE"
				echo "Task add successfully"
			else
				echo "Task cannot be empty"
			fi
			;;	
		2)
			if [ -s "$TODO_FILE" ]; then
				#echo -e "\nCurrent Task:"
				#nl "$TODO_FILE"
				echo $(date +%A) >> "$COMPLETE_TASK";
				echo $(date +%H:%M:%S) >> "$COMPLETE_TASK";
				read -p "Enter the number of your tak is finished " numb
				if [[ "$numb" =~ ^[0-9]+$ ]]; then
					if [ "$numb" -le "$(wc -l < "$TODO_FILE")" ] && [ "$numb" -gt 0 ]; then
						sed -n "${numb}p" "$TODO_FILE" >> "$COMPLETE_TASK"
						sed -i "${numb}d" "$TODO_FILE"
						echo "Task complete successfully"
					else
						echo "Invalid task number"
					fi
				else
					echo "Please enter a valid number!"
				fi
			else
				echo "No tasks."
			fi
			;;
		0)
			echo "End of program, bye bye!"
			exit 0
			;;
		*)
			echo "Invalid input, please try again."
			;;

	esac
	echo -e "\nPLease enter to continue"
	read
	clear 
done
