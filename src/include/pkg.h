#ifndef PKG_H
#define PKG_H

#pragma once

#include <time.h>
#include <sys/types.h>

#define MAGIC "\x50\x4b\x47" // PKG in hex
#define VER "0x01"
#define ERR 1

#define MAX_PKG_LEN 65536 // 64kb

struct {
   char hdr_sig[10];
   char hdr_ver[5];
} pkg_hdr_t;

struct {
   char pkg_name[30];
   int pkg_len;
   int pkg_num;
} pkg_meta_t;

struct {
   char data[MAX_PKG_LEN];
   time_t pkg_pak_time;
} pkg_data_t;

int pack(char *f, int f_len);

#endif
