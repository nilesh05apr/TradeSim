# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nilesh/projects/TradeSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nilesh/projects/TradeSim/build

# Include any dependencies generated for this target.
include CMakeFiles/TradeSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TradeSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TradeSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TradeSim.dir/flags.make

CMakeFiles/TradeSim.dir/main.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/main.cpp.o: ../main.cpp
CMakeFiles/TradeSim.dir/main.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TradeSim.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/main.cpp.o -MF CMakeFiles/TradeSim.dir/main.cpp.o.d -o CMakeFiles/TradeSim.dir/main.cpp.o -c /home/nilesh/projects/TradeSim/main.cpp

CMakeFiles/TradeSim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/main.cpp > CMakeFiles/TradeSim.dir/main.cpp.i

CMakeFiles/TradeSim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/main.cpp -o CMakeFiles/TradeSim.dir/main.cpp.s

CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o: ../Utils/Utils.cpp
CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o -MF CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o.d -o CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o -c /home/nilesh/projects/TradeSim/Utils/Utils.cpp

CMakeFiles/TradeSim.dir/Utils/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/Utils/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/Utils/Utils.cpp > CMakeFiles/TradeSim.dir/Utils/Utils.cpp.i

CMakeFiles/TradeSim.dir/Utils/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/Utils/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/Utils/Utils.cpp -o CMakeFiles/TradeSim.dir/Utils/Utils.cpp.s

CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o: ../OrderBook/OrderBook.cpp
CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o -MF CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o.d -o CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o -c /home/nilesh/projects/TradeSim/OrderBook/OrderBook.cpp

CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/OrderBook/OrderBook.cpp > CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.i

CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/OrderBook/OrderBook.cpp -o CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.s

CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o: ../Exchange/Exchange.cpp
CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o -MF CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o.d -o CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o -c /home/nilesh/projects/TradeSim/Exchange/Exchange.cpp

CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/Exchange/Exchange.cpp > CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.i

CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/Exchange/Exchange.cpp -o CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.s

CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o: ../Stock/Stock.cpp
CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o -MF CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o.d -o CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o -c /home/nilesh/projects/TradeSim/Stock/Stock.cpp

CMakeFiles/TradeSim.dir/Stock/Stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/Stock/Stock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/Stock/Stock.cpp > CMakeFiles/TradeSim.dir/Stock/Stock.cpp.i

CMakeFiles/TradeSim.dir/Stock/Stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/Stock/Stock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/Stock/Stock.cpp -o CMakeFiles/TradeSim.dir/Stock/Stock.cpp.s

CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o: CMakeFiles/TradeSim.dir/flags.make
CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o: ../MatchOrder/MatchOrder.cpp
CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o: CMakeFiles/TradeSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o -MF CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o.d -o CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o -c /home/nilesh/projects/TradeSim/MatchOrder/MatchOrder.cpp

CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nilesh/projects/TradeSim/MatchOrder/MatchOrder.cpp > CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.i

CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nilesh/projects/TradeSim/MatchOrder/MatchOrder.cpp -o CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.s

# Object files for target TradeSim
TradeSim_OBJECTS = \
"CMakeFiles/TradeSim.dir/main.cpp.o" \
"CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o" \
"CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o" \
"CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o" \
"CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o" \
"CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o"

# External object files for target TradeSim
TradeSim_EXTERNAL_OBJECTS =

TradeSim: CMakeFiles/TradeSim.dir/main.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/Utils/Utils.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/OrderBook/OrderBook.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/Exchange/Exchange.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/Stock/Stock.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/MatchOrder/MatchOrder.cpp.o
TradeSim: CMakeFiles/TradeSim.dir/build.make
TradeSim: CMakeFiles/TradeSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nilesh/projects/TradeSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TradeSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TradeSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TradeSim.dir/build: TradeSim
.PHONY : CMakeFiles/TradeSim.dir/build

CMakeFiles/TradeSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TradeSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TradeSim.dir/clean

CMakeFiles/TradeSim.dir/depend:
	cd /home/nilesh/projects/TradeSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nilesh/projects/TradeSim /home/nilesh/projects/TradeSim /home/nilesh/projects/TradeSim/build /home/nilesh/projects/TradeSim/build /home/nilesh/projects/TradeSim/build/CMakeFiles/TradeSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TradeSim.dir/depend

