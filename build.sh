
project="terra"

if [ "$1" == "-lib" ]; then
    echo "Generating static Library '$project.a'"
    # Check if debug directory exists
    if [ ! -d "./debug" ]; then
        mkdir debug
    fi 

    # Create Static Lib
    g++ -c src/tmatrix.cpp -Iinclude      -o debug/tmatrix.o && \
    g++ -c src/tlist.cpp   -Iinclude      -o debug/tlist.o && \
    ar rcs $project.a debug/*

else
    echo "Compiling all files"
    # Compile all files
    g++ -o $project -Wextra -Wall -pedantic -g -Iinclude \
       src/tmatrix.cpp \
       src/tlist.cpp \
       src/main.cpp
fi
