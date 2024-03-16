
project="terra"

red_echo() {
    local text=$1
    echo -e "\e[31m$text\e[0m"
}

green_echo() {
    local text=$1
    echo -e "\e[32m$text\e[0m"
}

if [ "$1" == "-lib" ]; then
    echo "Generating static Library '$project.a'"

    # Check if debug directory exists
    if [ ! -d "./debug" ]; then
        mkdir debug
    fi 

######### Add Source Files #########
    g++ -c src/tmatrix.cpp -Iinclude      -o debug/tmatrix.o && \
    g++ -c src/tlist.cpp   -Iinclude      -o debug/tlist.o && \
    ar rcs $project.a debug/*
###################################

else
    echo "Compiling all files for project '$project'"
######### Add Source Files #########
    g++ -o project -Wextra -Wall -pedantic -g -Iinclude \
        src/main.cpp \
        src/tmatrix.cpp \
        src/tlist.cpp 
###################################

    if [ $? -eq 0 ]; then
        echo -n "Compiling " && green_echo "finished" 
    else
        echo -n "Compiling " && red_echo "failed" 
    fi
fi
