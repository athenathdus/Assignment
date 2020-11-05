/********************************************************************************************************************/
/*             HW#5 : �¾�� �𵨸� Ȯ��                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 11�� 6��                                                     */
/*                                                                                                                                         */
/* ���� ���� : �¾��� ����Ͽ� ����, �ݼ�, ���� , �� �� 4���� �༺�� �𵨸� �Ͽ���. */
/* push, pop �� ������ ����Ͽ� �ټ����� �༺�� ��� ����� ������, glTranslatef�� ����Ͽ� �� ��ġ��*/
/* ���� �ٸ��� ��ġ������, glclearcolor�� ���� ������ ���������� �������. ũ�� ���� �� ����������*/
/* �Լ����� ������ ���� ���� �ٸ��� �����Ͽ�����, �� �Ÿ��� ������ �����Ͽ���. */
/* ���콺�ݹ� �Լ��� ���Ͽ� ���콺������ ������ �����ϵ���, �������� ������ ���߰� �Ͽ���,*/
/* Ÿ�̸� �ݹ��� ���Ͽ� ���������� �����̰� �Ͽ���. */
/*                                                                                             */
/*******************************************************************************************************************/

#include <gl/glut.h>

static int Day = 0, Time = 0;
int flag = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.3, 0.3);
    glutWireSphere(0.15, 20, 16); //�¾�
    glPushMatrix();

    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.3, 0.8, 0.9);
    glutWireSphere(0.09, 10, 8); //����
   glPushMatrix();  

    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.9, 0.5, 0.9);
    glutWireSphere(0.04, 10, 8);  //��
    
   
    glPopMatrix();
    glPopMatrix();
  
    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.4, 0.8);
    glutWireSphere(0.07, 10, 8);  //�ݼ�
    glPopMatrix();  

    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.2, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.3, 0.5, 0.8);
    glutWireSphere(0.05, 10, 8);  //����
    glPopMatrix();
    glutSwapBuffers();
}

void MyTimer(int Value) {  //mytimer�� �̿��� ��� �����ϰ� ����

    Day = (Day + 10) % 360;
    Time = (Time + 5) % 360;
    glutPostRedisplay();
    if (flag == 1) 
    {
        glutTimerFunc(60, MyTimer, 1);
    }
   
}


void MyMouseClick(GLint Button, GLint State,GLint X, GLint Y) { 
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {  //���� ���콺�� Ŭ������ ���, ����
        if (flag == 0)
        {
            flag = 1;
            glutTimerFunc(10, MyTimer, 1);
        }
        
    }
    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {  //�����ʸ��콺�� Ŭ������ ��� ���� 
        flag = 0;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Solar System");
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutTimerFunc(40, MyTimer, 1);
    glutMainLoop();
    return 0;
}
