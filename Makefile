LIBS=$(shell pkg-config --libs gtk4)
FLAGS=-Wall -Wextra -pedantic $(shell pkg-config --cflags gtk4)

zygui: main.c main_window.c
	mkdir -p build
	$(CC) ${LIBS} ${FLAGS} $^ -o build/$@