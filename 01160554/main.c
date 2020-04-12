#include <GL/glut.h>
#include <math.h>
#include <windows.h> //使用windows API來取得螢幕大小讓視窗在畫面中間

//角度換弳度
#undef rad
#define rad(degrees) ((degrees) * (3.1415926535 / 180.))

//將RGB色彩轉成glColor3f
#undef RGBtoGlColor3f
#define RGBtoGlColor3f(R, G, B) glColor3f(((R) / 255.), ((G) / 255.), ((B) / 255.))

static void display() {
	float a;

	/* ======================== 背景顏色 ======================== */
	glBegin(GL_QUAD_STRIP);
	RGBtoGlColor3f(252, 242, 155);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glEnd();
	/* ======================== 背景顏色 ======================== */

	/* ======================== 耳朵 ======================== */
	double earX = 0.5, earY = 0.5; //耳朵中心座標
	RGBtoGlColor3f(80, 50, 0); //耳朵顏色

	//左耳, 從30度到240度
	glBegin(GL_POLYGON);
	for(a = rad(30) ; a < rad(240) ; a += 0.001) {
		glVertex2f(cos(a) / 3 - earX, sin(a) / 3 + earY);
	}//end for
	glEnd();
	//右耳, 從150度到-60度
	RGBtoGlColor3f(80, 50, 0); //耳朵顏色
	glBegin(GL_POLYGON);
	for(a = rad(150) ; a > rad(-60) ; a -= 0.001) {
		glVertex2f(cos(a) / 3 + earX, sin(a) / 3 + earY);
	}//end for
	glEnd();
	/* ======================== 耳朵 ======================== */

	/* ======================== 臉 ======================== */
	RGBtoGlColor3f(80, 50, 0); //臉顏色

	//畫臉, 從(0, 0)畫圓
	glBegin(GL_POLYGON);
	//上半圓
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		glVertex2f(cos(a) / 1.4, sin(a) / 1.4);
	}//end for
	//下半圓
	for(a = rad(180) ; a > rad(-180) ; a -= 0.001) {
		glVertex2f(cos(a) / 1.4, sin(a) / 1.4);
	}//end for
	glEnd();
	/* ======================== 臉 ======================== */

	/* ======================== 第二層臉 ======================== */
	RGBtoGlColor3f(119, 75, 2); //第二層臉顏色

	//左耳, 從30度到240度
	glBegin(GL_POLYGON);
	for(a = rad(30) ; a < rad(240) ; a += 0.001) {
		glVertex2f(cos(a) / 3.5 - earX, sin(a) / 3.5 + earY);
	}//end for
	glEnd();
	//右耳, 從150度到-60度
	glBegin(GL_POLYGON);
	for(a = rad(150) ; a > rad(-60) ; a -= 0.001) {
		glVertex2f(cos(a) / 3.5 + earX, sin(a) / 3.5 + earY);
	}//end for
	glEnd();

	glBegin(GL_POLYGON);
	//上半圓
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		glVertex2f(cos(a) / 1.48, sin(a) / 1.48 + 0.018);
	}//end for
	//下半圓
	for(a = rad(180) ; a > rad(-180) ; a -= 0.001) {
		glVertex2f(cos(a) / 1.48, sin(a) / 1.48 - 0.018);
	}//end for
	glEnd();
	/* ======================== 第二層臉 ======================== */

	/* ======================== 眼睛 ======================== */
	double x, y; //x, y為橢圓形座標
	double eyeX = 0.3, eyeY = 0.25; //眼睛座標
	double cirH = 0.3, cirW = 0.2; //橢圓的寬高
	RGBtoGlColor3f(0, 0, 0); //眼睛顏色

	//左眼睛
	glBegin(GL_POLYGON);
	//上半部
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		//橢圓形公式
		x = cirW * cos(a) / 3 - eyeX;
		y = cirH * sin(a) / 3 + eyeY;
		//順旋轉公式
		glVertex2f(x * cos(rad(10)) + y * sin(rad(10)), -x * sin(rad(10)) + y * cos(rad(10)));
	}//end for
	//下半部
	for(a = rad(0) ; a > rad(-180) ; a -= 0.001) {
		x = cirW * cos(a) / 3 - eyeX;
		y = cirH * sin(a) / 3 + eyeY;
		glVertex2f(x * cos(rad(10)) + y * sin(rad(10)), -x * sin(rad(10)) + y * cos(rad(10)));
	}//end for
	glEnd();

	//右眼睛
	glBegin(GL_POLYGON);
	//上半部
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		x = cirW * cos(a) / 3 + eyeX;
		y = cirH * sin(a) / 3 + eyeY;
		//逆旋轉公式
		glVertex2f(x * cos(rad(10)) - y * sin(rad(10)), x * sin(rad(10)) + y * cos(rad(10)));
	}//end for
	//下半部
	for(a = rad(0) ; a > rad(-180) ; a -= 0.001) {
		x = cirW * cos(a) / 3 + eyeX;
		y = cirH * sin(a) / 3 + eyeY;
		glVertex2f(x * cos(rad(10)) - y * sin(rad(10)), x * sin(rad(10)) + y * cos(rad(10)));
	}//end for
	glEnd();
	/* ======================== 眼睛 ======================== */

	/* ======================== 嘴巴 ======================== */
	double mouseX = 0, mouseY = -0.2; //嘴巴中心座標
	cirH = 0.35, cirW = 0.5; //嘴巴橢圓形寬高
	RGBtoGlColor3f(173, 112, 14); //嘴巴顏色

	//上半部
	glBegin(GL_POLYGON);
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		glVertex2f(cirW * cos(a) - mouseX, (cirH - 0.02) * sin(a) + mouseY);
	}//end for
	glEnd();
	//下半部
	glBegin(GL_POLYGON);
	for(a = rad(0) ; a > rad(-180) ; a -= 0.001) {
		glVertex2f(cirW * cos(a) - mouseX, (cirH + 0.03) * sin(a) + mouseY);
	}//end for
	glEnd();
	/* ======================== 嘴巴 ======================== */

	/* ======================== 鼻子 ======================== */
	double noseX = 0, noseY = 0; //鼻子中心座標
	cirH = 0.08, cirW = 0.1; //鼻子橢圓形寬高
	RGBtoGlColor3f(0, 0, 0); //鼻子顏色

	//上半部
	glBegin(GL_POLYGON);
	for(a = rad(0) ; a < rad(180) ; a += 0.001) {
		glVertex2f(cirW * cos(a) - noseX, (cirH - 0.02) * sin(a) + noseY);
	}//end for
	glEnd();
	//下半部
	glBegin(GL_POLYGON);
	for(a = rad(0) ; a > rad(-180) ; a -= 0.001) {
		glVertex2f(cirW * cos(a) - noseX, (cirH + 0.03) * sin(a) + noseY);
	}//end for
	glEnd();
	/* ======================== 鼻子 ======================== */

	glutSwapBuffers();
}//end display

int main() {
	int xScreen, yScreen;

	//取得螢幕大小
	xScreen = GetSystemMetrics(SM_CXSCREEN);
	yScreen = GetSystemMetrics(SM_CYSCREEN);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	//set window size and start position
	//視窗正方形, 500 * 500
	glutInitWindowSize(500, 500);
	//視窗中央座標為視窗大小除以2, 開始位置扣除一半的視窗大小就是左上角開始畫視窗的座標
	glutInitWindowPosition(xScreen / 2 - 250, yScreen / 2 - 250);

	glutCreateWindow("Bear");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}//end main
