
#include "MyFunc.h"


int main() {
	//��������
	InitWindow();

	glutMouseFunc(mouseProcess);
	glutDisplayFunc(RenderScene);


	glutMainLoop();

	
	return 0;
}



