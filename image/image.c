#include <stdio.h>
#define THRESHOLD 128
#define WHITE 255
#define BLACK 0

int main()
{

    FILE *fIn = fopen("lena512.bmp", "r"); //Input File name
    FILE *fOut = fopen("b_w.bmp", "w+");   //Output File name

    int i;
    unsigned char byte[54];         //to get the image header
    unsigned char colorTable[1024]; //to get the colortable

    //To define colors used by the bitmap image data (Pixel array)
    //the number of bits per pixel, which is the color depth of  the   //image. Typical values are 1, 4, 8, 16, 24 and 32.

    if (fIn == NULL) // check if the input file has not been opened succesfully.
    {
        printf("File does not exist.\n");
    }

    for (i = 0; i < 54; i++) //read the 54 byte header from fIn
    {
        byte[i] = getc(fIn); //getc functions is used to read a character from a file
    }

    fwrite(byte, sizeof(unsigned char), 54, fOut); //write the header back

    // extract image height, width and bitDepth from imageHeader
    int height = *(int *)&byte[18];
    int width = *(int *)&byte[22];
    int bitDepth = *(int *)&byte[28];

    printf("width: %d\n", width);
    printf("height: %d\n", height);

    int size = height * width; //calculate image size

    if (bitDepth <= 8) //if ColorTable present, extract it.
    {
        fread(colorTable, sizeof(unsigned char), 1024, fIn);
        fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
    }

    unsigned char buffer[size]; //to store the image data

    fread(buffer, sizeof(unsigned char), size, fIn); //read image data

    for (i = 0; i < size; i++) //store 0(black) and 255(white) values to buffer
    {
        buffer[i] = (buffer[i] > THRESHOLD) ? WHITE : BLACK;
    }

    fwrite(buffer, sizeof(unsigned char), size, fOut); //write back to the output image

    fclose(fIn);
    fclose(fOut);

    return 0;
}