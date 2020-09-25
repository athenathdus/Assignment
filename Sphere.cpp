#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο�Quadric ����

int MyListID;//DisplayList������ID�����ؽĺ�
// Display List ����
void MyCreateList() {
	MyListID = glGenLists(1);// DisplayList����
	// ���̵� ���� ����Ʈ1���� ���θ����,�������� �ʰ� ������ �Ϸ�� ������ �����.
	glNewList(MyListID, GL_COMPILE);
	glShadeModel(GL_SMOOTH);// �������� ���� ������ �����Ͽ� ȥ���Ͽ� ĥ�ϰ� ����
	gluQuadricDrawStyle(qobj, GLU_FILL);// Quadric�� ���� ���ϴ�Draw Style ����
	gluQuadricNormals(qobj, GLU_SMOOTH);// ������������
	gluQuadricOrientation(qobj, GLU_OUTSIDE);// �������ͳ��� �� �ܺε�� ������������
	gluQuadricTexture(qobj, GL_FALSE);// Texture ��ǥ ����Ұ����������� ����
	glEnd();
	glEndList();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };//�ֺ���
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//�ݻ籤
	GLfloat mat_shininess[] = { 50.0 };//����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//������ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);

	gluSphere(qobj, 0.8, 50, 50);// Sphere ����
	glutSwapBuffers();
	glCallList(MyListID); // �������̿Ϸ�ȸ���Ʈ�������ν���
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300); // window â ����� 300,300���� ���� 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sphere");  // â �̸��� Sphere�� ���� 
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	MyCreateList(); // Display List ����
	glutMainLoop();
	return 0;
}