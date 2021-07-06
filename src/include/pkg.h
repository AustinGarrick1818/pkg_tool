#pragma once
#ifndef PKG_H
#define PKG_H

#include <time.h>

#define PKG_MAGIC "\x70\x6b\x67"
#define PKG_VER 0x01
#define PKG_SIG_LEN 3

#define OK 0
#define ERR 1

typedef struct {
   char hdr_sig[5];
   int hdr_ver[5];
   int sig_len[5];
   time_t hdr_mod_time[1024];
} pkg_hdr_t;

typedef struct {
   char pkg_name[20];

   // Effective user ID, and GID
   int UID[8];
   int GID[8];
   int use_compress[2]; // Uses zlib compression

   char pkg_hdr_sha256[130]; // Header checksum
   char pkg_meta_sha256[130]; // Metadata checksum
   char pkg_sha256[130]; // Package contents checksum

   int pkg_num[5]; // Number of package(s)
   size_t pkg_len[5]; // Length of file(s)

   time_t meta_mod_time[1024];
} pkg_meta_t;

typedef struct {
   char data[65536]; // 64kb
   time_t pkg_pak_time[1024];
} pkg_data_t;

int get_uid(); // Effective user ID
int pkg_init(); // Prepare header info
int pkg_pak(char *f, int num_pkg); // Pack function

#endif
