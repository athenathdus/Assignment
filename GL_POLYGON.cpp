#include<GL/glut.h>
#include<math.h>

//polygon

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.4, 0.3);  //�� ����
	glBegin(GL_POLYGON);  //GL_POLYGON �� �׸���.
	glVertex3f(0.0, 1.0, 0.0);  //v1
	glVertex3f(-1.0, 0.5, 0.0);   //v2
	glVertex3f(-1.0, -0.5, 0.0);   //v3
	glVertex3f(0.0, -1.0, 0.0);   //v4
	glVertex3f(1.0, -0.5, 0.0);   //v5
	glVertex3f(1.0, 0.5, 0.0);   //v6
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
	glutCreateWindow("polygon");   //�����츦 polygon �̸����� ����Ѵ�.

	RegisterCallback();
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.

	return 0;
}