all: glue illusionist referee

.PHONY: all clean

glue:
	gcc -o glue glue.c

illusionist:
	gcc -o illusionist illusionist.c -fno-stack-protector

referee:
	gcc -o referee referee.c

clean:
	rm -rf glue illusionist referee malloc fptrs
