CC := g++
CFLAGS := -Wall -Wextra -std=c++11

EXECUTABLE := main

.PHONY: all clean uninstall reinstall

all:
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./*.cpp
	mv ./*.o ./obj
	$(CC) $(CFLAGS) -o $(EXECUTABLE) ./obj/*.o

uninstall:
	rm -rf ./obj
	rm -rf $(EXECUTABLE)

clean:
	rm -rf ./obj

reinstall: uninstall all
