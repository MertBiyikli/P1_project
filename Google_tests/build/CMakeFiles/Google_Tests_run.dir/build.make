# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build

# Include any dependencies generated for this target.
include CMakeFiles/Google_Tests_run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Google_Tests_run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Google_Tests_run.dir/flags.make

CMakeFiles/Google_Tests_run.dir/test_main.o: CMakeFiles/Google_Tests_run.dir/flags.make
CMakeFiles/Google_Tests_run.dir/test_main.o: /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/test_main.cpp
CMakeFiles/Google_Tests_run.dir/test_main.o: CMakeFiles/Google_Tests_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Google_Tests_run.dir/test_main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_Tests_run.dir/test_main.o -MF CMakeFiles/Google_Tests_run.dir/test_main.o.d -o CMakeFiles/Google_Tests_run.dir/test_main.o -c /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/test_main.cpp

CMakeFiles/Google_Tests_run.dir/test_main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/test_main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/test_main.cpp > CMakeFiles/Google_Tests_run.dir/test_main.i

CMakeFiles/Google_Tests_run.dir/test_main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/test_main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/test_main.cpp -o CMakeFiles/Google_Tests_run.dir/test_main.s

CMakeFiles/Google_Tests_run.dir/Mockup.o: CMakeFiles/Google_Tests_run.dir/flags.make
CMakeFiles/Google_Tests_run.dir/Mockup.o: /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/Mockup.cpp
CMakeFiles/Google_Tests_run.dir/Mockup.o: CMakeFiles/Google_Tests_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Google_Tests_run.dir/Mockup.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Google_Tests_run.dir/Mockup.o -MF CMakeFiles/Google_Tests_run.dir/Mockup.o.d -o CMakeFiles/Google_Tests_run.dir/Mockup.o -c /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/Mockup.cpp

CMakeFiles/Google_Tests_run.dir/Mockup.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/Mockup.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/Mockup.cpp > CMakeFiles/Google_Tests_run.dir/Mockup.i

CMakeFiles/Google_Tests_run.dir/Mockup.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/Mockup.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/Mockup.cpp -o CMakeFiles/Google_Tests_run.dir/Mockup.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/test_main.o" \
"CMakeFiles/Google_Tests_run.dir/Mockup.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

Google_Tests_run: CMakeFiles/Google_Tests_run.dir/test_main.o
Google_Tests_run: CMakeFiles/Google_Tests_run.dir/Mockup.o
Google_Tests_run: CMakeFiles/Google_Tests_run.dir/build.make
Google_Tests_run: CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Google_Tests_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Google_Tests_run.dir/build: Google_Tests_run
.PHONY : CMakeFiles/Google_Tests_run.dir/build

CMakeFiles/Google_Tests_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Google_Tests_run.dir/clean

CMakeFiles/Google_Tests_run.dir/depend:
	cd /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build /Users/halilibrahim/Desktop/SS2024/ASE/GraphMicroservice/Google_tests/build/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Google_Tests_run.dir/depend

