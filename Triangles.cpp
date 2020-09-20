#include<GL/glut.h>
#include<math.h>

//Triangles

void MyDisplay() {

	glBegin(GL_TRIANGLES);  //GL_TRIANGLES �� �׸���.
	glVertex3f(0.0, -1.0, 0.0);  //v1
	glVertex3f(1.0, -0.5, 0.0);  //v2
	glVertex3f(1.0, 0.5, 0.0);  //v3
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
	glutCreateWindow("Triangles");  //�����츦 Triangles�̸����� ����Ѵ�.

	RegisterCallback();
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.

	return 0;
}

