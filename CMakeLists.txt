cmake_minimum_required(VERSION 3.10)
project(TextualFormulas)
include_directories(include)

add_executable(
    TextualFormulas 
    src/blkBeside.cpp
    src/blkBlock.cpp
    src/blkDebug.cpp
    src/blkMoveRef.cpp
    src/blkOperators.cpp
    src/blkOver.cpp
    src/blkText.cpp
    src/main.cpp
)
