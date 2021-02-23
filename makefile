# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/soorajmodi/Code/DataStructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/soorajmodi/Code/DataStructures

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.19.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.19.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/soorajmodi/Code/DataStructures/CMakeFiles /Users/soorajmodi/Code/DataStructures//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/soorajmodi/Code/DataStructures/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named LinkedList

# Build rule for target.
LinkedList: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 LinkedList
.PHONY : LinkedList

# fast build rule for target.
LinkedList/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/build
.PHONY : LinkedList/fast

#=============================================================================
# Target rules for targets named Graph

# Build rule for target.
Graph: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Graph
.PHONY : Graph

# fast build rule for target.
Graph/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/build
.PHONY : Graph/fast

#=============================================================================
# Target rules for targets named HashMap

# Build rule for target.
HashMap: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 HashMap
.PHONY : HashMap

# fast build rule for target.
HashMap/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/build
.PHONY : HashMap/fast

#=============================================================================
# Target rules for targets named BinaryTree

# Build rule for target.
BinaryTree: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 BinaryTree
.PHONY : BinaryTree

# fast build rule for target.
BinaryTree/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/build
.PHONY : BinaryTree/fast

#=============================================================================
# Target rules for targets named Stack

# Build rule for target.
Stack: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Stack
.PHONY : Stack

# fast build rule for target.
Stack/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/build
.PHONY : Stack/fast

#=============================================================================
# Target rules for targets named Queue

# Build rule for target.
Queue: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Queue
.PHONY : Queue

# fast build rule for target.
Queue/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/build
.PHONY : Queue/fast

src/BinaryTreeAPI.o: src/BinaryTreeAPI.c.o

.PHONY : src/BinaryTreeAPI.o

# target to build an object file
src/BinaryTreeAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPI.c.o
.PHONY : src/BinaryTreeAPI.c.o

src/BinaryTreeAPI.i: src/BinaryTreeAPI.c.i

.PHONY : src/BinaryTreeAPI.i

# target to preprocess a source file
src/BinaryTreeAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPI.c.i
.PHONY : src/BinaryTreeAPI.c.i

src/BinaryTreeAPI.s: src/BinaryTreeAPI.c.s

.PHONY : src/BinaryTreeAPI.s

# target to generate assembly for a file
src/BinaryTreeAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPI.c.s
.PHONY : src/BinaryTreeAPI.c.s

src/BinaryTreeAPITest.o: src/BinaryTreeAPITest.c.o

.PHONY : src/BinaryTreeAPITest.o

# target to build an object file
src/BinaryTreeAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPITest.c.o
.PHONY : src/BinaryTreeAPITest.c.o

src/BinaryTreeAPITest.i: src/BinaryTreeAPITest.c.i

.PHONY : src/BinaryTreeAPITest.i

# target to preprocess a source file
src/BinaryTreeAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPITest.c.i
.PHONY : src/BinaryTreeAPITest.c.i

src/BinaryTreeAPITest.s: src/BinaryTreeAPITest.c.s

.PHONY : src/BinaryTreeAPITest.s

# target to generate assembly for a file
src/BinaryTreeAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/BinaryTreeAPITest.c.s
.PHONY : src/BinaryTreeAPITest.c.s

src/DataTypes.o: src/DataTypes.c.o

.PHONY : src/DataTypes.o

# target to build an object file
src/DataTypes.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/DataTypes.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/DataTypes.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/DataTypes.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/DataTypes.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/DataTypes.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/DataTypes.c.o
.PHONY : src/DataTypes.c.o

src/DataTypes.i: src/DataTypes.c.i

.PHONY : src/DataTypes.i

# target to preprocess a source file
src/DataTypes.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/DataTypes.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/DataTypes.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/DataTypes.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/DataTypes.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/DataTypes.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/DataTypes.c.i
.PHONY : src/DataTypes.c.i

src/DataTypes.s: src/DataTypes.c.s

.PHONY : src/DataTypes.s

# target to generate assembly for a file
src/DataTypes.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/DataTypes.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/DataTypes.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/DataTypes.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BinaryTree.dir/build.make CMakeFiles/BinaryTree.dir/src/DataTypes.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/DataTypes.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/DataTypes.c.s
.PHONY : src/DataTypes.c.s

src/GraphAPI.o: src/GraphAPI.c.o

.PHONY : src/GraphAPI.o

# target to build an object file
src/GraphAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPI.c.o
.PHONY : src/GraphAPI.c.o

src/GraphAPI.i: src/GraphAPI.c.i

.PHONY : src/GraphAPI.i

# target to preprocess a source file
src/GraphAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPI.c.i
.PHONY : src/GraphAPI.c.i

src/GraphAPI.s: src/GraphAPI.c.s

.PHONY : src/GraphAPI.s

# target to generate assembly for a file
src/GraphAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPI.c.s
.PHONY : src/GraphAPI.c.s

src/GraphAPITest.o: src/GraphAPITest.c.o

.PHONY : src/GraphAPITest.o

# target to build an object file
src/GraphAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPITest.c.o
.PHONY : src/GraphAPITest.c.o

src/GraphAPITest.i: src/GraphAPITest.c.i

.PHONY : src/GraphAPITest.i

# target to preprocess a source file
src/GraphAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPITest.c.i
.PHONY : src/GraphAPITest.c.i

src/GraphAPITest.s: src/GraphAPITest.c.s

.PHONY : src/GraphAPITest.s

# target to generate assembly for a file
src/GraphAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Graph.dir/build.make CMakeFiles/Graph.dir/src/GraphAPITest.c.s
.PHONY : src/GraphAPITest.c.s

src/HashMapAPI.o: src/HashMapAPI.c.o

.PHONY : src/HashMapAPI.o

# target to build an object file
src/HashMapAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPI.c.o
.PHONY : src/HashMapAPI.c.o

src/HashMapAPI.i: src/HashMapAPI.c.i

.PHONY : src/HashMapAPI.i

# target to preprocess a source file
src/HashMapAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPI.c.i
.PHONY : src/HashMapAPI.c.i

src/HashMapAPI.s: src/HashMapAPI.c.s

.PHONY : src/HashMapAPI.s

# target to generate assembly for a file
src/HashMapAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPI.c.s
.PHONY : src/HashMapAPI.c.s

src/HashMapAPITest.o: src/HashMapAPITest.c.o

.PHONY : src/HashMapAPITest.o

# target to build an object file
src/HashMapAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPITest.c.o
.PHONY : src/HashMapAPITest.c.o

src/HashMapAPITest.i: src/HashMapAPITest.c.i

.PHONY : src/HashMapAPITest.i

# target to preprocess a source file
src/HashMapAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPITest.c.i
.PHONY : src/HashMapAPITest.c.i

src/HashMapAPITest.s: src/HashMapAPITest.c.s

.PHONY : src/HashMapAPITest.s

# target to generate assembly for a file
src/HashMapAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/HashMapAPITest.c.s
.PHONY : src/HashMapAPITest.c.s

src/LinkedListAPI.o: src/LinkedListAPI.c.o

.PHONY : src/LinkedListAPI.o

# target to build an object file
src/LinkedListAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPI.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/LinkedListAPI.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/LinkedListAPI.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/LinkedListAPI.c.o
.PHONY : src/LinkedListAPI.c.o

src/LinkedListAPI.i: src/LinkedListAPI.c.i

.PHONY : src/LinkedListAPI.i

# target to preprocess a source file
src/LinkedListAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPI.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/LinkedListAPI.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/LinkedListAPI.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/LinkedListAPI.c.i
.PHONY : src/LinkedListAPI.c.i

src/LinkedListAPI.s: src/LinkedListAPI.c.s

.PHONY : src/LinkedListAPI.s

# target to generate assembly for a file
src/LinkedListAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPI.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/HashMap.dir/build.make CMakeFiles/HashMap.dir/src/LinkedListAPI.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/LinkedListAPI.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/LinkedListAPI.c.s
.PHONY : src/LinkedListAPI.c.s

src/LinkedListAPITest.o: src/LinkedListAPITest.c.o

.PHONY : src/LinkedListAPITest.o

# target to build an object file
src/LinkedListAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPITest.c.o
.PHONY : src/LinkedListAPITest.c.o

src/LinkedListAPITest.i: src/LinkedListAPITest.c.i

.PHONY : src/LinkedListAPITest.i

# target to preprocess a source file
src/LinkedListAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPITest.c.i
.PHONY : src/LinkedListAPITest.c.i

src/LinkedListAPITest.s: src/LinkedListAPITest.c.s

.PHONY : src/LinkedListAPITest.s

# target to generate assembly for a file
src/LinkedListAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LinkedList.dir/build.make CMakeFiles/LinkedList.dir/src/LinkedListAPITest.c.s
.PHONY : src/LinkedListAPITest.c.s

src/QueueAPI.o: src/QueueAPI.c.o

.PHONY : src/QueueAPI.o

# target to build an object file
src/QueueAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPI.c.o
.PHONY : src/QueueAPI.c.o

src/QueueAPI.i: src/QueueAPI.c.i

.PHONY : src/QueueAPI.i

# target to preprocess a source file
src/QueueAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPI.c.i
.PHONY : src/QueueAPI.c.i

src/QueueAPI.s: src/QueueAPI.c.s

.PHONY : src/QueueAPI.s

# target to generate assembly for a file
src/QueueAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPI.c.s
.PHONY : src/QueueAPI.c.s

src/QueueAPITest.o: src/QueueAPITest.c.o

.PHONY : src/QueueAPITest.o

# target to build an object file
src/QueueAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPITest.c.o
.PHONY : src/QueueAPITest.c.o

src/QueueAPITest.i: src/QueueAPITest.c.i

.PHONY : src/QueueAPITest.i

# target to preprocess a source file
src/QueueAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPITest.c.i
.PHONY : src/QueueAPITest.c.i

src/QueueAPITest.s: src/QueueAPITest.c.s

.PHONY : src/QueueAPITest.s

# target to generate assembly for a file
src/QueueAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Queue.dir/build.make CMakeFiles/Queue.dir/src/QueueAPITest.c.s
.PHONY : src/QueueAPITest.c.s

src/StackAPI.o: src/StackAPI.c.o

.PHONY : src/StackAPI.o

# target to build an object file
src/StackAPI.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPI.c.o
.PHONY : src/StackAPI.c.o

src/StackAPI.i: src/StackAPI.c.i

.PHONY : src/StackAPI.i

# target to preprocess a source file
src/StackAPI.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPI.c.i
.PHONY : src/StackAPI.c.i

src/StackAPI.s: src/StackAPI.c.s

.PHONY : src/StackAPI.s

# target to generate assembly for a file
src/StackAPI.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPI.c.s
.PHONY : src/StackAPI.c.s

src/StackAPITest.o: src/StackAPITest.c.o

.PHONY : src/StackAPITest.o

# target to build an object file
src/StackAPITest.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPITest.c.o
.PHONY : src/StackAPITest.c.o

src/StackAPITest.i: src/StackAPITest.c.i

.PHONY : src/StackAPITest.i

# target to preprocess a source file
src/StackAPITest.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPITest.c.i
.PHONY : src/StackAPITest.c.i

src/StackAPITest.s: src/StackAPITest.c.s

.PHONY : src/StackAPITest.s

# target to generate assembly for a file
src/StackAPITest.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Stack.dir/build.make CMakeFiles/Stack.dir/src/StackAPITest.c.s
.PHONY : src/StackAPITest.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... BinaryTree"
	@echo "... Graph"
	@echo "... HashMap"
	@echo "... LinkedList"
	@echo "... Queue"
	@echo "... Stack"
	@echo "... src/BinaryTreeAPI.o"
	@echo "... src/BinaryTreeAPI.i"
	@echo "... src/BinaryTreeAPI.s"
	@echo "... src/BinaryTreeAPITest.o"
	@echo "... src/BinaryTreeAPITest.i"
	@echo "... src/BinaryTreeAPITest.s"
	@echo "... src/DataTypes.o"
	@echo "... src/DataTypes.i"
	@echo "... src/DataTypes.s"
	@echo "... src/GraphAPI.o"
	@echo "... src/GraphAPI.i"
	@echo "... src/GraphAPI.s"
	@echo "... src/GraphAPITest.o"
	@echo "... src/GraphAPITest.i"
	@echo "... src/GraphAPITest.s"
	@echo "... src/HashMapAPI.o"
	@echo "... src/HashMapAPI.i"
	@echo "... src/HashMapAPI.s"
	@echo "... src/HashMapAPITest.o"
	@echo "... src/HashMapAPITest.i"
	@echo "... src/HashMapAPITest.s"
	@echo "... src/LinkedListAPI.o"
	@echo "... src/LinkedListAPI.i"
	@echo "... src/LinkedListAPI.s"
	@echo "... src/LinkedListAPITest.o"
	@echo "... src/LinkedListAPITest.i"
	@echo "... src/LinkedListAPITest.s"
	@echo "... src/QueueAPI.o"
	@echo "... src/QueueAPI.i"
	@echo "... src/QueueAPI.s"
	@echo "... src/QueueAPITest.o"
	@echo "... src/QueueAPITest.i"
	@echo "... src/QueueAPITest.s"
	@echo "... src/StackAPI.o"
	@echo "... src/StackAPI.i"
	@echo "... src/StackAPI.s"
	@echo "... src/StackAPITest.o"
	@echo "... src/StackAPITest.i"
	@echo "... src/StackAPITest.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

