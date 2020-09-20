#include <GL/glut.h>

void MyDisplay() {
	glClearColor(0.259, 0.259, 0.453, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); // 색 지정
	glBegin(GL_LINES);  //GL_LINES 을 그린다.
	glVertex2f(-1.0, 0.0);  //v1
	glVertex2f(0.0, 0.0);  //v2
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);  //창의 크기를 지정한다.
	glutCreateWindow("lines");   //윈도우를 lines이름으로 출력한다.
	glutDisplayFunc(MyDisplay);  //MyDIsplay를 출력한다.
	glutMainLoop();  //GLUT 처리 루트로 진입한다.
	return 0;
}