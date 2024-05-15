EXECUTABLE := main

.PHONY: clean

all:
	mkdir ./obj
	gcc  -c ./*.c
	mv ./*.o ./obj
	gcc  -o $(EXECUTABLE) ./obj/*.o

uninstall:
	rm -rf ./obj
	rm -rf $(EXECUTABLE)

clean:
	rm -rf ./obj

reinstall: uninstall all
