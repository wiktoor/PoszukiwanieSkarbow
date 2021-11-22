CC = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++20

test: test.o
test.o: test.cc treasure.h

clean:
	rm -f *.o test