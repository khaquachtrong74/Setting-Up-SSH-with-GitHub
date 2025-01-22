#!/bin/bash
# Đối số cần truyền là đường dẫn đến project cần xoá
if [ $# -lt 1 ]; then
	echo "Usage: $0 <directory_folder_remove>"
	exit 1
fi
PROJECT_DIR="$1"
ROOT_CMAKELISTS="./CMakeLists.txt"
#cat "$ROOT_CMAKELISTS"
if [ -d "$PROJECT_DIR" ]; then
	read -p "Are you sure you want to del this runes '$PROJECT_DIR' ? [y/n]: " CONFIRM
	if [[ "$CONFIRM" =~ ^[Yy]$ ]]; then
		rm -rf "$PROJECT_DIR"
		echo "Project '$PROJECT_DIR' is gone! haha."
	# Để xoá đi dòng sub_directory ở CMakeLists.txt gốc
	# Ta sẽ dùng tới công cụ sed để tìm và xoá 1 cách tự động
		if [ -f "$ROOT_CMAKELISTS" ]; then
			sed -i "/add_subdirectory($PROJECT_DIR)/d" "$ROOT_CMAKELISTS"
		else
			echo "Warning: Root CMakeLists not found"
		fi
	else
		echo "Canceled. You are my hero"
	fi
else
	echo "Error: Project directory does not exists"
	exit 1
fi
