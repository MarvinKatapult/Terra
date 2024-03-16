
if [ "$1" == "-lib" ]; then
    # Check if debug directory exists
    if [ ! -d "./debug" ]; then
        mkdir debug
    fi 

    # Create Static Lib
    g++ -c src/tmatrix.cpp -Iinclude      -o debug/tmatrix.o && \
    g++ -c src/tlist.cpp   -Iinclude      -o debug/tlist.o && \
    ar rcs terra.a debug/*

else
    # Compile all files
    g++ -o terra -Wextra -Wall -pedantic -g -Iinclude \
       src/tmatrix.cpp \
       src/tlist.cpp \
       src/main.cpp
fi
