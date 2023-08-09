/*----------------------------------------------------------------
AUTHOR: spexcher
Name: Gourab Modak
email: gm2623@cse.jgec.ac.in
Institution: Jalpaiguri Government Engineering College (B. Tech UG CSE 4 year)
Github: https://github.com/gauravthedeveloper/
linkedin : https://www.linkedin.com/in/gourabmodak/
codeforces : https://codeforces.com/profile/sectumsempra07/
codechef : https://www.codechef.com/users/sectumsempra07/
leetcode : https://leetcode.com/sectumsempra07/
--------------------------------------------------------------------
*/
#include <stdio.h>

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <time.h>
int main()
{
    int gm, gd = DETECT, i;
    int h, m, s, f;
    char str[256];

    long currentTime;

    char data[] = "C:\\TDM-GCC-32\\lib\\libbgi.a"; // static file
    initgraph(&gd, &gm, data);
    while (!kbhit())
    {
        cleardevice();
        currentTime = time(NULL);
        strcpy(str, ctime(&currentTime));
        setcolor(GREEN);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
        outtextxy(getmaxx() / 3, getmaxy() / 3, str);
        delay(1000);
    }

    // draw
    getch();
    closegraph();

    return 0;
}
