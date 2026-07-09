#!/bin/sh
set -e

if ! which cmake ctest > /dev/null; then
	echo "cmake or ctest could not be found. Please install cmake and ctest to build the project." >&2
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
			rm -rf build/ bin/
			exit
			;;
		--no-cmake)
			if [ -z "$CXX" ]; then
				echo "CXX is not set. Please set CXX to your C++ compiler." >&2
				exit 1
			fi
			mkdir -p build/
			$CXX $CFLAGS -o build/blackjack src/*.cpp -I include/
			exit
			;;
		--help)
			echo "Usage: $0 [--debug] [--release] [--clean]"
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
