#include "pkg.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <crypt.h>
#include <sys/types.h>


pkg_hdr_t hdr[15];
pkg_meta_t meta[1024];
pkg_data_t pkg_data[655360];



int pkg_init() {
   // Initalize header information
   strcpy(hdr->hdr_sig, PKG_MAGIC);
   hdr->hdr_ver = PKG_VER;
   hdr->sig_len = PKG_SIG_LEN;
   hdr->hdr_mod_time = time(NULL);
}

int pkg_pak(char *f, int num_pkg) {
   int i;
   char tmp[655360];
   FILE *fp[num_pkg];
   FILE *pkg = fopen("new.pkg", "wb");

   for (i = f; i < num_pkg; i++) {
      fp[i] = fopen(i+1, "rb");

      if (fp[i] == NULL) {
         printf("fopen() failed on: %d\n", i);
         return -1;
      }

      strcpy(meta->pkg_name, f);
      meta->pkg_num = num_pkg;

      while(fgets(tmp, strlen(f), fp)) {
         // I don't even know what the fuck to do
      }
   }
}
