/********************************************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ÿ�̸��ݹ�(1)                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 10�� 15��                                                      */
/*                                                                                                                                         */
/* ���� ���� : ������ ������� ���������� 15���� �ٿ��� ����� �ٲ�� ��.
/* timer callback�� ����Ͽ� ��� �ݺ��ǰ� �������, timer callback�� �Ҹ������� �������� gx,gy,gz�� ���Ͽ�,
   ���� ��� �ٲ�� �������.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/

#include <gl/glut.h>

GLfloat Delta = 0.0;
GLfloat gx, gy, gz;  //float���� gx,gy,gz�� ����
int key;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0 - gx, 1.0 - gy, 1.0-gz);  //�� ��ȭ�� ����, 1.0���� gx,gy,gz�� ���� �ֵ��� ����
    glVertex3f(-1.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}
void MyTimer(int Value) {

    gx += 0.05;   //gx�� 0.05 �������� ����.
    gy += 0.05;   //gy�� 0.05 �������� ����.
    gz += 0.05;   //gz�� 0.05 �������� ����.
    //
    glutPostRedisplay();
    glutTimerFunc(500, MyTimer, 1);
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Timer Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(1000, MyTimer, 1);

    glutMainLoop();
    return 0;
}
