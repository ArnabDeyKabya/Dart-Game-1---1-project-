#include "iGraphics.h"
#include<string>
#include<math.h>
#include<stdlib.h>

using namespace std;

double x1[] = {774.999945, 761.537849, 722.469427, 661.619791, 584.946517, 499.956422};
double y_one[] = {360.174311, 444.987962, 521.655046, 582.495041, 621.551313, 634.999997};
double x2[] = {499.956422, 414.970594, 338.309702, 277.479351, 238.435229, 225.000014};
double y2[] = {634.999997, 621.524378, 582.443808, 521.584531, 444.905069, 359.912844};
double x3[] = {225.000014, 238.489100, 277.581817, 338.450733, 415.136381, 500.130733};
double y3[] = {359.912844, 274.929153, 198.274455, 137.453748, 98.421778,  85.000031};
double x4[] = {500.130733, 585.112286, 661.760788, 722.571849, 761.591666, 774.999945};
double y4[] = {85.000031,  98.502584,  137.607448, 198.486000, 275.177833, 360.174311};

int x = 500, y = 360, r = 305;
char score_string[10]="";
char total_string[10]="";
char highest_score[100]="";
char thanks[100]="";
char quit_game[100]="";
char personal_high[100]="";
int countAttempt = 0;

/*
	function iDraw() is called again and again by the system.

*/
int circle_0(double dx, double dy)
{
    if(((dx - 500)*(dx - 500))+((dy - 360)*(dy - 360))-(18*18) >= 0) return 1;
    else return 0;
}
int circle_1(double dx, double dy)
{
    if(((dx - 500)*(dx - 500))+((dy - 360)*(dy - 360))-(150*150) >= 0) return 1;
    else return 0;
}
int circle_2(double dx, double dy)
{
    if(((dx - 500)*(dx - 500))+((dy - 360)*(dy - 360))-(180*180) >= 0) return 1;
    else return 0;
}
int circle_3(double dx, double dy)
{
    if(((dx - 500)*(dx - 500))+((dy - 360)*(dy - 360))-(275*275) >= 0) return 1;
    else return 0;
}
int circle_4(double dx, double dy)
{
    if(((dx - 500)*(dx - 500))+((dy - 360)*(dy - 360))-(305*305) >= 0) return 1;
    else return 0;
}

int first_quadrant(int dx, int dy)
{
    if(dx-500>0 && dy-360>0)return 1;
    else return 0;
}
int second_quadrant(int dx, int dy)
{
    if(dx-500<0 && dy-360>0)return 1;
    else return 0;
}
int third_quadrant(int dx, int dy)
{
    if(dx-500<0 && dy-360<0)return 1;
    else return 0;
}
int fourth_quadrant(int dx, int dy)
{
    if(dx-500>0 && dy-360<0)return 1;
    else return 0;
}

void drawTextBox()
{
    iSetColor(150, 150, 150);
    iRectangle(450, 350, 250, 30);
}

char str[100], str2[100];
char timer_str[100], time_out[100];
int len, timer = 0;
int mode;
double dx, dy;
char str_score [30] = "Your score is 0";
int z=0, e=0, f=0, q=0, v=0;

void iDraw()
{

    iClear();
    iShowBMP(200,75, "dart3.bmp");
    iShowBMP(400,400,"how to play7.bmp");
    iShowBMP(400,300,"exit2.bmp");
    iShowBMP(400,500,"start5.bmp");
    if(z==1)
    {
        iClear();
        iShowBMP(250,150,"thanks3.bmp");
        e = 3;
    }
    if(q==1)
    {
        iClear();
        iShowBMP(200, 200, "how to play11.bmp");
        iShowBMP(350, 125, "main menu2.bmp");
    }
    if(v==1)
    {
        iClear();
        iShowBMP(200,75, "dart3.bmp");
        iShowBMP(400,400,"how to play7.bmp");
        iShowBMP(400,300,"score3.bmp");
        iShowBMP(400,200,"exit2.bmp");
        iShowBMP(400,500,"start5.bmp");

    }
    if(e == 1)
    {
        iClear();
        iShowBMP(0, 0, "BACKGROUND.bmp");
        drawTextBox();
        if(mode == 1)
        {
            iSetColor(255, 200, 255);
            iText(455, 360, str);
        }
        iText(130, 420, "Click to activate the box. Enter your Name in UPPERCASE letter and press ENTER to start the game.", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(e == 2)
    {
        iClear();
        iShowBMP(0,0, "BACKGROUND.bmp");
        iSetColor(0,0,255);
        iSetColor(10,10,10);
        iSetColor(0,255,0);
        iCircle(500,360,305);
        iSetColor(255,255,0);
        iCircle(500,360,275);
        iSetColor(255,0,0);
        iCircle(500,360,150);
        iSetColor(0,0,255);
        iCircle(500,360,180);
        iSetColor(200,150,230);
        int i;
        double o;

        double p, q;
        for (i=1,o=(18/57.29); i<=20; i++,o+=(18/57.29))
        {
            p = 500+275*cos(o);
            q = 360+275*sin(o);
            iLine(500, 360, p, q);
        }
        iSetColor(200,150,230);
        iFilledCircle(500,360,18);//out

        iSetColor(255, 0, 0);

        iFilledCircle(dx, dy, 5);

        iText((x1[0] + x1[1])/2.0 + 5, (y_one[0] + y_one[1])/2.0 + 5, "10");
        iText((x1[1] + x1[2])/2.0 + 5, (y_one[1] + y_one[2])/2.0 + 5, "20");
        iText((x1[2] + x1[3])/2.0 + 5, (y_one[2] + y_one[3])/2.0 + 5, "30");
        iText((x1[3] + x1[4])/2.0 + 5, (y_one[3] + y_one[4])/2.0 + 5, "40");
        iText((x1[4] + x1[5])/2.0 + 5, (y_one[4] + y_one[5])/2.0 + 5, "50");

        iText((x2[0] + x2[1])/2.0 + 5, (y2[0] + y2[1])/2.0 + 5, "60");
        iText((x2[1] + x2[2])/2.0 + 5-5, (y2[1] + y2[2])/2.0 + 5+5, "70");
        iText((x2[2] + x2[3])/2.0 + 5-10, (y2[2] + y2[3])/2.0 + 5+10, "80");
        iText((x2[3] + x2[4])/2.0 + 5-2-5-10, (y2[3] + y2[4])/2.0 + 5+2, "90");
        iText((x2[4] + x2[5])/2.0 + 5-25-5, (y2[4] + y2[5])/2.0 + 5, "100");

        iText((x3[0] + x3[1])/2.0 + 5-10-15-5, (y3[0] + y3[1])/2.0 + 5-2, "110");
        iText((x3[1] + x3[2])/2.0 + 5-20-10, (y3[1] + y3[2])/2.0 + 5-10, "120");
        iText((x3[2] + x3[3])/2.0 + 5-25-10, (y3[2] + y3[3])/2.0 + 5-15, "130");
        iText((x3[3] + x3[4])/2.0 + 5-10-10, (y3[3] + y3[4])/2.0 + 5-20, "140");
        iText((x3[4] + x3[5])/2.0 + 5-10, (y3[4] + y3[5])/2.0 + 5-20, "150");

        iText((x4[0] + x4[1])/2.0 + 5-5-5, (y4[0] + y4[1])/2.0 + 5-15-5, "160");
        iText((x4[1] + x4[2])/2.0 + 5-10, (y4[1] + y4[2])/2.0 + 5-30+5, "170");
        iText((x4[2] + x4[3])/2.0 + 5, (y4[2] + y4[3])/2.0 + 5-15, "180");
        iText((x4[3] + x4[4])/2.0 + 5, (y4[3] + y4[4])/2.0 + 5-10, "190");
        iText((x4[4] + x4[5])/2.0 + 5, (y4[4] + y4[5])/2.0 + 5, "200");
        iText(720, 650, "Your Current Score is : ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(850+20+20+10+10+50, 600+20+20+10, score_string, GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(950+20, 625, total_string, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(720+20, 625, "Your Total  score is : ",GLUT_BITMAP_TIMES_ROMAN_24 );
        iSetColor(255, 255, 255);
        iText(720, 600, highest_score, GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(720, 580, thanks, GLUT_BITMAP_HELVETICA_18);
        iText(720+20+20+20, 540, quit_game, GLUT_BITMAP_HELVETICA_18);
        iText(780, 520, personal_high, GLUT_BITMAP_HELVETICA_18);

        if(timer<500)timer++;
        if(timer == 500)
        {
            iKeyboard('p');
        }
        else
        {
            int temp = timer;
            char s[100];
            int k = 0;
            while(temp != 0)
            {
                s[k++] = temp%10 + '0';
                temp/=10;
            }
            s[k] = '\0';
            strrev(s);
            strcpy(timer_str, "\0");
            strcat(timer_str, "Timer: ");
            strcat(timer_str, s);

            if(countAttempt < 3)iText(100, 540, timer_str, GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(timer == 500 && countAttempt < 3)iText(800, 500, time_out, GLUT_BITMAP_HELVETICA_18);
    }
}


void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(z==0)
    {
        if(mx >= 400 && mx <= 600 && my >= 300 && my <= 350)
        {
            z++;
        }
    }
    if(e==0)
    {
        if(mx >= 400 && mx <= 600 && my >= 500 && my <= 550)
        {
            e++;
        }
    }
    if(e == 1)
    {

        if(mx >= 450 && mx <= 700 && my >= 350 && my <= 380 && mode == 0)
        {
            mode = 1;
        }

    }
    if(q==0)
    {
        if(mx >= 400 && mx <= 600 && my >= 400 && my <= 450)
            q++;
    }
    if(v==0)
    {
        if(mx >= 350 && mx <= 550 && my >= 125 && my <= 175)
        {
            v++;
        }
    }

}




int score_calculation(int value)
{
    if(!(circle_0(dx, dy)))
    {
        return 1000;
    }
    else if(!(circle_1(dx, dy)))
    {
        return (value*3);
    }
    else if(!(circle_2(dx, dy)))
    {
        return (value*2);
    }
    else if(!(circle_3(dx, dy)))
    {
        return (value*1);
    }
    else if(!(circle_4(dx, dy)))
    {
        return 0;
    }
}

int score, total = 0;
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key=='p')
    {
        if(timer == 500)
        {
            strcpy(time_out, "Your time is out, press 'q' to quit.");
            iPauseTimer(0);
        }
        else
        {
            iPauseTimer(0);
            if(first_quadrant(dx, dy))
            {

                double minimum;
                int index;
                int i;
                double a1, b1, c1, d1, a2, b2, c2, d2, sum;
                for(i=0; i<6; i++)
                {
                    a1=(360 - y_one[i]);
                    b1=(x1[i] - 500);
                    c1=500*y_one[i] - 360*x1[i];
                    d1=fabs(a1*dx + b1*dy + c1)/(sqrt(a1*a1 + b1*b1));

                    a2=(360 - y_one[i+1]);
                    b2=(x1[i+1] - 500);
                    c2=500*y_one[i+1] - 360*x1[i+1];
                    d2=fabs(a2*dx + b2*dy + c2)/(sqrt(a2*a2 + b2*b2));

                    sum = d1 + d2;

                    if(i==0)
                    {
                        minimum = sum;
                        index = i;
                    }
                    else
                    {
                        if (sum < minimum)
                        {
                            minimum = sum;
                            index = i;
                        }
                    }
                }
                if(index == 0)
                {
                    score = score_calculation(10);

                }
                if(index == 1)
                {
                    score= score_calculation(20);
                }
                if(index == 2)
                {
                    score = score_calculation(30);
                }
                if(index == 3)
                {
                    score = score_calculation(40);
                }
                if(index == 4)
                {
                    score = score_calculation(50);
                }
            }
            if(second_quadrant(dx, dy))
            {
                double minimum;
                int i, index;
                double a1, b1, c1, d1, a2, b2, c2, d2, sum;
                for(i=0; i<6; i++)
                {
                    a1=(360 - y2[i]);
                    b1=(x2[i] - 500);
                    c1=500*y2[i] - 360*x2[i];
                    d1=fabs(a1*dx + b1*dy + c1)/(sqrt(a1*a1 + b1*b1));

                    a2=(360 - y2[i+1]);
                    b2=(x2[i+1] - 500);
                    c2=500*y2[i+1] - 360*x2[i+1];
                    d2=fabs(a2*dx + b2*dy + c2)/(sqrt(a2*a2 + b2*b2));
                    sum = d1 + d2;

                    if(i==0)
                    {
                        minimum = sum;
                        index = i;
                    }
                    else
                    {
                        if (sum < minimum)
                        {
                            minimum = sum;
                            index = i;
                        }
                    }

                }
                if(index == 0)
                {
                    score = score_calculation(60);
                }
                if(index == 1)
                {
                    score = score_calculation(70);
                }
                if(index == 2)
                {
                    score = score_calculation(80);
                }
                if(index == 3)
                {
                    score = score_calculation(90);
                }
                if(index == 4)
                {
                    score = score_calculation(100);
                }
            }
            if(third_quadrant(dx, dy))
            {
                double minimum;
                int i, index;
                double a1, b1, c1, d1, a2, b2, c2, d2, sum;
                for(i=0; i<6; i++)
                {
                    a1=(360 - y3[i]);
                    b1=(x3[i] - 500);
                    c1=500*y3[i] - 360*x3[i];
                    d1=fabs(a1*dx + b1*dy + c1)/(sqrt(a1*a1 + b1*b1));

                    a2=(360 - y3[i+1]);
                    b2=(x3[i+1] - 500);
                    c2=500*y3[i+1] - 360*x3[i+1];
                    d2=fabs(a2*dx + b2*dy + c2)/(sqrt(a2*a2 + b2*b2));

                    sum = d1 + d2;

                    if(i==0)
                    {
                        minimum = sum;
                        index = i;
                    }
                    else
                    {
                        if (sum < minimum)
                        {
                            minimum = sum;
                            index = i;
                        }
                    }


                }
                if(index == 0)
                {
                    score = score_calculation(110);
                }
                if(index == 1)
                {
                    score = score_calculation(120);

                }
                if(index == 2)
                {
                    score = score_calculation(130);
                }
                if(index == 3)
                {
                    score = score_calculation(140);
                }
                if(index == 4)
                {
                    score = score_calculation(150);
                }

            }
            if(fourth_quadrant(dx, dy))
            {
                double minimum;
                int i, index;
                double a1, b1, c1, d1, a2, b2, c2, d2, sum;
                for(i=0; i<6; i++)
                {
                    a1=(360 - y4[i]);
                    b1=(x4[i] - 500);
                    c1=500*y4[i] - 360*x4[i];
                    d1=fabs(a1*dx + b1*dy + c1)/(sqrt(a1*a1 + b1*b1));

                    a2=(360 - y4[i+1]);
                    b2=(x4[i+1] - 500);
                    c2=500*y4[i+1] - 360*x4[i+1];
                    d2=fabs(a2*dx + b2*dy + c2)/(sqrt(a2*a2 + b2*b2));

                    sum = d1 + d2;

                    if(i==0)
                    {
                        minimum = sum;
                        index = i;
                    }
                    else
                    {
                        if (sum < minimum)
                        {
                            minimum = sum;
                            index = i;
                        }
                    }

                }
                if(index == 0)
                {
                    score = score_calculation(160);
                }
                if(index == 1)
                {
                    score = score_calculation(170);
                }
                if(index == 2)
                {
                    score = score_calculation(180);
                }
                if(index == 3)
                {
                    score = score_calculation(190);
                }
                if(index == 4)
                {
                    score = score_calculation(200);
                }
            }

            countAttempt++;
            printf("Your score for the %dth attempt: %d\n",countAttempt, score);
            itoa(score, score_string, 10);
            total = total + score;
            itoa(total, total_string, 10);
            if(countAttempt == 3)
            {
                printf("Total score is %d\n", total);

                FILE *fq = fopen("name_score.txt", "rb");

                char name[30];
                int scr;
                int mx = 0;
                bool flag = false;
                while(fscanf(fq, "%s %d", name, &scr) == 2)
                {
                    if(strcmp(name, str2) == 0)
                    {
                        flag = true;
                        if(mx < scr)mx = scr;
                    }
                }


                if(total > mx)
                {
                    strcpy(personal_high, "This is your personal new high score");
                    printf("This is your personal new high score");
                }
                else
                {
                    if(flag)
                    {
                        strcpy(personal_high, "This is not your personal new high score");
                        printf("this is not your personal new high score");
                    }
                    else
                    {
                        strcpy(personal_high, "This is your personal new high score");
                        printf("This is your personal new high score");
                    }
                }

                fclose(fq);

                fq = fopen("name_score.txt", "a");
                fprintf(fq, "%s : %d\n", str2, total);






                FILE *fp;
                fp = fopen("highest.txt", "rb");
                int highestScore = 0;
                fscanf(fp, "%d", &highestScore);

                if(total > highestScore)
                {
                    printf("This is the new highest score.\n");
                    strcpy(highest_score, "This is the new highest score. CONGRATULATION !!!");


                    fclose(fp);
                    fp = fopen("highest.txt", "wb");
                    fprintf(fp, "%d", total);
                }
                else
                {
                    strcpy(highest_score, "This is not Highest score.");
                    strcpy(thanks, "Thanks for Playing");
                }
                strcpy(quit_game, "Press 'q' to quit.");
            }
        }
    }
    if(key=='r')
    {
        iResumeTimer(0);
    }
    //place your codes for other keys here
    if(mode == 1)
    {
        if(key == '\r')
        {
            mode = 0;
            strcpy(str2, str);
            printf("%s\n", str2);

            e++;
        }
        else
        {
            str[len] = key;
            len++;
        }
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}

void positionChange()
{
    dx = 500 + (rand() % 500)-200;
    dy = 360 + (rand() % 500)-200;

    int x = 500 - dx;
    int y = 360 - dy;
    if(x * x + y * y > (r - 1) * (r - 1))positionChange();
}

int main()
{
    iSetTimer(200, positionChange);
    len = 0;
    mode = 0;
    str[0]= 0;
    iInitialize(1300, 720, "DART POINTER!!! THIS IS OUR FIRST PROJECT ");
    return 0;
}

