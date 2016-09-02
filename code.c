/// <summary>  
/// 程序功能：c语言实现纯高斯模糊
/// 系统Ubuntu 15.10，编程语言C,最新整理时间 2016.8.25。  
/// </summary> 
#include<stdio.h>  
#include<stdlib.h>
#include<malloc.h>
//自定义数据类型
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
//位图信息头结构体定义
//#pragma pack(push,2)
typedef struct tagBITMAPINFOHEADER
{
   WORD   bfType;
   DWORD  bfileSize;
   DWORD  bfReserved;
   DWORD  bOffBits;
   DWORD  biSize;
   long   biWidth;
   long   biHeight;
   WORD   biPlanes;
   WORD   biBitCount;
   DWORD  biCompression;
   DWORD  biSizeImage;
   long   biXPelsPerMeter;
   long   biYPelsPerMeter;
   DWORD biClrUsed;
   DWORD biClrImportant;
} __attribute__((packed))BITMAPINFOHEADER,*PBITMAPINFOHEADER;  
//#pragma pack(pop)
typedef struct
{
	BITMAPINFOHEADER header;
	char *data;
} bmp_t;
void bmp_free(bmp_t *);
bmp_t *bmp_open(FILE *);
int main(void)  
{  
        char *InputName, *OutputName;
	FILE *InputFile, *OutputFile;
	bmp_t *bmp = NULL, *blur = NULL;
        InputName = "input.bmp"; OutputName = "output.bmp";
        if(!(InputFile=fopen(InputName, "r")))  //图像文件打开
	{
		printf("File not found\n");
		return 1;
	}
        bmp = bmp_open(InputFile);   //图像文件读取
	fclose(InputFile);

}  
bmp_t *bmp_open(FILE *f) {
	bmp_t *bmp;
	bmp = (bmp_t *)malloc(sizeof(bmp_t));
	bmp->data = NULL;

	if (fread(&(bmp->header), sizeof(BITMAPINFOHEADER), 1, f)) {
		bmp->data = (char*)malloc(bmp->header.biSizeImage);
		if (fread(bmp->data, bmp->header.biSizeImage, 1, f))
                 printf("图像读取成功\n");
                 printf("Width: %ld\n", bmp->header.biWidth);
                 printf("Height: %ld\n", bmp->header.biHeight);
                 printf("BitCount: %d\n\n", (int)bmp->header.biBitCount);
			return bmp;
	}
	fprintf(stderr, "Error reading file");
	bmp_free(bmp);
	return NULL;
}
void bmp_free(bmp_t *bmp)
{
	if (bmp == NULL) return;
	if (bmp->data != NULL) free(bmp->data);
	free(bmp);
}
