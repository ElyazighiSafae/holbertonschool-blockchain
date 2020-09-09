# Crypto functions for Blockchain project

CC = gcc
# CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3 -ftrapv -Wconversion -Wunreachable-code --std=gnu90
LIBS = -I. -lssl -lcrypto
TASK0 = sha256
TASK1 = ec_create
TASK2 = ec_to_pub
# TASK2 = 2-nary_tree_traverse
# TASK3 = 3-nary_tree_diameter
# TASK4 = 4-path_exists

# $(TASK4): $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c  4-main.c
# 	$(CC) $(CFLAGS) -o $@  $^

# $(TASK3): $(TASK3).c $(TASK1).c $(TASK0).c 3-main.c
# 	$(CC) $(CFLAGS) -o $@  $^

# $(TASK2): $(TASK2).c $(TASK1).c $(TASK0).c  2-main.c
# 	$(CC) $(CFLAGS) -o $@  $^

$(TASK2): $(TASK2).c test/$(TASK2)-main.c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) $(LIBS) -o $@  $^

$(TASK1): $(TASK1).c test/$(TASK1)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) $(LIBS) -o $@  $^

$(TASK0): $(TASK0).c test/$(TASK0)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) $(LIBS) -o $@  $^

.PHONY: clean, check, run

clean:
	rm $(TASK0) $(TASK1) $(TASK2) $(TASK3) $(TASK4)

run: $(TASK1)
	@valgrind --leak-check=full ./$^

check:
	betty *.c *.h
