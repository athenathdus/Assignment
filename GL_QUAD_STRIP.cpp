#include<GL/glut.h>
#include<math.h>

//GL_QUAD_STRIP


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUAD_STRIP);  //GL_QUAD_STRIP 를 그린다.

	glVertex3f(-0.7, 0.0, 0.0); // v0
	glVertex3f(-0.7, 0.4, 0.0); // v1
	glVertex3f(-0.2, -0.2, 0.0); // v2

	glColor3f(1.0, 0.0, 0.0); // 색 지정

	glVertex3f(-0.2, 0.5, 0.0); // v3
	glVertex3f(0.2, -0.1, 0.0); // v4


	glColor3f(0.0, 1.0, 0.0); // 색 지정

	glVertex3f(0.3, 0.5, 0.0); // v5
	glVertex3f(0.6, -0.2, 0.0); // v6


	glColor3f(0.0, 0.0, 1.0); // 색 지정

	glVertex3f(0.7, 0.3, 0.0);//v7

	glEnd();
	glFlush();  // 화면에 출력한다.

}



void Mykeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':exit(0);
	}
}

void RegisterCallback()
{
	glutDisplayFunc(MyDisplay);  //MyDIsplay를 출력한다.
	glutKeyboardFunc(Mykeyboard);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);  //창의 크기를 지정한다.
	glutCreateWindow("GL_QUAD_STRIP");  //윈도우를 GL_QUAD_STRIP이름으로 출력한다.

	RegisterCallback();
	glutMainLoop();  //GLUT 처리 루트로 진입한다.

	return 0;
}