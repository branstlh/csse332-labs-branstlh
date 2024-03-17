program.bin: shell.o program.o
	gcc -o program.bin program.o shell.o
shell.o: shell.c donothing.bin
	gcc -c shell.c
donothing.bin: donothing.c
	gcc -o donothing.bin donothing.c
