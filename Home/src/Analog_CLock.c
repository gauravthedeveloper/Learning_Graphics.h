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
#include <string.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

void calcPoints(int radius, int midx, int midy, int x[12], int y[12])
{
    int x1, y1;

    x[0] = midx, y[0] = midy - radius;
    x[6] = midx, y[6] = midy + radius;
    x[3] = midx + radius, y[3] = midy;
    x[9] = midx - radius, y[9] = midy;

    x1 = (int)((radius / 2) * sqrt(3));
    y1 = (radius / 2);
    x[2] = midx + x1, y[2] = midy - y1;
    x[4] = midx + x1, y[4] = midy + y1;
    x[8] = midx - x1, y[8] = midy + y1;
    x[10] = midx - x1, y[10] = midy - y1;

    x1 = radius / 2;
    y1 = (int)((radius / 2) * sqrt(3));
    x[1] = midx + x1, y[1] = midy - y1;
    x[5] = midx + x1, y[5] = midy + y1;
    x[7] = midx - x1, y[7] = midy + y1;
    x[11] = midx - x1, y[11] = midy - y1;

    return;
}

void minSecCalc(int radius, int midx, int midy, int secx[60], int secy[60])
{
    int i, j = 0, x, y;
    char str[32];

   
    secx[j] = midx, secy[j++] = midy - radius;

    for (i = 96; i < 180; i = i + 6)
    {
        secx[j] = midx - (radius * cos((i * 3.14) / 180));
        secy[j++] = midy - (radius * sin((i * 3.14) / 180));
    }

 
    secx[j] = midx + radius, secy[j++] = midy;
    for (i = 186; i < 270; i = i + 6)
    {
        secx[j] = midx - (radius * cos((i * 3.14) / 180));
        secy[j++] = midy - (radius * sin((i * 3.14) / 180));
    }

  
    secx[j] = midx, secy[j++] = midy + radius;
    for (i = 276; i < 360; i = i + 6)
    {
        secx[j] = midx - (radius * cos((i * 3.14) / 180));
        secy[j++] = midy - (radius * sin((i * 3.14) / 180));
    }

  
    secx[j] = midx - radius, secy[j++] = midy;
    for (i = 6; i < 90; i = i + 6)
    {
        secx[j] = midx - (radius * cos((i * 3.14) / 180));
        secy[j++] = midy - (radius * sin((i * 3.14) / 180));
    }

    return;
}

int main()
{
   
    int gdriver = DETECT, gmode, err, tmp;
    int i, j, midx, midy, radius, hr, min, sec;
    int x[12], y[12], minx[60], miny[60];
    int hrx[12], hry[12], secx[60], secy[60];
    int secx1, secy1;
    char str[256];
    time_t t1;
    struct tm *data;

  
    char dataaa[] = "C:\\TDM-GCC-32\\lib\\libbgi.a"; // static file
    initgraph(&gdriver, &gmode, dataaa);
    err = graphresult();

    if (err != grOk)
    {
       
        printf("Graphics Error: %s",
               grapherrormsg(err));
        return 0;
    }

  
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    radius = 200;

  
    calcPoints(radius - 30, midx, midy, x, y);


    calcPoints(radius - 90, midx, midy, hrx, hry);

    
    minSecCalc(radius - 50, midx, midy, minx, miny);

   
    minSecCalc(radius - 70, midx, midy, secx, secy);

    while (!kbhit())
    {
        setlinestyle(SOLID_LINE, 1, 3);
        settextstyle(TRIPLEX_FONT, 0, 3);

      
        circle(midx, midy, radius);

       
        for (j = 0; j < 12; j++)
        {
            if (j == 0)
            {
                sprintf(str, "%d", 12);
            }
            else
            {
                sprintf(str, "%d", j);
            }
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            moveto(x[j], y[j]);
            outtext(str);
        }

       
        t1 = time(NULL);
        data = localtime(&t1);

        
        sec = data->tm_sec % 60;
        line(midx, midy, secx[sec], secy[sec]);

      
        min = data->tm_min % 60;
        line(midx, midy, minx[min], miny[min]);

       
        hr = data->tm_hour % 12;
        line(midx, midy, hrx[hr], hry[hr]);

      
        delay(1000);
        cleardevice();
    }

    getch();

  
    closegraph();
    return 0;
}