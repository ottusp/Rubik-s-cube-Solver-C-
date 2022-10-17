compile:
	g++ main.cpp -o main

run:
	./main

clear:
	rm -f main

all:
	@make -s compile &&
	@make -s run &&
	@make -s clear