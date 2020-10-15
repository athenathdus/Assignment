/********************************************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(1)                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 10�� 15��                                                      */
/*                                                                                                                                         */
/* ���� ���� : Ű�� ������, 4���� vertex��ǥ�� �����ϰ� ����, ������, �Ʒ���, ���� ���� 0.1�� �̵��ϰ�
�ڵ带 Ȯ���Ͽ���. �־��� vertex 4������ gx,gy ��� ������ �߰��Ͽ� �� Ű�� ������ �����̰� �������,
������ RGB�� ����Ͽ� �������� (1,0,0), �Ķ����� (0,0,1) �� �ǵ��� ������ �߰��Ͽ� �����Ͽ���.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/

#include <GL/glut.h>
GLfloat gx, gy, c, d, e; //���� gx,gy,c,d,e�� ����


void MyDisplay() {  // vertex�� gx,gy ������ �߰��Ͽ� mykeyboard ���� ���� ����� �� �ֵ��� ����
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5+c, 0.5+d, 0.5+e);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + gx, -0.5 - gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 - gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 - gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 - gy, 0.0);
    glEnd();
    glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) { 

    switch (key) {
    case 'a':case 'A': // 4 ���� vertex ��ǥ�� �����ϰ� �������� 0.1 �� �̵�
        gx = gx - 0.1f;
        break;

    case 'f': case 'F': // 4 ���� vertex ��ǥ�� �����ϰ� ���������� 0.1 �� �̵�
        gx = gx + 0.1f;
        break;

    case 'r': case 'R': //4 ���� vertex ��ǥ�� �����ϰ� �Ʒ������� 0.1 �� �̵��ϰ� ���������� Polygon ĥ��
        c = c + 0.5;
        d = d - 0.5;
        e = e - 0.5;
       
        gy = gy - 0.1f;
        break;

    case 'v': case 'V': // 4 ���� vertex ��ǥ�� �����ϰ� �������� 0.1 �� �̵�
       
        gy = gy + 0.1f;
        break;

    case 'b':  // �Ķ������� Polygon ĥ��
        c = c - 0.5;
        d = d - 0.5;
        e = e + 0.5;
        break;
    }
    glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        break;
    case GLUT_KEY_LEFT:
        break;
    default:
        break;
    }
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Keyboard Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutSpecialFunc(MySpecial);

    glutMainLoop();
    return 0;
}
