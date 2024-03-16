
project="terra"

red_echo() {
    local text=$1
    echo -e "\e[31m$text\e[0m"
}

green_echo() {
    local text=$1
    echo -e "\e[32m$text\e[0m"
}

yellow_echo() {
    local text=$1
    echo -e "\e[33m$text\e[0m"
}

########## Compiling Static Library ##########
if [ "$1" == "-lib" ]; then
    echo -n "Generating static Library "
    yellow_echo "$project.a"

    # Check if debug directory exists
    if [ ! -d "./debug" ]; then
        mkdir debug
    fi 
#############################################

######### Add Source Files #########
    g++ -c src/tmatrix.cpp -Iinclude      -o debug/tmatrix.o && \
    g++ -c src/tlist.cpp   -Iinclude      -o debug/tlist.o && \
    g++ -c src/tlog.cpp   -Iinclude      -o debug/tlog.o && \
    ar rcs $project.a debug/*
###################################
    error_code=$?

    echo -n "Compiled library "
    if [ $error_code -eq 0 ]; then
        green_echo "successfully"
    else
        red_echo "failed"
    fi


########## Compiling Binary ##########
else 
    echo -n "Compiling all files for project "
    yellow_echo "$project"
######### Add Source Files #########
    g++ -o $project -Wextra -Wall -pedantic -g -Iinclude \
        src/main.cpp \
        src/tmatrix.cpp \
        src/tlog.cpp \
        src/tlist.cpp 
###################################
    error_code=$?
    echo -n "Compiling "
    if [ $error_code -eq 0 ]; then
        green_echo "finished" 
    else
        red_echo "failed" 
    fi
fi
