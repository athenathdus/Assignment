#include<GL/glut.h>
#include<math.h>

//linestrip
void MyDisplay()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);  // 색 지정
	glBegin(GL_LINESTRIP);  //GL_LINESTRIP 을 그린다.

	glVertex2f(-0.5, 0.5);  //v1
	glVertex2f(0.0, 0.0);  //v2
	glVertex2f(0.5, 0.0);  //v3
	glVertex2f(1.0, 0.5);  //v4
	glVertex2f(0.5, 1.0);  //v5
	glVertex2f(0.0, 1.0);  //v6

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
	glutInitWindowSize(500, 500);  //창의 크기를 지정한다.
	glutCreateWindow("linestrip");   //윈도우를 linestrip 이름으로 출력한다.

	RegisterCallback();
	glutMainLoop();  //GLUT 처리 루트로 진입한다.

	return 0;
}