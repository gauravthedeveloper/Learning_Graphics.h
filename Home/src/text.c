#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <time.h>
void minSecPos(int xrad, int midx, int midy, int x[60], int y[60])
{
    int i, j = 45;
    for (i = 360; i >= 0; i = i - 6)
    {
        x[j] = midx - (xrad * cos((i * 3.14) / 180));
        y[j--] = midy - (xrad * sin((i * 3.14) / 180));
        j = (j == -1) ? 59 : j;
    }
    return;
}

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

int main()
{
    int gm, gd = DETECT, i;

    char data2[] = "C:\\TDM-GCC-32\\lib\\libbgi.a"; // static file
    initgraph(&gd, &gm, data2);
    int j, midx, midy, radius, hr, min, sec;
    int x[12], y[12], minx[60], miny[60];
    int hrx[12], hry[12], secx[60], secy[60];
    int secx1, secy1;
    char str[256];
    time_t t1;
    struct tm *data;

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    radius = 200;

    minSecPos(radius - 10, midx, midy, minx, miny);
    minSecPos(radius - 30, midx, midy, secx, secy);
    calcPoints(radius - 50, midx, midy, hrx, hry);

    while (!kbhit())
    {
        t1 = time(NULL);
        data = localtime(&t1);
        hr = data->tm_hour;
        min = data->tm_min;
        sec = data->tm_sec;

        setcolor(0);
        setfillstyle(1, 0);
        circle(midx, midy, radius);
        // floodfill(midx, midy, 0);

        setcolor(15);
        for (i = 0; i < 12; i++)
        {
            line(midx, midy, hrx[i], hry[i]);
        }

        setcolor(14);
        for (i = 0; i < 60; i++)
        {
            line(midx, midy, secx[i], secy[i]);
        }

        setcolor(12);
        for (i = 0; i < 60; i++)
        {
            line(midx, midy, minx[i], miny[i]);
        }

        setcolor(10);
        line(midx, midy, secx[sec], secy[sec]);

        setcolor(9);
        line(midx, midy, minx[min], miny[min]);

        setcolor(4);
        line(midx, midy, hrx[hr % 12], hry[hr % 12]);

        sprintf(str, "%02d:%02d:%02d", hr, min, sec);
        setcolor(15);
        outtextxy(midx - 40, midy + radius + 10, str);

        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}
