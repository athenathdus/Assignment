/********************************************************************************************************************/
/*             HW#4 : Callback ���α׷���  - Ű�����ݹ�(2)                                                                  */
/*  �ۼ��� : �ڼҿ�                              ��¥ : 2020�� 10�� 15��                                                      */
/*                                                                                                                                         */
/* ���� ���� : ����Ű�� ������, 4���� vertex��ǥ�� �����ϰ� ����, ������, �Ʒ���, ���� ���� 0.1�� �̵��ϰ�
�ڵ带 Ȯ���Ͽ���. �־��� vertex 4������ gx,gy ��� ������ �߰��Ͽ� �� Ű�� ������ �����̰� �������,
if ,else������ ������ �����Ͽ� windowȭ�鿡�� ����� �ʰ� �������.
/*                - - - - - - -                                                                                                           */
/*******************************************************************************************************************/
#include <GL/glut.h>
GLfloat gx, gy;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, -0.5 + gy, 0.0);
    glVertex3f(0.5 + gx, 0.5 + gy, 0.0);
    glVertex3f(-0.5 + gx, 0.5 + gy, 0.0);
    glEnd();
    glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch(key)
        case 'Q':
            exit(1);
}

void MySpecial(int key, int x, int y) { //special key �� ����Ͽ�, ����, �Ʒ���, ������, �������� �����̰� ����
    switch (key) {
    case GLUT_KEY_PAGE_UP:  //zoomin
        gx = gx + 0.1f;
        gy = gy + 0.1f;
        break;
    case GLUT_KEY_PAGE_DOWN: //zoomout
        gy = gy - 0.1f;
        gx = gx - 0.1f;
        break;
    case GLUT_KEY_UP:  //����
        if (gy >= 0.4)
            gy = gy;
        else
            gy = gy + 0.1f;
        break;

    case GLUT_KEY_DOWN: //�Ʒ���
        if (gy <= -0.5)
            gy = gy;
        else
            gy = gy - 0.1f;
        break;
    case GLUT_KEY_LEFT: //����
        if (gx <= -0.5)
            gx = gx;
        else
            gx = gx - 0.1f;
        break;
    case GLUT_KEY_RIGHT:  //������
        if (gx >= 0.4)
            gx = gx;
        else
            gx = gx + 0.1f;
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
