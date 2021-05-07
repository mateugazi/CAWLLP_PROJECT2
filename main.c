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

    struct tagBITMAPFILEHEADER header;
    struct tagBITMAPINFOHEADER info;

    if(file != NULL){
        fread(&header.bfType, 2, 1, file);
        printf("bfSize: %c%c", header.bfType[0], header.bfType[1]);
        fread(&header.bfSize, 4, 1, file);
        printf("\n");
        printf("bfSize: ");
        printf("%" PRIu32, header.bfSize);
        fread(&header.bfReserved1, 2, 1, file);
        printf("\n");
        printf("bsReserved1: ");
        printf("%"PRIu16, header.bfReserved1);
        fread(&header.bfReserved2, 2, 1, file);
        printf("\n");
        printf("bsReserved2: ");
        printf("%"PRIu16, header.bfReserved2);
        fread(&header.bfOffBits, 4, 1, file);
        printf("\n");
        printf("bfOffBits: ");
        printf("%" PRIu32, header.bfOffBits);

    } else {
        printf("Wrong file");
    }
    return 0;
}
