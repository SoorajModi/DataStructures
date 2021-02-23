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

# Import library files
#file(GLOB SOURCES "temp/*.c")
set(LINKEDLIST src/LinkedListAPI.c src/LinkedListAPITest.c src/DataTypes.c)
set(QUEUE src/QueueAPI.c src/LinkedListAPI.c src/QueueAPITest.c src/DataTypes.c)
set(STACK src/StackAPI.c src/LinkedListAPI.c src/StackAPITest.c src/DataTypes.c)
set(BINARY_TREE src/BinaryTreeAPI.c src/BinaryTreeAPITest.c src/DataTypes.c)
set(GRAPH src/GraphAPI.c src/GraphAPITest.c src/DataTypes.c)
set(HASH_MAP src/HashMapAPI.c src/LinkedListAPI.c src/HashMapAPITest.c src/DataTypes.c)

add_executable(LinkedList ${LINKEDLIST})
add_executable(Queue ${QUEUE})
add_executable(Stack ${STACK})
add_executable(BinaryTree ${BINARY_TREE})
add_executable(Graph ${GRAPH})
add_executable(HashMap ${HASH_MAP})

exec_program(LinkedList)
exec_program(Queue)
exec_program(Stack)
exec_program(BinaryTree)
exec_program(Graph)
exec_program(HashMap)