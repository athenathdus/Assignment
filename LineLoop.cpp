#include<GL/glut.h>
#include<math.h>

//LineLoop

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.4, 0.3);  // 색 지정
	glBegin(GL_LINE_LOOP);  // GL_LINE_LOOP 를 그린다.
	glVertex3f(0.0, 1.0, 0.0);  //v1
	glVertex3f(-1.0, 0.5, 0.0);  //v2
	glVertex3f(-1.0, -0.5, 0.0);  //v3
	glVertex3f(0.0, -1.0, 0.0);  //v4
	glVertex3f(1.0, -0.5, 0.0);  //v5
	glVertex3f(1.0, 0.5, 0.0);  //v6
	glEnd();
	glFlush();

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
	glutInitWindowSize(500, 500);   //창의 크기를 지정한다.
	glutCreateWindow("LINE_LOOP");  //윈도우를LINE_LOOP이름으로 출력한다.

	RegisterCallback();
	glutMainLoop();

	return 0;
}