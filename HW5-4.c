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

    gluLookAt(0.0+ex, 3.5+ey, 3.5, 0.0+ax, 0.0+ay, 0.0+az, 0.0, 1.0, 0.0);  //gluLookAt()�Լ��� ������ float �������� ����

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

void MyKeyboard(unsigned char key, int x, int y) {  //mykeyboard�� ����Ͽ� ���ڸ� �������� 0.1�� ���� �Ǵ� �����ϰ� ��

    switch (key) {
    case 'a':case 'A': 
        ax = ax + 0.1f;
        break;

    case 'f': case 'F': 
        ax = ax - 0.1f;
        break;

    case 'r': case 'R': 
        ay = ay + 0.1f;
        break;

    case 'v': case 'V': 
        ay = ay - 0.1f;
        break;
  
    case 'z': case 'Z': 
        az = az + 0.1f;
        break;

    case 't': case 'T': 
        az = az - 0.1f;
        break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {  //����Ű�� �������� 0.1�� ���� �Ǵ� ���� �ϰ��� 
    switch (key) {
    case GLUT_KEY_UP:
        ey = ey + 0.1f;
        break;
    case GLUT_KEY_DOWN:
        ey = ey - 0.1f;
        break;
    case GLUT_KEY_LEFT:
        ex = ex - 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        ex = ex + 0.1f;
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
