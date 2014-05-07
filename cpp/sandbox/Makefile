#!/usr/bin/pmake
CC = /opt/randh/gcc-4.6.1/bin/g++

CFLAGS = -g
CFLAGS += -std=c++0x
CFLAGS += -Wall 

all:
	$(.PMAKE) prog

prog:
	$(CC) $(CFLAGS) -o dlist dlist.c

clean:
	rm -fv dlist
