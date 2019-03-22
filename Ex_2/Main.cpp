
#include "MyFunc.h"


int main() {
	//´´½¨´°¿Ú
	InitWindow();

	glutMouseFunc(mouseProcess);
	glutDisplayFunc(RenderScene);


	glutMainLoop();

	
	return 0;
}



