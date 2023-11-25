
CC = gcc

gc_main: src/memory/gc_main.c deps/bdwgc/*.c
	mkdir -p build
	make build_bdwgc
	$(CC) src/memory/gc_main.c build/*.o


build_bdwgc: deps/bdwgc/extra/gc.c
	mkdir -p build
	$(CC) -c deps/bdwgc/extra/gc.c -I deps/bdwgc/include -o build/gc.o