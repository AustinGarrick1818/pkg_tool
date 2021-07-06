#include "pkg.h"
#include <time.h>
#include <zconf.h>
#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>


// Keep track of current chunk of data
static int cur_chunk = 0;

static pkg_hdr_t hdr[15];
static pkg_meta_t meta[1024];
static pkg_data_t pkg_data[65536];

int get_uid() {
   int uid = getuid();
   meta->uid[0] = uid;
   meta->gid[0] = uid;
}

int pkg_init() {
   // Initalize header information
   strcpy(hdr->hdr_sig, PKG_MAGIC);
   hdr->hdr_ver[0] = PKG_VER;
   hdr->sig_len[0] = PKG_SIG_LEN;
   hdr->hdr_mod_time[0] = time(NULL);
}

// Open multiole files to be stored in .pkg format
int pkg_pak(char *f, int num_pkg) {
   int i;
   char tmp[65536];
   FILE *fp[num_pkg];
   FILE *pkg = fopen("new.pkg", "wb");

   for (i = f; i < num_pkg; i++) {
      fp[i] = fopen(i+1, "rb");

      if (fp[i] == NULL) {
         printf("fopen() failed on: %d\n", i);
         return -1;
      }

      strcpy(meta->pkg_name, f);
      meta->pkg_num[0] = num_pkg;

      // Write current data
      fseek(pkg, 0, SEEK_SET);
      fwrite(&hdr, sizeof(hdr), strlen(pkg), pkg);

      while(fgets(tmp, strlen(f), fp)) {
         // Write data in chunks
      }
   }
}
