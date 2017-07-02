#include <string>
#include <iostream>
#include "tinydir/tinydir.h"
#include <stdio.h>

#include "glew\glew.h"
#include "freeglut\freeglut.h"

void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);

	glutSwapBuffers();
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << " GLEW Version is 4.5\n ";
	}
	else
	{
		std::cout << "GLEW 4.5 not supported\n ";
	}

	glEnable(GL_DEPTH_TEST);
	// register callbacks
	glutDisplayFunc(renderScene);

	glutMainLoop();

	return 0;
}

/* @param filedir - the directory in which to list files
   @effects list the files in the input directory
*/
//void listfiles(char* filedir) {
//	//init tinydir directory to filedir
//	tinydir_dir dir;
//	tinydir_open(&dir, filedir);
//
//	//iterate over all files in dir
//	while (dir.has_next) {
//		tinydir_file file;
//		tinydir_readfile(&dir, &file);
//
//		//print file name, followed by a '/' if the file is a directory
//		printf("%s", file.name);
//		if (file.is_dir)
//		{
//			printf("/");
//		}
//		printf("\n");
//
//		//proceed to the next file
//		tinydir_next(&dir);
//	}
//
//	//close dir once we're finished reading files
//	tinydir_close(&dir);
//}
//
//int main() {
//	//hard-code romname for testing
//	std::string romname = "advnture.bin";
//	listfiles("./roms");
//	std::cin.get();
//}