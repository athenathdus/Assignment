#include <GL/glut.h>

void MyDisplay() {
	glClearColor(0.259, 0.259, 0.453, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); // �� ����
	glBegin(GL_LINES);  //GL_LINES �� �׸���.
	glVertex2f(-1.0, 0.0);  //v1
	glVertex2f(0.0, 0.0);  //v2
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);  //â�� ũ�⸦ �����Ѵ�.
	glutCreateWindow("lines");   //�����츦 lines�̸����� ����Ѵ�.
	glutDisplayFunc(MyDisplay);  //MyDIsplay�� ����Ѵ�.
	glutMainLoop();  //GLUT ó�� ��Ʈ�� �����Ѵ�.
	return 0;
}