#!/usr/bin/python3

import sys

file = "Makefile"
auth = "MasterHugeD"
ver = "v0.0.1-alpha"

CC = "/usr/bin/arm-linux-gnueabi-gcc"
CC_STRIP = "/usr/bin/arm-linux-gnueabi-strip"

CFLAGS = "-Os -Wall -Wextra -lcrypt -lz -pthread"

SRC = "pkg.c"
MODULE = "pkg"

with open(file, "w") as fd:
   print("Creating: %s" % file)

   fd.write("# Autogenerated Makefil; DO NOT MODIFY!\n)"
   fd.write("#\n");
   fd.write("# Created by: %s\n" % auth)
   fd.write("# Script version: %s\n\n" % ver)

   fd.write("SRC := %s\n" % SRC)
   fd.write("OBJ := $(SRC:.c=.o)\n")
   fd.write("MODULE := %s\n\n" % MODULE)

   fd.write("CC := %s\n" % CC)
   fd.write("CC_STRIP := %s\n\n" % CC_STRIP)

   fd.write("CFLAGS := %s\n\n" % CFLAGS)
   fd.write("all: MODULE\n\n")

   fd.write("%.o: %.c\n")
   fd.write("\t$(CC) -c -o $@ $< $(CFLAGS)\n\n")


   fd.write("$(MODULE): $(OBJ)\n")
   fd write("\t$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)\n\n")

   fd.write("strip:\n")
   fd.write("\t$(CC_STRIP) --strip-unneeded $(MODULE)\n")
   fd.write("\t$(CC_STRIP) --strip-debug $(MODULE)\n\n")

   fd.write("clean:\n")
   fd.write("\trm -f *.o\n")
   fd.write("\trm -f $(MODULE)\n")
   fd.close()

sys.exit(0)
