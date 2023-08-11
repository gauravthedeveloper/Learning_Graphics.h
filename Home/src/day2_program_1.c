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
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void triangleRotate(int xx1, int xx2, int xx3, int yy1, int yy2, int yy3, int angle = 0)
{
    int cx = (int)(xx1 + xx2 + xx3) / 3;
    int cy = (int)(yy1 + yy2 + yy3) / 3;
    double theta = (double)(angle % 180) * M_PI / 180;
    // xx1 = xx1 - cx;

    xx1 = (xx1 * cos(theta) - yy1 * sin(theta));
    xx2 = (xx2 * cos(theta) - yy2 * sin(theta));
    xx3 = (xx3 * cos(theta) - yy3 * sin(theta));

    yy1 = (yy1 * cos(theta) + xx1 * sin(theta));
    yy2 = (yy2 * cos(theta) + xx2 * sin(theta));
    yy3 = (yy3 * cos(theta) + xx3 * sin(theta));
    cleardevice();
    // line for xx1, yy1, xx2, yy2
    line(xx1, yy1, xx2, yy2);

    // line for xx1, yy1, xx2, yy2
    line(xx1, yy1, xx3, yy3);

    // line for x1, y1, xx2, yy2
    line(xx2, yy2, xx3, yy3);
}
void rectangleRotate(int cx, int cy, int w, int h, int angle = 0)
{

    double theta = (double)(angle % 180) * M_PI / 1800;
    int dx = w / 2;
    int dy = h / 2;

    int point[8] = {
        (int)(-dx * cos(theta) - dy * sin(theta) + cx),
        (int)(-dx * sin(theta) + dy * cos(theta) + cy),
        (int)(dx * cos(theta) - dy * sin(theta) + cx),
        (int)(dx * sin(theta) + dy * cos(theta) + cy),
        (int)(dx * cos(theta) + dy * sin(theta) + cx),
        (int)(dx * sin(theta) - dy * cos(theta) + cy),
        (int)(-dx * cos(theta) + dy * sin(theta) + cx),
        (int)(-dx * sin(theta) - dy * cos(theta) + cy)};

    for (int i = 0; i < 8; i += 2)
        line(point[i], point[i + 1], point[(i + 2) % 8], point[(i + 3) % 8]);
}
int main()
{
    int choice, innerchoice = 0;
    double angle, theta;
    int dx, dy, cx, cy;
    int point[8];
    printf("What do you want to draw\n1:Circle\n2:Rectangle\n3:Triangle\n");
    scanf("%d", &choice);
    int x = 0, y = 0, radius = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    switch (choice)
    {
        {
        case 1:
            printf("Input three integers being coordinates of x and y and the radius\n");

            scanf("%d", &x);
            scanf("%d", &y);
            scanf("%d", &radius);
            break;
        case 2:
            printf("input 4 integers being coordinates of top left and bottom right of rectangle\n");

            scanf("%d", &x1);
            scanf("%d", &y1);
            scanf("%d", &x2);
            scanf("%d", &y2);

            break;
        case 3:
            printf("input 6 integers being coordinates of the triangle\n");

            scanf("%d", &x1);
            scanf("%d", &y1);
            scanf("%d", &x2);
            scanf("%d", &y2);
            scanf("%d", &x3);
            scanf("%d", &y3);

            break;
        default:
            break;
        }
    }
    int gm, gd = DETECT, i;
    char data[] = "C:\\TDM-GCC-32\\lib\\libbgi.a"; // static file
    int scalingFactor, scalingFactorX_triangle, scalingFactorY_triangle;
    initgraph(&gd, &gm, data);
    if (choice == 1)
    {
        circle(x, y, radius);

        printf("Enter \n1 to scale with an entered factor\n2 to translate in x direction \n3 to translate in y direction and \n4 if you are satisfied\n");
        scanf("%d", &innerchoice);
        switch (innerchoice)
        {
        case 1:
            printf("Enter the scaling factor(integer)>1\n");

            scanf("%d", &scalingFactor);
            cleardevice();

            circle(x, y, scalingFactor * radius);

            break;
        case 2:
            printf("Enter the slide amount(integer positive or negative)\n");

            scanf("%d", &scalingFactor);
            cleardevice();

            circle(x + scalingFactor, y, radius);
            break;
        case 3:
            printf("Enter the slide amount(integer positive or negative)\n");

            scanf("%d", &scalingFactor);
            cleardevice();

            circle(x, y + scalingFactor, radius);
            break;
        default:
            break;
        }
    }
    else if (choice == 2)
    {

        rectangle(x1, y1, x2, y2);
        printf("Enter \n1 to scale with an entered factor\n2 to translate in x direction \n3 to translate in y direction and \n4 Rotate it by an angle you enter as input\n5 if you are satisfied with the output\n");
        scanf("%d", &innerchoice);
        switch (innerchoice)
        {
        case 1:
            printf("Enter the scaling factor(integer)>1\n");

            scanf("%d", &scalingFactor);

            cleardevice();

            rectangle(x1 - (((x2 - x1) / 2) * scalingFactor), y1 - (((y2 - y1) / 2) * scalingFactor), x2 + (((x2 - x1) / 2) * scalingFactor), y2 + (((y2 - y1) / 2) * scalingFactor));
            break;
        case 2:
            printf("Enter the slide amount(integer positive or negative)\n");

            scanf("%d", &scalingFactor);
            cleardevice();

            rectangle(x1 + scalingFactor, y1, x2 + scalingFactor, y2);
            break;
        case 3:
            printf("Enter the slide amount(integer positive or negative)\n");

            scanf("%d", &scalingFactor);
            cleardevice();

            rectangle(x1, y1 + scalingFactor, x2, y2 + scalingFactor);
            break;
        case 4:
            printf("Enter the angle of rotation\n");

            scanf("%lf", &angle);
            // theta = (double)(angle % 180.0) * M_PI / 180;
            dx = (x2 - x1) / 2;
            dy = (y2 - y1) / 2;
            cx = (x1 + x2) / 2;
            cy = (y1 + y2) / 2;
            cleardevice();
            rectangleRotate(cx, cy, abs(x2 - x1), abs(y2 - y1), angle);

        default:
            break;
        }
    }
    else if (choice == 3)
    {

        // line for x1, y1, x2, y2
        line(x1, y1, x2, y2);

        // line for x1, y1, x2, y2
        line(x1, y1, x3, y3);

        // line for x1, y1, x2, y2
        line(x2, y2, x3, y3);
        printf("Enter \n1 to scale with an entered factor\n2 to translate in x direction \n3 to translate in y direction and \n4 Rotate it by an angle you enter as input\n5 if you are satisfied with the output\n");
        scanf("%d", &innerchoice);
        switch (innerchoice)
        {
        case 1:
            printf("Enter the scaling factor(integer)>1 for both x and y\n");

            scanf("%d", &scalingFactorX_triangle);
            scanf("%d", &scalingFactorY_triangle);
            x3 = x3 * scalingFactorX_triangle;
            x1 = x1 * scalingFactorX_triangle;
            x2 = x2 * scalingFactorX_triangle;
            y3 = y3 * scalingFactorY_triangle;
            y1 = y1 * scalingFactorY_triangle;
            y2 = y2 * scalingFactorY_triangle;
            cleardevice();
            // line for x1, y1, x2, y2
            line(x1, y1, x2, y2);

            line(x1, y1, x3, y3);

            // line for x1, y1, x2, y2
            line(x2, y2, x3, y3);
            break;
        case 2:
            printf("Enter the slide amount(integer positive or negative)\n");
            scanf("%d", &scalingFactorX_triangle);
            x3 = x3 + scalingFactorX_triangle;
            x1 = x1 + scalingFactorX_triangle;
            x2 = x2 + scalingFactorX_triangle;

            cleardevice();
            // line for x1, y1, x2, y2
            line(x1, y1, x2, y2);

            // line for x1, y1, x2, y2
            line(x1, y1, x3, y3);

            line(x2, y2, x3, y3);
            break;
        case 3:
            printf("Enter the slide amount(integer positive or negative)\n");
            scanf("%d", &scalingFactorX_triangle);
            y3 = y3 + scalingFactorX_triangle;
            y1 = y1 + scalingFactorX_triangle;
            y2 = y2 + scalingFactorX_triangle;

            cleardevice();

            line(x1, y1, x2, y2);

            line(x1, y1, x3, y3);

            // line for x1, y1, x2, y2
            line(x2, y2, x3, y3);
            break;
        case 4:
            printf("Enter the angle of rotation\n");

            scanf("%lf", &angle);
            triangleRotate(x1, x2, x3, y1, y2, y3, angle);
            break;

        default:
            break;
        }
    }
    getch();
    closegraph();

    return 0;
}
