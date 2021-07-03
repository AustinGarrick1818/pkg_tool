#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>
#include <time.h>
#include "pkg.h"
#include <sys/types.h>

// NOTE:
// pkg_file_t is allocated in main.c
//
// Must create a header (.h) file with special data
// and name it pkg_data

int blk_write(char *n, int blk, void *mem) {
   FILE *f = fopen(n, "r+");

   fseek(f, blk, SEEK_SET);
   fwrite(&mem, strlen(mem), 1, f);

   fclose(f);
   return 1;
}

int main(int argc, char *argv[]) {
   pkg_file_t* pkg = malloc(sizeof(pkg_file_t*) * MAX_PKG_LEN);
   char *file = argv[1];
   char *name = argv[2];
   int num_pkg = argv[3];
   int len_t = strlen(file);

   // Setup package metadata
   pkg->meta->pkg_len = len_t;
   strcpy(pkg->meta->pkg_name, name);
   pkg->meta->pkg_num = num_pkg;

   // Setup package header info
   strcpy(pkg->hdr->hdr_sig, MAGIC);
   strcpy(pkg->hdr->hdr_ver, VER);

   fseek(file, 0, SEEK_END);
   fread(&pkg->data, len_t, 1, file);

   // Create new package file
   blk_write("new.pkg", 0, &pkg->hdr);
   blk_write("new.pkg", 15, &pkg->meta);

   char salt[] = "$-*-$";
   char *enc_data = crypt(pkg->data, pkg->encrypt);
   pkg->pkg_pak_time = time(NULL);

   blk_write("new.pkg", 25, &pkg->encrypt);
   memset(pkg->data, 0, len_t);

   memset(pkg->encrypt, 0, strlen(pkg->encrypt));
   memset(pkg->data, 0, strlen(pkg->data));
   memset(pkg->hdr->hdr_sig, 0, strlen(pkg->hdr->hdr_sig));
   memset(pkg->hdr->hdr_ver, 0, strlen(pkg->hdr->hdr_ver));
   memset(pkg->meta->pkg_name, 0, strlen(pkg->meta->pkg_name));
   return 0;
}
