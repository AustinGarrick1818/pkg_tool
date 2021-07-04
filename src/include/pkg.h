#pragma once
#ifndef PKG_H
#define PKG_H

#include <time.h>

#define PKG_MAGIC "\x70\x6b\x67"
#define PKG_VER 0x01
#define PKG_SIG_LEN 3


typedef struct {
   char hdr_sig[5];
   int hdr_ver;
   int sig_len;
   time_t hdr_mod_time;
} pkg_hdr_t;

typedef struct {
   char pkg_name[20];

   char pkg_hdr_sha256[130]; // Header checksum
   char pkg_meta_sha256[130]; // Metadata checksum
   char pkg_sha256[130]; // Package contents checksum

   int pkg_num; // Number of package(s)
   int pkg_len; // Length of file(s)

   time_t meta_mod_time
} pkg_meta_t;

typedef struct {
   char data[655360]; // 64kb
   time_t pkg_pak_time;
}

int pkg_init(); // Prepare header info

#endif
