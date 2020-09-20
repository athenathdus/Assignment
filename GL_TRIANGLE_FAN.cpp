#include<GL/glut.h>
#include<math.h>

//GL_TRIANGLE_FAN


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);  //GL_TRIANGLE_FAN �� �׸���.

	glVertex3f(0.0, -0.5, 0.0); // v0
	glVertex3f(-0.6, -0.3, 0.0); // v1

	glColor3f(1.0, 0.0, 0.0); // �� ����

	glVertex3f(-0.4, 0.0, 0.0); // v2

	glColor3f(0.0, 1.0, 0.0); // �� ����

	glVertex3f(0.3, 0.3, 0.0); // v3

	glColor3f(0.0, 0.0, 1.0); // �� ����

	glVertex3f(0.6, 0.0, 0.0); // v4

	glColor3f(0.0, 0.0, 0.5); // �� ����

	glVertex3f(0.8, -0.3, 0.0); // v5

	glEnd();
	glFlush();  // ȭ�鿡 ����Ѵ�.

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
	glutCreateWindow("GL_TRIANGLE_FAN");  //�����츦 GL_TRIANGLE_FAN�̸����� ����Ѵ�.

	RegisterCallback();
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.

	return 0;
}