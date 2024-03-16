
if [ "$1" == "-lib" ]; then
# Create Static Lib
cc -c src/tmatrix.cpp -Iinclude      -o debug/tmatrix.o && \
cc -c src/tlist.cpp   -Iinclude      -o debug/tlist.o && \
ar rcs terra.a debug/*

else
# Compile all files
cc -o terra -Wextra -Wall -pedantic -g -Iinclude \
   src/tmatrix.cpp \
   src/tlist.cpp \
   src/main.cpp
fi
