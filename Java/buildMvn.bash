#!/bin/bash

buildMvn(){
	if [ $# -lt 3 ]; then 
		echo "Usage: buildMVN <groupId> <artifactId> <package>"
		return 1
	fi
	if ! command -v mvn &>/dev/null; then
		echo "Error: Maven (mvn) is not installed or not in PATH"
		return 1
	fi
	mvn archetype:generate \
		-DgroupId="com.$1" \
		-DartifactId="$2" \
		-Dpackage="com.$1.$3" \
		-DarchetypeArtifactId=maven-archetype-quickstart \
		-DinteractiveMode=false

	if [ $? -eq 0 ];then
		echo "Maven project created successfully!"
	else
		echo "Error: Failed to create Maven project."
		return 1
	fi
}

buildMvn "$1" "$2" "$3"
