#include <GL/glut.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
void Triangulo(GLfloat A[],GLfloat B[],GLfloat C[]) {
    glBegin(GL_TRIANGLES);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glEnd();
}
void Tetraedro(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloatV3[]) {
    glColor3f(1, 0.5, 0);
    Triangulo(V0, V1, V2);
    glColor3f(0, 1, 1);
    Triangulo(V0, V2, V3);
    glColor3f(1, 0, 1);
    Triangulo(V1, V2, V3);
    glColor3f(0.5, 0, 0.5);
    Triangulo(V0, V1, V3);
}
void AjustarPosicoes(GLfloat V1[],GLfloat V2[],GLfloat V3[], GLfloat V4[],int n) {
    GLfloat V12[3];
    GLfloat V23[3];
    GLfloat V31[3];
    GLfloat V14[3];
    GLfloat V24[3];
    GLfloat V34[3];
    if(n > 0) {
        V12[0] = (V1[0] + V2[0]) / 2;
        V12[1] = (V1[1] + V2[1]) / 2;
        V12[2] = (V1[2] + V2[2]) / 2;
        V23[0] = (V2[0] + V3[0]) / 2;
        V23[1] = (V2[1] + V3[1]) / 2;
        V23[2] = (V2[2] + V3[2]) / 2;
        V31[0] = (V3[0] + V1[0]) / 2;
        V31[1] = (V3[1] + V1[1]) / 2;
        V31[2] = (V3[2] + V1[2]) / 2;
        V14[0] = (V1[0] + V4[0]) / 2;
        V14[1] = (V1[1] + V4[1]) / 2;
        V14[2] = (V1[2] + V4[2]) / 2;
        V24[0] = (V2[0] + V4[0]) / 2;
        V24[1] = (V2[1] + V4[1]) / 2;
        V24[2] = (V2[2] + V4[2]) / 2;
        V34[0] = (V3[0] + V4[0]) / 2;
        V34[1] = (V3[1] + V4[1]) / 2;
        V34[2] = (V3[2] + V4[2]) / 2;
        AjustarPosicoes(V1,V12,V31,V14,n-1);
        AjustarPosicoes(V12,V2,V23,V24,n-1);
        AjustarPosicoes(V31,V23,V3,V34,n-1);
        AjustarPosicoes(V14,V24,V34,V4,n-1);
    } else {
        Tetraedro(V1,V2,V3, V4);
    }
}
void Desenhe() {
    GLfloat P[4][3] = {
        {-0.5,-0.5,0.5},
        {0.5,-0.5,0.5},
        {0,0.5,0.5},
        {0,0.1,-0.5},
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    AjustarPosicoes(P[0],P[1],P[2],P[3],3);
    glutSwapBuffers();
}
int main (int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("M1 - Rasterization");
    glutDisplayFunc(Desenhe);
    glutMainLoop();
    return 0;
}