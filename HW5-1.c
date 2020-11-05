/********************************************************************************************************************/
/*             HW#5 : 태양계 모델링 확장                                                                  */
/*  작성자 : 박소연                              날짜 : 2020년 11월 6일                                                     */
/*                                                                                                                                         */
/* 문제 정의 : 태양을 비롯하여 수성, 금성, 지구 , 달 등 4개의 행성을 모델링 하였다. */
/* push, pop 을 적절히 사용하여 다섯개의 행성을 모두 만들어 내었고, glTranslatef를 사용하여 각 위치를*/
/* 서로 다르게 배치했으며, glclearcolor을 통해 배경색을 검정색으로 만들었다. 크기 색상 및 공전각도는*/
/* 함수내의 조절을 통해 서로 다르게 설정하였으며, 각 거리도 적절히 설정하였다. */
/* 마우스콜백 함수를 통하여 마우스왼쪽을 누르면 공전하도록, 오른쪽을 누르면 멈추게 하였고,*/
/* 타이머 콜백을 통하여 지속적으로 움직이게 하였다. */
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
    glutWireSphere(0.15, 20, 16); //태양
    glPushMatrix();

    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.7, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.3, 0.8, 0.9);
    glutWireSphere(0.09, 10, 8); //지구
   glPushMatrix();  

    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.9, 0.5, 0.9);
    glutWireSphere(0.04, 10, 8);  //달
    
   
    glPopMatrix();
    glPopMatrix();
  
    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.4, 0.8);
    glutWireSphere(0.07, 10, 8);  //금성
    glPopMatrix();  

    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.2, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.3, 0.5, 0.8);
    glutWireSphere(0.05, 10, 8);  //수성
    glPopMatrix();
    glutSwapBuffers();
}

void MyTimer(int Value) {  //mytimer을 이용해 계속 공전하게 만듦

    Day = (Day + 10) % 360;
    Time = (Time + 5) % 360;
    glutPostRedisplay();
    if (flag == 1) 
    {
        glutTimerFunc(60, MyTimer, 1);
    }
   
}


void MyMouseClick(GLint Button, GLint State,GLint X, GLint Y) { 
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {  //왼쪽 마우스를 클릭했을 경우, 공전
        if (flag == 0)
        {
            flag = 1;
            glutTimerFunc(10, MyTimer, 1);
        }
        
    }
    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {  //오른쪽마우스를 클릭했을 경우 정지 
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
