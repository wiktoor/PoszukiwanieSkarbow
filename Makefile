CC = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++20 -DTEST_NUM=301

hunt_test: hunt_test.o
hunt_test.o: hunt_test.cc treasure_hunt.h treasure.h member.h

test: test.o
test.o: test.cc treasure_hunt.h treasure.h member.h

clean:
	rm -f *.o hunt_test test