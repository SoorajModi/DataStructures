cmake_minimum_required(VERSION 3.10)

# Specify project information
project(DataStructures
        VERSION
        0.80
        DESCRIPTION
        "Data Structures written in C"
        LANGUAGES
        C
        )

# Include header files
include_directories(include)

# Set directory variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PROJECT_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(PROJECT_TEST_DIR ${CMAKE_BINARY_DIR}/test)

# Set library files
set(LINKEDLIST ${PROJECT_SOURCE_DIR}/LinkedListAPI.c ${PROJECT_TEST_DIR}/LinkedListAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)
set(QUEUE ${PROJECT_SOURCE_DIR}/QueueAPI.c ${PROJECT_SOURCE_DIR}/LinkedListAPI.c ${PROJECT_SOURCE_DIR}/QueueAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)
set(STACK ${PROJECT_SOURCE_DIR}/StackAPI.c ${PROJECT_SOURCE_DIR}/LinkedListAPI.c ${PROJECT_TEST_DIR}/StackAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)
set(BINARY_TREE ${PROJECT_SOURCE_DIR}/BinaryTreeAPI.c ${PROJECT_TEST_DIR}/BinaryTreeAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)
set(GRAPH ${PROJECT_SOURCE_DIR}/GraphAPI.c ${PROJECT_TEST_DIR}/GraphAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)
set(HASH_MAP ${PROJECT_SOURCE_DIR}/HashMapAPI.c ${PROJECT_SOURCE_DIR}/LinkedListAPI.c ${PROJECT_TEST_DIR}/HashMapAPITest.c ${PROJECT_TEST_DIR}/DataTypes.c)

# Create executables
add_executable(LinkedList ${LINKEDLIST})
add_executable(Queue ${QUEUE})
add_executable(Stack ${STACK})
add_executable(BinaryTree ${BINARY_TREE})
add_executable(Graph ${GRAPH})
add_executable(HashMap ${HASH_MAP})

# Execute programs
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${LinkedList})
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Queue})
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Stack})
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BinaryTree})
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Graph})
exec_program(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${HashMap})