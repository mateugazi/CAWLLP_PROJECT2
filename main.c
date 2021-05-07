#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;

// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapfileheader
typedef struct tagBITMAPFILEHEADER {
    char  bfType[2];
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

// https://docs.microsoft.com/pl-pl/previous-versions/dd183376(v=vs.85)
typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    struct tagBITMAPFILEHEADER headerFile;
    struct tagBITMAPINFOHEADER headerInfo;

    if(file != NULL){
        fread(&headerFile.bfType, 2, 1, file);
        fread(&headerFile.bfSize, 4, 1, file);
        fread(&headerFile.bfReserved1, 2, 1, file);
        fread(&headerFile.bfReserved2, 2, 1, file);
        fread(&headerFile.bfOffBits, 4, 1, file);

        fread(&headerInfo.biSize, 4, 1, file);
        fread(&headerInfo.biWidth, 4, 1, file);
        fread(&headerInfo.biHeight, 4, 1, file);
        fread(&headerInfo.biPlanes, 2, 1, file);
        fread(&headerInfo.biBitCount, 2, 1, file);
        fread(&headerInfo.biCompression, 4, 1, file);
        fread(&headerInfo.biSizeImage, 4, 1, file);
        fread(&headerInfo.biXPelsPerMeter, 4, 1, file);
        fread(&headerInfo.biYPelsPerMeter, 4, 1, file);
        fread(&headerInfo.biClrUsed, 4, 1, file);
        fread(&headerInfo.biClrImportant, 4, 1, file);


        printf("BITMAPFILEHEADER: \n");
        printf("bfType: %c%c", headerFile.bfType[0], headerFile.bfType[1]);
        printf("\n");
        printf("bfSize: ");
        printf("%" PRIu32, headerFile.bfSize);
        printf("\n");
        printf("bsReserved1: ");
        printf("%"PRIu16, headerFile.bfReserved1);
        printf("\n");
        printf("bsReserved2: ");
        printf("%"PRIu16, headerFile.bfReserved2);
        printf("\n");
        printf("bfOffBits: ");
        printf("%" PRIu32, headerFile.bfOffBits);

        printf("\n\n");
        printf("BITMAPINFOHEADER: \n");
        printf("biSize: ");
        printf("%"PRIu32, headerInfo.biSize);
        printf("\n");
        printf("biWidth: ");
        printf("%d", headerInfo.biWidth);
        printf("\n");
        printf("biHeight: ");
        printf("%d", headerInfo.biHeight);
        printf("\n");
        printf("biPlanes: ");
        printf("%"PRIu16, headerInfo.biPlanes);
        printf("\n");
        printf("biBitCount: ");
        printf("%"PRIu16, headerInfo.biBitCount);
        printf("\n");
        printf("biCompression: ");
        printf("%"PRIu32, headerInfo.biCompression);
        printf("\n");
        printf("biSizeImage: ");
        printf("%"PRIu32, headerInfo.biSizeImage);
        printf("\n");
        printf("biXPelsPerMeter: ");
        printf("%d", headerInfo.biXPelsPerMeter);
        printf("\n");
        printf("biYPelsPerMeter: ");
        printf("%d", headerInfo.biYPelsPerMeter);
        printf("\n");
        printf("biClrUsed: ");
        printf("%"PRIu32, headerInfo.biClrUsed);
        printf("\n");
        printf("biClrImportant: ");
        printf("%"PRIu32, headerInfo.biClrImportant);
    } else {
        printf("Wrong file");
    }
    return 0;
}
