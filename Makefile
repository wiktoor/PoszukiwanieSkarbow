CC = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -fconcepts-diagnostics-depth=3

test: test.o
test.o: test.cc treasure.h treasure_hunt.h member.h

clean:
	rm -f *.o test