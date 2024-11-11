CC=g++
CFLAGS=-Wall -Wextra -pedantic -O3 -Iinclude -std=c++11


all: lib

lib: tstring.o tlist.o thash.o tstringlist.o tfile.o tlog.o tmatrix.o tvector.o
	ar rcs libterra.a *.o

tstring.o: src/tstring.cpp include/tstring.hpp
	$(CC) -c src/tstring.cpp $(CFLAGS) -fPIC -o tstring.o

tlist.o: src/tlist.cpp include/tlist.hpp
	$(CC) -c src/tlist.cpp $(CFLAGS) -fPIC -o tlist.o

thash.o: src/thash.cpp include/thash.hpp
	$(CC) -c src/thash.cpp $(CFLAGS) -fPIC -o thash.o

tstringlist.o: src/tstringlist.cpp include/tstringlist.hpp
	$(CC) -c src/tstringlist.cpp $(CFLAGS) -fPIC -o tstringlist.o

tfile.o: src/tfile.cpp include/tfile.hpp
	$(CC) -c src/tfile.cpp $(CFLAGS) -fPIC -o tfile.o

tlog.o: src/tlog.cpp include/tlog.hpp
	$(CC) -c src/tlog.cpp $(CFLAGS) -fPIC -o tlog.o

tmatrix.o: src/tmatrix.cpp include/tmatrix.hpp
	$(CC) -c src/tmatrix.cpp $(CFLAGS) -fPIC -o tmatrix.o

tvector.o: src/tvector.cpp include/tvector.hpp
	$(CC) -c src/tvector.cpp $(CFLAGS) -fPIC -o tvector.o

test: lib
	$(CC) src/main.cpp $(CFLAGS) -o test libterra.a

clean:
	rm *.o -f
	rm test -f
	rm libterra.a -f
