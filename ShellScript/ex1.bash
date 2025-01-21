#!/bin/bash
# Print time
time=$(date +%H)
if [ "$time" -gt 5 ] && [ "$time" -lt 12 ]; then
	echo "Good morning."
elif [ "$time" -gt 12 ] && [ "$time" -lt 18]; then
	echo "Good Afternoon"
else
	echo "Good Evening";
fi
