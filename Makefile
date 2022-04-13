FLAGS=-Wall -Wextra -pedantic

main: main.c
	mkdir -p build
	$(CC) ${FLAGS} -o build/$@ $^

release: main.c
	mkdir -p build
	$(CC) -o2 ${FLAGS} -o build/$@ $^
