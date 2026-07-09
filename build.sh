#!/bin/sh
set -e

if ! which cmake > /dev/null
then
	echo "cmake could not be found. Please install cmake to build the project."
	exit 1
fi

FLAGS="-DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
for arg in "$@"; do
	case $arg in
		--debug)
			FLAGS="$FLAGS -DCMAKE_BUILD_TYPE=Debug"
			;;
		--release)
			FLAGS="$FLAGS -DCMAKE_BUILD_TYPE=Release"
			;;
		--clean)
			rm -rf build
			exit
			;;
		*)
			echo "Unknown argument: $arg"
			exit 1
			;;
	esac
done

cmake -S . -B build $FLAGS
cmake --build build
ctest --test-dir build --output-on-failure

set +e
