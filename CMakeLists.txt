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

# Set directory variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PROJECT_SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(PROJECT_TEST_DIR ${CMAKE_BINARY_DIR}/test)

# Set dependency directory variables
set(UNITY_DIR ${CMAKE_BINARY_DIR}/lib/Unity-2.5.2/src)
set(UNITY_MEMORY_DIR ${CMAKE_BINARY_DIR}/lib/Unity-2.5.2/extras/memory/src)

# Include header files
include_directories(${CMAKE_BINARY_DIR}/include)

# Include dependencies
include_directories(${UNITY_DIR})
include_directories(${UNITY_MEMORY_DIR})

# Set library files
set(LINKEDLIST ${PROJECT_SOURCE_DIR}/LinkedListAPI.c
        ${PROJECT_TEST_DIR}/LinkedListAPITest.c
        ${UNITY_DIR}/unity.c
        ${PROJECT_TEST_DIR}/DataTypes.c)
set(QUEUE ${PROJECT_SOURCE_DIR}/QueueAPI.c
        ${PROJECT_SOURCE_DIR}/LinkedListAPI.c
        ${PROJECT_TEST_DIR}/QueueAPITest.c
        ${UNITY_DIR}/unity.c
        ${PROJECT_TEST_DIR}/DataTypes.c)
set(STACK ${PROJECT_SOURCE_DIR}/StackAPI.c
        ${PROJECT_SOURCE_DIR}/LinkedListAPI.c
        ${PROJECT_TEST_DIR}/StackAPITest.c
        ${UNITY_DIR}/unity.c
        ${PROJECT_TEST_DIR}/DataTypes.c)
set(BINARY_TREE ${PROJECT_SOURCE_DIR}/BinaryTreeAPI.c
        ${PROJECT_TEST_DIR}/BinaryTreeAPITest.c
        ${UNITY_DIR}/unity.c
        ${PROJECT_TEST_DIR}/DataTypes.c)
set(GRAPH ${PROJECT_SOURCE_DIR}/GraphAPI.c
        ${PROJECT_TEST_DIR}/GraphAPITest.c
        ${UNITY_DIR}/unity.c
        ${UNITY_MEMORY_DIR}/unity_memory.c
        ${PROJECT_TEST_DIR}/DataTypes.c)
set(HASH_MAP ${PROJECT_SOURCE_DIR}/HashMapAPI.c
        ${PROJECT_SOURCE_DIR}/LinkedListAPI.c
        ${PROJECT_TEST_DIR}/HashMapAPITest.c
        ${UNITY_DIR}/unity.c
        ${PROJECT_TEST_DIR}/DataTypes.c)

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
