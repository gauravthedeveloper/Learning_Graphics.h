#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <math.h>

void drawAnalogClock(int centerX, int centerY, int radius, int hour, int minute, int second)
{
    int endX, endY;
    float angle;

    // Draw clock face
    setcolor(YELLOW);
    circle(centerX, centerY, radius);
    circle(centerX, centerY, radius + 5);

    // Draw clock hands
    // Hour hand

    angle = ((hour % 12 + minute / 60.0) * (360.0 / 12.0) - 90.0) * (3.14159 / 180.0);
    endX = centerX + (int)(0.4 * radius * cos(angle));
    endY = centerY + (int)(0.4 * radius * sin(angle));
    setcolor(3);
    line(centerX, centerY, endX, endY);

    // Minute hand
    setcolor(10);
    angle = ((minute + second / 60.0) * (360.0 / 60.0) - 90.0) * (3.14159 / 180.0);
    endX = centerX + (int)(0.6 * radius * cos(angle));
    endY = centerY + (int)(0.6 * radius * sin(angle));
    line(centerX, centerY, endX, endY);

    // Second hand
    setcolor(12);
    angle = (second * (360.0 / 60.0) - 90.0) * (3.14159 / 180.0);
    endX = centerX + (int)(0.6 * radius * cos(angle));
    endY = centerY + (int)(0.6 * radius * sin(angle));
    line(centerX, centerY, endX, endY);
}

void drawDigitalClock(int x, int y, int hour, int minute, int second)
{
    char timeStr[9]; // HH:MM:SS\0
    sprintf(timeStr, "%02d:%02d:%02d", hour, minute, second);

    setcolor(13);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(x, y, timeStr);
}

int main()
{
    int gdriver = DETECT, gmode;
    char dataaa[] = "C:\\TDM-GCC-32\\lib\\libbgi.a"; // static file
    initgraph(&gdriver, &gmode, dataaa);

    int centerX = getmaxx() / 4;
    int centerY = getmaxy() / 2;
    int radius = 100;

    int setByUser = 0; // 0 for system clock, 1 for manual
    int hour = 0, minute = 0, second = 0;

    int choice;
    printf("Menu:\n");
    printf("1. Set time manually\n");
    printf("2. Use system time\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter hour (0-23): ");
        scanf("%d", &hour);
        printf("Enter minute (0-59): ");
        scanf("%d", &minute);
        printf("Enter second (0-59): ");
        scanf("%d", &second);
        setByUser = 1;
    }

    while (!kbhit())
    {
        cleardevice();
        setcolor(10);
        settextstyle(10, HORIZ_DIR, 3);
        char c[] = "Analog and Digital Clock By Gourab";
        outtextxy(100, 70, c);
        char c2[] = "24-Hour Clock";
        outtextxy(330, 280, c2);
        if (!setByUser)
        {
            // Get the current time
            time_t currentTime = time(NULL);
            struct tm *localTime = localtime(&currentTime);
            hour = localTime->tm_hour;
            minute = localTime->tm_min;
            second = localTime->tm_sec;
        }

        // Draw the analog clock
        setcolor(RED);
        drawAnalogClock(centerX, centerY, radius, hour, minute, second);
        setcolor(11);
        // Draw the digital clock
        drawDigitalClock(centerX * 2 + 50, centerY, hour, minute, second);

        delay(1000); // Sleep for 1 second
    }

    closegraph();
    return 0;
}
