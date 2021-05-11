#include <math.h>
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
    FILE *file = fopen(argv[1], "rb");
    FILE *outfile;
    if(argv[2]!= NULL) outfile = fopen(argv[2], "wb");
    struct tagBITMAPFILEHEADER headerFile;
    struct tagBITMAPINFOHEADER headerInfo;

    if(file != NULL){
        fread(&headerFile.bfType, 2, 1, file);
        if(argv[2]!= NULL)fwrite(&headerFile.bfType, 2, 1, outfile);
        fread(&headerFile.bfSize, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerFile.bfSize, 4, 1, outfile);
        fread(&headerFile.bfReserved1, 2, 1, file);
        if(argv[2]!= NULL)fwrite(&headerFile.bfReserved1, 2, 1, outfile);
        fread(&headerFile.bfReserved2, 2, 1, file);
        if(argv[2]!= NULL)fwrite(&headerFile.bfReserved2, 2, 1, outfile);
        fread(&headerFile.bfOffBits, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerFile.bfOffBits, 4, 1, outfile);

        fread(&headerInfo.biSize, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biSize, 4, 1, outfile);
        fread(&headerInfo.biWidth, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biWidth, 4, 1, outfile);
        fread(&headerInfo.biHeight, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biHeight, 4, 1, outfile);
        fread(&headerInfo.biPlanes, 2, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biPlanes, 2, 1, outfile);
        fread(&headerInfo.biBitCount, 2, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biBitCount, 2, 1, outfile);
        fread(&headerInfo.biCompression, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biCompression, 4, 1, outfile);
        fread(&headerInfo.biSizeImage, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biSizeImage, 4, 1, outfile);
        fread(&headerInfo.biXPelsPerMeter, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biXPelsPerMeter, 4, 1, outfile);
        fread(&headerInfo.biYPelsPerMeter, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biYPelsPerMeter, 4, 1, outfile);
        fread(&headerInfo.biClrUsed, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biClrUsed, 4, 1, outfile);
        fread(&headerInfo.biClrImportant, 4, 1, file);
        if(argv[2]!= NULL)fwrite(&headerInfo.biClrImportant, 4, 1, outfile);


        printf("BITMAPFILEHEADER: \n");
        printf("bfType: \t%c%c", headerFile.bfType[0], headerFile.bfType[1]);
        printf("\n");
        printf("bfSize: \t");
        printf("%" PRIu32, headerFile.bfSize);
        printf("\n");
        printf("bsReserved1: \t");
        printf("%"PRIu16, headerFile.bfReserved1);
        printf("\n");
        printf("bsReserved2: \t");
        printf("%"PRIu16, headerFile.bfReserved2);
        printf("\n");
        printf("bfOffBits: \t");
        printf("%" PRIu32, headerFile.bfOffBits);

        printf("\n\n");
        printf("BITMAPINFOHEADER: \n");
        printf("biSize: \t");
        printf("%"PRIu32, headerInfo.biSize);
        printf("\n");
        printf("biWidth: \t");
        printf("%d", headerInfo.biWidth);
        printf("\n");
        printf("biHeight: \t");
        printf("%d", headerInfo.biHeight);
        printf("\n");
        printf("biPlanes: \t");
        printf("%"PRIu16, headerInfo.biPlanes);
        printf("\n");
        printf("biBitCount: \t");
        printf("%"PRIu16, headerInfo.biBitCount);
        printf("\n");
        printf("biCompression: \t");
        printf("%"PRIu32, headerInfo.biCompression);
        printf("\n");
        printf("biSizeImage: \t");
        printf("%"PRIu32, headerInfo.biSizeImage);
        printf("\n");
        printf("biXPelsPerMeter: \t");
        printf("%d", headerInfo.biXPelsPerMeter);
        printf("\n");
        printf("biYPelsPerMeter: \t");
        printf("%d", headerInfo.biYPelsPerMeter);
        printf("\n");
        printf("biClrUsed: \t");
        printf("%"PRIu32, headerInfo.biClrUsed);
        printf("\n");
        printf("biClrImportant: \t");
        printf("%"PRIu32, headerInfo.biClrImportant);
        printf("\n");
    } else {
        printf("Wrong file\n");
    }
    if(headerInfo.biCompression==0 && headerInfo.biBitCount == 24)
    {


        int rowLength = (headerInfo.biBitCount*headerInfo.biWidth+31) / 32;
        rowLength *=4;
        int rowToProcess = headerInfo.biWidth*3;
        int rgb [3][16];
        for (int j = 0; j < 16; ++j) {
            rgb[0][j]=0;
            rgb[1][j]=0;
            rgb[2][j]=0;
        }
        unsigned char ffs [rowLength];
        fread(ffs, 1, rowLength,file);

        printf("\n");
        printf("%i", rowLength);
        printf("\n");
        if(argv[2]!= NULL)fwrite(ffs, 1, rowLength,outfile);
        for(int i=0;i<headerInfo.biHeight;i++)
        {
            unsigned char row [rowLength];
            unsigned char greyRow [rowLength];
            for (int j = 0; j < rowLength; ++j) {
                greyRow[j]=0;
            }
            fread(row, 1, rowLength,file);

            for (int j = 0; j < rowToProcess; j+=3) {
                rgb[0][row[j] / 16]++;
                rgb[1][row[j + 1] / 16]++;
                rgb[2][row[j + 2] / 16]++;
                int avg = (row[j]+row[j+1]+row[j+2])/3;
                greyRow[j]=avg;
                greyRow[j+1]=avg;
                greyRow[j+2]=avg;
            }
            if(argv[2]!= NULL)fwrite(greyRow, 1, rowLength,outfile);
        }
        float div = rowToProcess/3*headerInfo.biHeight/100;
        printf("Red:\n");
        for (int i = 0; i < 16; ++i) {
            printf("%d-%d: %2.2f%%\n",i*16,i*16+15,rgb[0][i]/div);
        }
        printf("Green:\n");
        for (int i = 0; i < 16; ++i) {
            printf("%d-%d: %2.2f%%\n",i*16,i*16+15,rgb[1][i]/div);
        }
        printf("Blue:\n");
        for (int i = 0; i < 16; ++i) {
            printf("%d-%d: %2.2f%%\n",i*16,i*16+15,rgb[2][i]/div);
        }

//        for(int j = 0; j < rowLength; j++) {
//         //   printf("%u ", ffs[j]);
//            if ((j+1) %8 == 0) printf("\n");
//        }

    printf("\n");
        if(argv[3] != NULL) {
            fclose(outfile);
            outfile = fopen(argv[2], "r+b");
            fseek ( outfile , headerFile.bfOffBits , SEEK_SET );
            char *message = NULL;
            message = malloc(sizeof(argv[3]) * sizeof(char));
            strcpy(message, argv[3]);
            int messageLength = strlen(message);
            //printf("%s", message);
            //printf("%i", messageLength);


            for(int i = 0; i < messageLength; i++) {

                unsigned char tmp = 0;
                unsigned char *x = &tmp;



                for (int k = 0; k<8;k++) {
                        fread(x, 1, sizeof(unsigned char),outfile);

                        unsigned char f = ((message[i] & ( 1 << k )) >> k);
                        f = f | 254;
                       //printf("%d ",f);
                        fseek ( outfile , headerFile.bfOffBits +( i*8 + k) , SEEK_SET );
                        *x = *x&f;
                        fwrite(x, 1, sizeof(unsigned char),outfile);
                    }


            }

            printf("decode?");
            char answer;
            scanf("%s", &answer);
            if( answer == 'y') {
//                unsigned char arr[100];
//                fread(arr, sizeof (arr), 1,outfile);
//                printf("\n");
//                printf("%s", arr);
//                printf("\n");
                char decodedMessage[messageLength];
                for(int j = 0; j < messageLength; j++) {
                    decodedMessage[j] = 0;
                }

                decodedMessage[messageLength] = '\0';

                fclose(outfile);
                outfile = fopen(argv[2], "rb");
                fseek ( outfile , headerFile.bfOffBits, SEEK_SET );

                for(int i = 0; i < messageLength; i++) {
                    unsigned char tmp = 0;
                    unsigned char *x = &tmp;

                    char POTEGA=1;

                    for (int k = 0; k<8;k++) {
                        fread(x, 1, sizeof(unsigned char),outfile);
//                        unsigned char f = ((x & ( 1 << k )) >> k);
//                        f = f & 1;
                        *x = *x & 1;


                        decodedMessage[i] += *x * POTEGA;
                        POTEGA *=2;
                    }


                }
                printf("\n");
                printf("%i",messageLength);

                printf("\n");

                printf("%s", decodedMessage);
            }
        }

    } else{
        printf("histogram calculation is unsupported\n");
    }
    fclose(file);
    fclose(outfile);
    return 0;
}