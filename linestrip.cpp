#include<GL/glut.h>
#include<math.h>

//linestrip
void MyDisplay()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);  // �� ����
	glBegin(GL_LINESTRIP);  //GL_LINESTRIP �� �׸���.

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
	glutDisplayFunc(MyDisplay);  //MyDIsplay�� ����Ѵ�.
	glutKeyboardFunc(Mykeyboard);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);  //â�� ũ�⸦ �����Ѵ�.
	glutCreateWindow("linestrip");   //�����츦 linestrip �̸����� ����Ѵ�.

	RegisterCallback();
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.

	return 0;
}