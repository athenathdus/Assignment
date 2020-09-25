#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο�Quadric ����

//void gluDisk(GLUquadric *qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);

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
	//gluDisk(qobj, 0.0, 2.0, 20, 3);  ����� �����ִ� Disk (�ּ�ó��)
	gluDisk(qobj, 0.5, 2.0, 20, 3);
	glutSwapBuffers();
	glCallList(MyListID); // �������̿Ϸ�ȸ���Ʈ�������ν���
	glFlush();
}
void Reshape(int w, int h) { //������� ũ�Ⱑ ����Ǿ����� ȣ��Ǵ� reshape �ݹ��Լ�
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300); // window â ����� 300,300���� ���� 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Disk");  // â �̸��� Disk ���� 
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	MyCreateList(); // Display List ����
	glutMainLoop();
	return 0;
}