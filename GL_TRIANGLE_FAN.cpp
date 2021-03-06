#include<GL/glut.h>
#include<math.h>

//GL_TRIANGLE_FAN


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);  //GL_TRIANGLE_FAN 를 그린다.

	glVertex3f(0.0, -0.5, 0.0); // v0
	glVertex3f(-0.6, -0.3, 0.0); // v1

	glColor3f(1.0, 0.0, 0.0); // 색 지정

	glVertex3f(-0.4, 0.0, 0.0); // v2

	glColor3f(0.0, 1.0, 0.0); // 색 지정

	glVertex3f(0.3, 0.3, 0.0); // v3

	glColor3f(0.0, 0.0, 1.0); // 색 지정

	glVertex3f(0.6, 0.0, 0.0); // v4

	glColor3f(0.0, 0.0, 0.5); // 색 지정

	glVertex3f(0.8, -0.3, 0.0); // v5

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
	glutCreateWindow("GL_TRIANGLE_FAN");  //윈도우를 GL_TRIANGLE_FAN이름으로 출력한다.

	RegisterCallback();
	glutMainLoop();  //GLUT 처리 루트로 진입한다.

	return 0;
}