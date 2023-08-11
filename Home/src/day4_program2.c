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
// Write the PGM header for the negative image
void writePGMHeader(FILE *file, int width, int height, int maxValue)
{
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", maxValue);
}

void skipComments(FILE *file)
{
    int ch;
    while ((ch = fgetc(file)) == '#')
    {
        while ((ch = fgetc(file)) != '\n')
            ;
    }
    fseek(file, -1, SEEK_CUR); // Move back one character if it's not a comment character
}

//  Read the PGM header
void readPGMHeader(FILE *file, int *width, int *height, int *maxValue)
{
    char format[3];
    skipComments(file);
    fscanf(file, "%s", format);
    skipComments(file);
    fscanf(file, "%d", width);
    skipComments(file);
    fscanf(file, "%d", height);
    skipComments(file);
    fscanf(file, "%d", maxValue);
}

int main()
{
    char inputFileName[] = "input.pgm";
    char outputFileName[] = "output.pgm";
    FILE *inputFile, *outputFile;
    int width, height, maxValue;

    // Open the input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the PGM header
    readPGMHeader(inputFile, &width, &height, &maxValue);

    // Open the output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Write the PGM header for the negative image
    writePGMHeader(outputFile, width, height, maxValue);

    // Read the image data from the input file, convert to negative, and write to the output file
    for (int i = 0; i < width * height; i++)
    {
        int pixelValue;
        fscanf(inputFile, "%d", &pixelValue);
        // Calculate the negative of the pixel value
        int negativeValue = maxValue - pixelValue;
        fprintf(outputFile, "%d ", negativeValue);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Negative image created successfully.\n");
    return 0;
}
