# Crypto functions for Blockchain project

CC = gcc
# CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3  -ftrapv -Wconversion -Wunreachable-code --std=gnu90
LIBS = -I. -lssl -lcrypto
TASK0 = sha256
TASK1 = ec_create
TASK2 = ec_to_pub
TASK3 = ec_from_pub
TASK4 = ec_save
TASK5 = ec_load
TASK6 = ec_sign
TASK7 = ec_verify
STATIC_LIB = libhblk_crypto.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJ)
	ar ru $@ $^
	ranlib $@

$(TASK7): $(TASK7).c test/$(TASK7)-main.c $(TASK6).c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK6): $(TASK6).c test/$(TASK6)-main.c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK5): $(TASK5).c test/$(TASK5)-main.c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK4): $(TASK4).c test/$(TASK4)-main.c $(TASK3).c $(TASK2).c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK3): $(TASK3).c test/$(TASK3)-main.c $(TASK2).c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK2): $(TASK2).c test/$(TASK2)-main.c $(TASK1).c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK1): $(TASK1).c test/$(TASK1)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK0): $(TASK0).c test/$(TASK0)-main.c provided/_print_hex_buffer.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

.PHONY: clean, check

clean:
	rm $(OBJ) $(TASK0) $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5) $(TASK6) $(TASK7)

check:
	betty *.c *.h
