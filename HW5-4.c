/********************************************************************************************************************/
/*             HW#5 :  gluLookAt()�� �ǽð�����                                                              */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 11�� 10��                                                     */
/*                                                                                                                                         */
/* ���� ���� : ���� ��ǥ�踦 Ű���� �ݹ� �Լ��� �ǽð� ��� �����ϵ��� �����ϴ� ���̴�.
* glLookAt()�Լ��� ���ڸ� float ���� ax,ay,az,ex,ey�� ����Ͽ� ���� 0.1 �� ������ �� �ֵ��� �������.
* ����Ű����� ���� ����� �Լ��� ���� ����Ű�� Ư�� ���ڸ� ������ ���� �Ǵ� ���� �� �� �ֵ��� �Ͽ���.
/*                                                                                             */
/*******************************************************************************************************************/

#include <GL/glut.h>

void DrawGround() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, -0.71, 2.0);
    glVertex3f(2.0, -0.71, 2.0);
    glVertex3f(2.0, -0.71, -2.0);
    glVertex3f(-2.0, -0.71, -2.0);
    glEnd();

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
    for (float x = -2.0; x <= 2.2; x += 0.2) {
        glVertex3f(x, -0.7, -2.0);
        glVertex3f(x, -0.7, 2.0);
    }

    for (float z = -2.0; z <= 2.2; z += 0.2) {
        glVertex3f(-2.0, -0.7, z);
        glVertex3f(2.0, -0.7, z);
    }
    glEnd();
}

float ex, ey, ax, ay, az; //float ���� ����

void MyDisplay() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0 + ex, 3.5 + ey, 3.5, 0.0 + ax, 0.0 + ay, 0.0 + az, 0.0, 1.0, 0.0);  //gluLookAt()�Լ��� ������ float �������� ����

    //gluLookAt(-1.0, 0.5, 3.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    DrawGround();

    glColor3f(1.0, 1.0, 0.0);
    glutWireTeapot(1.0);

    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}

// Ÿ�̸� �ݹ��� ����Ͽ� ���������� 0.1 �� ���� �Ǵ� ���� �ϰ� �������

void MyIdleax() {
    ax = ax + 0.1f;

    glutPostRedisplay();
}
void MyIdleax2() {
    ax = ax - 0.1f;

    glutPostRedisplay();
}
void MyIdleay() {
    ay = ay + 0.1f;

    glutPostRedisplay();
}
void MyIdleay2() {
    ay = ay - 0.1f;

    glutPostRedisplay();
}
void MyIdleaz() {
    az = az + 0.1f;

    glutPostRedisplay();
}
void MyIdleaz2() {
    az = az - 0.1f;

    glutPostRedisplay();
}
void MyIdleex() {
    ex = ex + 0.1f;

    glutPostRedisplay();
}
void MyIdleex2() {
    ex = ex - 0.1f;

    glutPostRedisplay();
}
void MyIdleey() {
    ey = ey + 0.1f;

    glutPostRedisplay();
}
void MyIdleey2() {
    ey = ey - 0.1f;

    glutPostRedisplay();
}

//void MyTimerax(int Value) {
//    ax = ax + 0.1f;
//
//    glutPostRedisplay();
//    glutTimerFunc(40, MyTimerax, 1);
//}
void MyTimerax2(int Value) {
    ax = ax - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerax2, 1);
}
void MyTimeray(int Value) {
    ay = ay + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeray, 1);
}
void MyTimeray2(int Value) {
    ay = ay - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeray2, 1);
}
void MyTimeraz(int Value) {
    az = az + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeraz, 1);
}
void MyTimeraz2(int Value) {
    az = az + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimeraz2, 1);
}

void MyTimerey(int Value) {
    ey = ey + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerey, 1);
}
void MyTimerey2(int Value) {
    ey = ey - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerey2, 1);
}
void MyTimerex(int Value) {
    ex = ex + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerex, 1);
}
void MyTimerex2(int Value) {
    ex = ex - 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimerex2, 1);
}
void MyTimer(int Value) {
    ax = ax + 0.1f;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}


void MyKeyboard(unsigned char key, int x, int y) {  //�ش� ���ڸ� �������� Ÿ�̸Ӹ� �θ� 

    switch (key) {
    case 'a':case 'A':
        glutIdleFunc(MyIdleax);
        break;

    case 'f': case 'F':
        glutIdleFunc(MyIdleax2);
        break;

    case 'r': case 'R':
        glutIdleFunc(MyIdleay);
        break;

    case 'v': case 'V':
        glutIdleFunc(MyIdleay2);
        break;

    case 'z': case 'Z':
        glutIdleFunc(MyIdleaz);
        break;

    case 't': case 'T':
        glutIdleFunc(MyIdleaz2);
        break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {  //����Ű�� �������� Ÿ�̸��ݹ��� �θ�
    switch (key) {
    case GLUT_KEY_UP:
        glutIdleFunc(MyIdleey);
        break;
    case GLUT_KEY_DOWN:
        glutIdleFunc(MyIdleey2);
        break;
    case GLUT_KEY_LEFT:
        glutIdleFunc(MyIdleex2);
        break;
    case GLUT_KEY_RIGHT:
        glutIdleFunc(MyIdleex);
        break;

    default:
        break;
    } glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("VCS (View Coordinate System)");
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutSpecialFunc(MySpecial); //mySpecial �߰�
    glutKeyboardFunc(MyKeyboard);  //myKeyboard �߰�
    
    glutMainLoop();
    return 0;
}