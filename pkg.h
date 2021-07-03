#ifndef PKG_H
#define PKG_H

#include <time.h>
#include <sys/types.h>

#define MAGIC "\x50\x4b\x47" // PKG in hex
#define VER "0x01"
#define ERR 1

#define MAX_PKG_LEN 65536 // 64kb

typedef struct {
   char hdr_sig[10];
   char hdr_ver[5];
} pkg_hdr_t;

typedef struct {
   char pkg_name[30];
   int pkg_len;
   int pkg_num;
   time_t mod_time;
} pkg_meta_t;

typedef struct {
   pkg_hdr_t hdr[15];
   pkg_meta_t meta[15];

   char data[MAX_PKG_LEN];
   char encrypt[10];
   time_t pkg_pak_time;
} pkg_file_t;


//int blk_write(char *n, int blk);

#endif
