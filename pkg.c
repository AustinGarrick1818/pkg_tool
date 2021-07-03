#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>
#include "pkg.h"
#include <sys/types.h>

// NOTE:
// pkg_file_t is allocated in main.c
//
// Must create a header (.h) file with special data
// and name it pkg_data

int blk_write(int blk, int len, void *mem) {
   FILE *f = fopen("new.pkg", "r+");

   int i;
   for (i = 0; i < len; i++) {
      fseek(f, blk, SEEK_SET);
      fwrite(&mem, i, 1, f);
   }

   fclose(f);
   return 1;
}

int main(int argc, char *argv[]) {
   pkg_file_t* pkg = malloc(sizeof(pkg_file_t*) * MAX_PKG_LEN);
   char *files = argv[1];
   char *name = argv[2];
   int num_pkg = argv[3];
   int len = strlen(files);

   // Setup package metadata
   int len = strlen(pkg_data);
   pkg->meta->pkg_len = len;
   strcpy(pkg->meta->pkg_name, name);
   pkg->meta->pkg_num = num_pkg;

   // Setup package header info
   strcpy(pkg->hdr->hdr_sig, MAGIC);
   strcpy(pkg->hdr->hdr_ver, VER);

   // Copy data
   strcpy(pkg->data, pkg_data);

   // Create new package file
   blk_write(0, sizeof(pkg->hdr), &pkg->hdr);
   blk_write(15, sizeof(pkg->meta), &pkg->meta);

   char salt[] = "$-*-$";
   int encrypted = crypt(pkg->data, pkg->encrypt);
   blk_write(25, sizeof(pkg->encrypt, &pkg->encrypt);

   memset(pkg->meta->data, 0, strlen(pkg->meta->data);
   memset(pkg->hdr->hdr_sig, 0, strlen(pkg->hdr->hdr_sig);
   memset(pkg->hdr->hdr_ver, 0, strlen(pkg->hdr->hdr_ver);
   memset(pkg->meta->pkg_name, 0, strlen(pkg->meta->pkg_name);
   return 0;
}
