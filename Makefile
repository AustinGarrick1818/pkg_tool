# Autogenerated Makefil; DO NOT MODIFY!
#
# Created by: MasterHugeD
# Script version: v0.0.3-alpha

SRC := pkg.c
OBJ := $(SRC:.c=.o)
MODULE := pkg

CC := /usr/bin/gcc
CC_STRIP := /usr/bin/strip

CFLAGS := -Os -Wall -Wextra -lcrypt

all: $(MODULE)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(MODULE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

strip:
	$(CC_STRIP) --strip-unneeded $(MODULE)
	$(CC_STRIP) --strip-debug $(MODULE)

clean:
	rm -f *.o
	rm -f $(MODULE)
