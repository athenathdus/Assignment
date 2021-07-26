#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

GLUquadricObj* qobj = gluNewQuadric(); // 새로운Quadric 생성

int MyListID;//DisplayList는정수ID에의해식별
// Display List 생성
void MyCreateList() {
	MyListID = glGenLists(1);// DisplayList선언
	// 아이디를 가진 리스트1개를 새로만들되,실행하지 않고 컴파일 완료된 버전을 만든다.
	glNewList(MyListID, GL_COMPILE);
	glShadeModel(GL_SMOOTH);// 각정점에 정한 색상을 보간하여 혼합하여 칠하게 설정
	gluQuadricDrawStyle(qobj, GLU_FILL);// Quadric을 위해 원하는Draw Style 지정
	gluQuadricNormals(qobj, GLU_SMOOTH);// 법선벡터제어
	gluQuadricOrientation(qobj, GLU_OUTSIDE);// 법선벡터내부 및 외부등과 같은방향지정
	gluQuadricTexture(qobj, GL_FALSE);// Texture 좌표 사용할것인지에대한 여부
	glEnd();
	glEndList();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };//주변광
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };//반사광
	GLfloat mat_shininess[] = { 50.0 };//선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//조명위치
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

	gluCylinder(qobj, 2.0, 0.0, 2.0, 20, 8);
	glutSwapBuffers();
	glCallList(MyListID); // 컴파일이완료된리스트가실제로실행
	glFlush();
}
void Reshape(int w, int h) { //모니터의 크기가 변경되었을때 호출되는 reshape 콜백함수
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
	glutInitWindowSize(300, 300); // window 창 사이즈를 300,300으로 지정 
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cylinder");  // 창 이름을 Cylinder로 지정 
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	MyCreateList(); // Display List 생성
	glutMainLoop();
	return 0;
}
