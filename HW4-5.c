/********************************************************************************************************************/
/*             HW#4 : Callback ���α׷���  - ldle�ݹ�(1)                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 10�� 15��                                                      */
/*                                                                                                                                         */
/* ���� ���� : ����Ű�� ������, 4���� vertex��ǥ�� �����ϰ� ����, ������, �Ʒ���, ���� ���� 0.1�� �̵��ϰ�
�ڵ带 Ȯ���Ͽ���. �־��� vertex 4������ gx,gy ��� ������ �߰��Ͽ� �� Ű�� ������ �����δ�. Idle�ݹ��
special key�� ����Ͽ� �����Ͽ���. 
/*                                                                                                                  */
/*******************************************************************************************************************/


#include <GL/glut.h>

GLfloat Delta = 0.0;
GLfloat gx = 0;
GLfloat gy = 0; //gx,gy ���� 
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.8);  //�� vertex ����
    glVertex3f(-0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 + gy, 0.0);
    glEnd();
    glutSwapBuffers();
}

void MyIdle1() {  //idle 1 (������ �̵�)
  
          if(gx<0.5)
              gx = gx + 0.01f;

    glutPostRedisplay();
}
void MyIdle2() {  //idle 2 (���� �̵�)

    if(gy<0.5)
        gy = gy + 0.01f;

    glutPostRedisplay();
}
void MyIdle3() {  //idle 3 (�Ʒ��� �̵�)
    if (gy>-0.5)
        gy = gy - 0.01f;

    glutPostRedisplay();
} 
void MyIdle4() { //idle 4 (���� �̵�)
    if(gx>-0.5)
        gx = gx - 0.01f;
    glutPostRedisplay();
}
void MySpecial(int key, int x, int y) { //special key �� ����Ͽ�, ����, �Ʒ���, ������, �������� �����̰� ����
    switch (key) {
    
    case GLUT_KEY_UP:  //����
        glutIdleFunc(MyIdle2);
        break;
    case GLUT_KEY_DOWN: //�Ʒ���
        glutIdleFunc(MyIdle3);
        break;
    case GLUT_KEY_LEFT: //����
        glutIdleFunc(MyIdle4);
        break;
    case GLUT_KEY_RIGHT:  //������
        glutIdleFunc(MyIdle1);
        break;
    default:
        break;
    }
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
    glutCreateWindow("Idle Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(MySpecial); //myspecial�� �ҷ� idle callback ����� 
    glutMainLoop();
    return 0;
}
