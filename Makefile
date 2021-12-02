CC = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -fconcepts-diagnostics-depth=3

ok2: ok2.o
ok2.o: ok2.cc treasure.h treasure_hunt.h member.h

clean:
	rm -f *.o ok2