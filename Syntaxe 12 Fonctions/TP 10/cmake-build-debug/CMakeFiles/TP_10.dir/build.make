# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TP_10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TP_10.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TP_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP_10.dir/flags.make

CMakeFiles/TP_10.dir/main.c.obj: CMakeFiles/TP_10.dir/flags.make
CMakeFiles/TP_10.dir/main.c.obj: C:/Users/user/CLionProjects/Entrainement-au-C/Entrainement-au-C/Syntaxe\ 12\ Fonctions/TP\ 10/main.c
CMakeFiles/TP_10.dir/main.c.obj: CMakeFiles/TP_10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP_10.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TP_10.dir/main.c.obj -MF CMakeFiles\TP_10.dir\main.c.obj.d -o CMakeFiles\TP_10.dir\main.c.obj -c "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\main.c"

CMakeFiles/TP_10.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP_10.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\main.c" > CMakeFiles\TP_10.dir\main.c.i

CMakeFiles/TP_10.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP_10.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\main.c" -o CMakeFiles\TP_10.dir\main.c.s

# Object files for target TP_10
TP_10_OBJECTS = \
"CMakeFiles/TP_10.dir/main.c.obj"

# External object files for target TP_10
TP_10_EXTERNAL_OBJECTS =

TP_10.exe: CMakeFiles/TP_10.dir/main.c.obj
TP_10.exe: CMakeFiles/TP_10.dir/build.make
TP_10.exe: CMakeFiles/TP_10.dir/linklibs.rsp
TP_10.exe: CMakeFiles/TP_10.dir/objects1.rsp
TP_10.exe: CMakeFiles/TP_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TP_10.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP_10.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP_10.dir/build: TP_10.exe
.PHONY : CMakeFiles/TP_10.dir/build

CMakeFiles/TP_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP_10.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP_10.dir/clean

CMakeFiles/TP_10.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10" "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10" "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug" "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug" "C:\Users\user\CLionProjects\Entrainement-au-C\Entrainement-au-C\Syntaxe 12 Fonctions\TP 10\cmake-build-debug\CMakeFiles\TP_10.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TP_10.dir/depend
