CC = gcc
CFLAGS = -Wall -g

all: build_dir biblioteca

biblioteca: biblioteca.c biblioteca.h
	$(CC) $(CFLAGS) -shared -o build/biblioteca.so -fPIC biblioteca.c

run: build/biblioteca.so
	python3 main.py

clean:
	rm -rf build

build_dir:
	mkdir -p build