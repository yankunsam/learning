# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sam/eos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/eos/build

# Utility rule file for test_api_multi_index.

# Include the progress variables for this target.
include contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/progress.make

contracts/test_api_multi_index/CMakeFiles/test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.wast.hpp


contracts/test_api_multi_index/test_api_multi_index.wast.hpp: contracts/test_api_multi_index/test_api_multi_index.wast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/eos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_api_multi_index.wast.hpp"
	cd /home/sam/eos/build/contracts/test_api_multi_index && echo "const char* const test_api_multi_index_wast = R\"=====(" > /home/sam/eos/build/contracts/test_api_multi_index/test_api_multi_index.wast.hpp
	cd /home/sam/eos/build/contracts/test_api_multi_index && cat /home/sam/eos/build/contracts/test_api_multi_index/test_api_multi_index.wast >> /home/sam/eos/build/contracts/test_api_multi_index/test_api_multi_index.wast.hpp
	cd /home/sam/eos/build/contracts/test_api_multi_index && echo ")=====\";" >> /home/sam/eos/build/contracts/test_api_multi_index/test_api_multi_index.wast.hpp

contracts/test_api_multi_index/test_api_multi_index.wast: contracts/test_api_multi_index/test_api_multi_index.s
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/eos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating WAST test_api_multi_index.wast"
	cd /home/sam/eos/build/contracts/test_api_multi_index && /home/sam/eos/build/externals/binaryen/bin/eosio-s2wasm -o /home/sam/eos/build/contracts/test_api_multi_index/test_api_multi_index.wast -s 4096 test_api_multi_index.s

contracts/test_api_multi_index/test_api_multi_index.s: contracts/test_api_multi_index/test_api_multi_index.bc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/eos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating textual assembly test_api_multi_index.s"
	cd /home/sam/eos/build/contracts/test_api_multi_index && /home/sam/opt/wasm/bin/llc -thread-model=single -asm-verbose=false -o test_api_multi_index.s test_api_multi_index.bc

contracts/test_api_multi_index/test_api_multi_index.bc: contracts/test_api_multi_index/test_api_multi_index.cpp.bc
contracts/test_api_multi_index/test_api_multi_index.bc: contracts/libc++/libc++.bc
contracts/test_api_multi_index/test_api_multi_index.bc: contracts/musl/libc.bc
contracts/test_api_multi_index/test_api_multi_index.bc: contracts/eosiolib/eosiolib.bc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/eos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking LLVM bitcode executable test_api_multi_index.bc"
	cd /home/sam/eos/build/contracts/test_api_multi_index && /home/sam/opt/wasm/bin/llvm-link -only-needed -o test_api_multi_index.bc test_api_multi_index.cpp.bc /home/sam/eos/build/contracts/libc++/libc++.bc /home/sam/eos/build/contracts/musl/libc.bc /home/sam/eos/build/contracts/eosiolib/eosiolib.bc

contracts/test_api_multi_index/test_api_multi_index.cpp.bc: ../contracts/test_api_multi_index/test_api_multi_index.cpp
contracts/test_api_multi_index/test_api_multi_index.cpp.bc: ../contracts/test_api_multi_index/test_api_multi_index.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sam/eos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building LLVM bitcode test_api_multi_index.cpp.bc"
	cd /home/sam/eos/build/contracts/test_api_multi_index && /home/sam/opt/wasm/bin/clang -emit-llvm -O3 --std=c++14 --target=wasm32 -ffreestanding -nostdlib -nostdlibinc -fno-threadsafe-statics -fno-rtti -fno-exceptions -c /home/sam/eos/contracts/test_api_multi_index/test_api_multi_index.cpp -o test_api_multi_index.cpp.bc -Weverything -Wno-c++98-compat -Wno-old-style-cast -Wno-vla -Wno-vla-extension -Wno-c++98-compat-pedantic -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-packed -Wno-padded -Wno-c99-extensions -Wno-documentation-unknown-command -I /home/sam/eos/contracts -I /home/sam/eos/externals/magic_get/include -isystem /home/sam/eos/contracts/libc++/upstream/include -isystem /home/sam/eos/contracts/musl/upstream/include -isystem /home/sam/opt/boost_1_66_0/include -isystem /home/sam/eos/contracts/libc++/upstream/include -isystem /home/sam/eos/contracts/musl/upstream/include -isystem /home/sam/opt/boost_1_66_0/include

test_api_multi_index: contracts/test_api_multi_index/CMakeFiles/test_api_multi_index
test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.wast.hpp
test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.wast
test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.s
test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.bc
test_api_multi_index: contracts/test_api_multi_index/test_api_multi_index.cpp.bc
test_api_multi_index: contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/build.make

.PHONY : test_api_multi_index

# Rule to build all files generated by this target.
contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/build: test_api_multi_index

.PHONY : contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/build

contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/clean:
	cd /home/sam/eos/build/contracts/test_api_multi_index && $(CMAKE_COMMAND) -P CMakeFiles/test_api_multi_index.dir/cmake_clean.cmake
.PHONY : contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/clean

contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/depend:
	cd /home/sam/eos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/eos /home/sam/eos/contracts/test_api_multi_index /home/sam/eos/build /home/sam/eos/build/contracts/test_api_multi_index /home/sam/eos/build/contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : contracts/test_api_multi_index/CMakeFiles/test_api_multi_index.dir/depend

