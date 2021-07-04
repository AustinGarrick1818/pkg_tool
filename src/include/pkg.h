#pragma once
#ifndef PKG_H
#define PKG_H

#include <time.h>

#define PKG_MAGIC "\x70\x6b\x67"
#define PKG_VER 0x01
#define PKG_SIG_LEN 3


// Supproted file formats
const char pkg_ext[] = {
   ".mp3",
   ".txt",
   ".log",
   ".bin",
   ".elf",
   ".exe",
};

typedef struct {
   char hdr_sig[5];
   int hdr_ver;
   int sig_len;
} pkg_hdr_t;

typedef struct {
   char pkg_name[20];

   char pkg_hdr_sha256[130]; // Header checksum
   char pkg_meta_sha256[130]; // Metadata checksum
   char pkg_sha256[130]; // Package contents checksum

   int pkg_num; // Number of package(s)
   int pkg_len; // Length of file(s)
   time_t pkg_pak_time;

   char pak_time_sha256[130];
} pkg_meta_t;

typedef struct {

}

int pkg_init(pkg_hdr_t *pkg_hdr);
int pkg_meta_init(pkg_meta_t *meta);
int pak_pkg(pkg_pack_t *p, char *f);

int verify_sha256(pkg_meta_t *meta);
int gen_sha256(pkg_meta_t *meta, char *f);

#endif
