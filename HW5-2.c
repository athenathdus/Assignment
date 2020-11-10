/********************************************************************************************************************/
/*                    HW#5 : �κ��� �հ��� ����                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 11�� 11��                                                     */
/*                                                                                                                                         */
/* ���� ���� : �հ��� 3���� ���� �κ����� �����ϴ� ���̴�. �� �հ��� �� ������ 2�� �̻����� �����Ͽ���
* �κ��� �հ��� 3���� ����2������ �����Ͽ�����, 1,2,3 Ű�� ������ �Ǹ� �հ����� ������ ��� �ؾ��ؼ� 
* ����Ű���� �Լ��� �����Ͽ�����, �������� �ʾҴ�. �� ���콺 �ݹ��� ����ؼ� ȸ�� �� ���ư��⸦ �ؾ�������
* �������� �������� ���Ͽ� ���콺 �ݹ��� Ʋ�� �ϼ��Ͽ���. �Ҽ��ִ� �κп� �־�� �ּ��� ���� �����Ͽ���. 
* 
/*                                                                                             */
/*******************************************************************************************************************/


#include <stdlib.h>
#include <gl/glut.h>

static int shoulder = 0, elbow = 0, hand = 0, finger1 = 0, finger2 = 0, finger3 = 0;
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);	 // Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��
    glScalef(1.5, 0.4, 1.0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0.0, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��
      //  glColor3f(1.0, 1.0, 1.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01, 0.0, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.05, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01,-0.01, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.3, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.01, -0.01, 0.0);	// Pivot ���� �� ��ü �̵�
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0); // ������ �������� ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// Pivot���� ������ ��ġ�� �������� �̵�
    glPushMatrix();	// ������ �������� ��ü ���� �� ���/Ȯ��

    glScalef(1.0, 0.4, 1.0);
    glutWireCube(0.5);
    glPopMatrix();

    glutSwapBuffers();

}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {  //���콺 �ݹ�
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        
    }
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {

    }
}

void MyKeyboard(unsigned char key, int x, int y) {  //����Ű���� �Լ� 

    switch (key) {
    case '1':
        finger1 = (finger1 + 5) % 360;
        break;
    case '2':
        finger2 = (finger2 + 5) % 360;
        break;
    case '3':
        finger3 = (finger3 + 5) % 360;
        break;
    
    default:
        break;
    }
  glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);

    glutMainLoop();
    return 0;
}
