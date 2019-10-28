#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *img = fopen("lena512.bmp", "rb"); //read the file

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, img); // read the 54-byte header
                                                   // extract image height and width from header
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = 0;
    printf("%dx%d original size\n", width, height);
    int crop_width, crop_height, h_choice;
    printf("\nEnter new width: ");
    scanf("%d", &crop_width);
    printf("\nEnter new height: ");
    scanf("%d", &crop_height);
    printf("\n1. Crop bottom\n2. Crop top\nEnter choice: ");
    scanf("%d", &h_choice);

    while ((width * 3 + padding) % 4 != 0)
        padding++;

    int widthnew = width * 3 + padding, original_h = height;
    unsigned char data[widthnew];

    FILE *new_img = fopen("new_img.bmp", "wb");
    header[22] = crop_height; // new height
                              //	header[18] -= 27; // new width

    fwrite(header, sizeof(unsigned char), 54, new_img);

    int i, limit;
    if (h_choice == 1)
    {
        i = 0;
        limit = crop_height;
    }
    else
    {
        i = original_h - crop_height;
        limit = original_h;
    }
    for (; i < limit; i++)
    {
        fread(data, sizeof(unsigned char), widthnew, img);
        fwrite(data, sizeof(unsigned char), sizeof(data), new_img);
    }

    fclose(new_img);
    fclose(img);

    return 0;
}
