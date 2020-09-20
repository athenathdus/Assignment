#include<GL/glut.h>
#include<math.h>

//GL_QUADS


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);  //GL_QUADS �� �׸���.

    glColor3f(1.0, 0.0, 0.0); // �� ����
	glVertex3f(1.0, 0.0, 0.0); // v0
	glVertex3f(-1.0, 0.0, 0.0); // v1
	glVertex3f(-0.0, 1.0, 1.0); // v2
	glVertex3f(1.0, 1.0,1.0); // v5
   
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
	glutCreateWindow("GL_QUADS");  //�����츦 GL_QUADS�̸����� ����Ѵ�.

	RegisterCallback();
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.

	return 0;
}