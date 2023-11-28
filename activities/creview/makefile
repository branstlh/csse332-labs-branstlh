all:
	@echo "This is a dumb makefile, please specify which target you want to build"
	@echo "Byebye..."

.PHONY: all clean

extract_num_str: extract_num_str.c
	gcc -ggdb -Wall -Werror -o $@ $^

num_seq: num_seq.c
	gcc -ggdb -Wall -Werror -o $@ $^

str_find_next: str_find_next.c
	gcc -ggdb -Wall -Werror -o $@ $^

get_first_byte: get_first_byte.c
	gcc -ggdb -Wall -Werror -o $@ $^

clean:
	rm -rf *.o extract_num_str str_find_next num_seq get_first_byte

