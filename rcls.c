#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *folder;
        struct dirent *entry;
      int files = 0;
      char fname[40];
  if (argv[1] == NULL) {
    folder = opendir(".");
  } else {
      folder = opendir(argv[1]);
  }
      if(folder == NULL) {
       printf("FATAL ERROR: DIRECTORY DOES NOT EXIST!\n");
    return -1;
      }

      while( (entry=readdir(folder)) ) {
        files++;
        printf("FILE %3d: %s\n", files, entry->d_name);
      }
      closedir(folder);
}
