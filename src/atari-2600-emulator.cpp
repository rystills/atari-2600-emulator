#include <string>
#include <iostream>
#include "tinydir/tinydir.h"
#include <stdio.h>

/* @param fileDir - the directory in which to list files
   @effects list the files in the input directory
*/
void listFiles(char* fileDir) {
	//init tinydir directory to fileDir
	tinydir_dir dir;
	tinydir_open(&dir, fileDir);

	//iterate over all files in dir
	while (dir.has_next) {
		tinydir_file file;
		tinydir_readfile(&dir, &file);

		//print file name, followed by a '/' if the file is a directory
		printf("%s", file.name);
		if (file.is_dir)
		{
			printf("/");
		}
		printf("\n");

		//proceed to the next file
		tinydir_next(&dir);
	}

	//close dir once we're finished reading files
	tinydir_close(&dir);
}

int main() {
	//hard-code romName for testing
	std::string romName = "ADVNTURE.BIN";
	listFiles("./roms");
	std::cin.get();
}