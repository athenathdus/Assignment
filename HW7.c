/********************************************************************************************************************/
/*             HW#7 : ���� ��������                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 11�� 24 ��                                                     */
/*                                                                                                                                         */
/* ���� ���� : �ڵ� 7-2�� �����Ͽ� 2���̻��� ��ü�� �� ������ �׷ȴ�. �ϳ��� �����츦 4����
* �������� �����Ͽ����� ���� ������ gluPerspective�Լ��� ����Ͽ� ���������Ͽ���, ���ϴ��� ������
* glOrtho �Լ��� ����Ͽ� �������� �Ͽ���. Ű���� �ݹ��� ����Ͽ� glLookup�� ex,ey,ez,px,py,pz����
* ������ �߰��Ͽ� �ùٸ� Ű�� ������ ī�޶��� ��ġ�� �����ϰų� �����ϵ��� �����Ͽ���.
* �������� ���콺 �ݹ��� ����Ͽ� ���̵��� �ҷ�����, ���̵��� ����Ͽ� ���������� ���� �Ǵ� �����ϵ��� �Ͽ���. 
/*                                                                                             */
/*******************************************************************************************************************/
#include <GL/glut.h>

int Width, Height;
float ex, ey, ez, px, py, pz;
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawScene() {
    glColor3f(0.5, 0.5, 1.0);
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, 2.0);
    glEnd();
    glPopMatrix();

    glColor3f(0.1, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.5);
    glutWireTeapot(1.0);
    glPopMatrix();
}

void MyDisplay() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glViewport(0, 0, Width / 2, Height / 2);  //���ϴ� (�������� glOrtho)
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-3.6, 3.6, -2.7, 2.7, 5, 19.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(0.0 + ex, 3.0 + ey, 5.0 + ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();

    glViewport(Width / 2, Height / 2, Width / 2, Height / 2);   //���� (�������� gluPerspective)
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPerspective(28, 800.0 / 600.0, 5.0, 19.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    gluLookAt(5.0 + px, 5.0 + py, 5.0 + pz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    DrawScene();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h) {
    Width = w;
    Height = h;
}



void MyKeyboard(unsigned char key, int x, int y) {  //�ش� ���ڸ� �������� ���� �� ����
    switch (key) {
    case 'a':case 'A':
        ex = ex + 0.2f;
        px = px + 0.2;
        break;

    case 'f': case 'F':
        ey = ey + 0.2f;
        py = py + 0.2;
        break;

    case 'z': case 'Z':
        ez = ez + 0.2f;
        pz = pz + 0.2f;
        break;

    case 'd':case 'D':
        ex = ex - 0.2f;
        px = px - 0.2;
        break;

    case 'g': case 'G':
        ey = ey - 0.2f;
        py = py - 0.2f;
        break;

    case 't': case 'T':
        ez = ez - 0.2f;
        pz = pz - 0.2f;
        break;
        glutPostRedisplay();
    }

    glutPostRedisplay();
}

void MyIdleax() {  //���̵� ����Ͽ� ���������� ���� 
    ex = ex + 0.1f;
    px = px + 0.1f;

    glutPostRedisplay();
}
void MyIdleax2() {  //���̵� ����Ͽ� ���������� ���� 
    ex = ex - 0.1f;
    px = px - 0.1f;
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {  //���콺�ݹ��Լ�
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        glutIdleFunc(MyIdleax);
    }
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        glutIdleFunc(MyIdleax2);
    }
}


int main(int argc, char** argv) {
    Width = 500;
    Height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(0, 0);
    glutInit(&argc, argv);
    glutCreateWindow("Viewpory Partition");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);  //myKeyboard �߰�
    glutMouseFunc(MyMouseClick);
    glutMainLoop();
    return 0;
}

