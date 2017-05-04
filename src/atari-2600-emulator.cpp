#include <string>
#include <iostream>
#include "tinydir/tinydir.h"
#include <stdio.h>

int main() {
	tinydir_dir dir;
	tinydir_open(&dir, "./roms");
	
	while (dir.has_next) {
	    tinydir_file file;
	    tinydir_readfile(&dir, &file);

	    printf("%s", file.name);
	    if (file.is_dir)
	    {
	        printf("/");
	    }
	    printf("\n");

	    tinydir_next(&dir);
	}
	tinydir_close(&dir);
}