/// <summary>  
/// 程序功能：c语言实现纯高斯模糊
/// 系统Ubuntu 15.10，编程语言C,最新整理时间 2016.8.25。  
/// </summary> 
#include<stdio.h>  
#include <stdlib.h>
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
//读取bmp图像函数
int ReadBmp(const char* szFileName);
//定义全局变量
//定义一个位图信息头结构体对象
  BITMAPINFOHEADER bih;
//定义指针变量Buffer，用于存储图像数据
  BYTE *Buffer = NULL;
//定义一行图像素数据的所有字节个数
long LineByteWidth;
int main(void)  
{  
  const  char *InputName, *OutputName;
  InputName = "input.bmp"; OutputName = "output.bmp";
  if (ReadBmp(InputName) == 0)
  {
	   printf("failure to read file %s",  InputName);
	   return 1;
  }
  printf("Width: %ld\n", bih.biWidth);
  printf("Height: %ld\n", bih.biHeight);
  printf("BitCount: %d\n\n", (int)bih.biBitCount);
  free(Buffer);
  return 0;  
}  
/// <summary>  
/// 函数功能实现读取bmp图像
/// </summary>  
/// <param name="szFileName">图像文件的路径</param>        
int ReadBmp(const char* szFileName)
{
	//文件状态变量
        FILE *file;
        //定义大小为7的数组，用于后面的存储
	//WORD bfh[7];
	long dpixeladd;
        //读取图像文件失败，返回0
	if (NULL == (file = fopen(szFileName, "rb")))
	{
	   return 0;
	}
        //读取成功后，输出图像路径
	printf("%s\n", szFileName);
        //读取7个WORD的数据到数组中
	//fread(&bfh, sizeof(WORD), 7, file);
        //判断数组中的第一个元素是不是BM，详见说明文档
	//if (bfh[0] != (WORD)(((WORD)'B')|('M'<<8)))
	//{
	//   fclose(file);
	//   return 0;
	//}
        //如果前面确定是bmp图像，则读取位图信息头数据
	fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);
        //如果不是24位的bmp图像则退出
	if (bih.biBitCount < 24)
	{
	   fclose(file);
	   return 0;
	}
        //几个通道？一般bih.biBitCount = 24，该值为3
	dpixeladd = bih.biBitCount / 8;
        //一行的跨度
	LineByteWidth = bih.biWidth * (dpixeladd);
        //使该宽度值能被4整出
	if ((LineByteWidth % 4) != 0)
	LineByteWidth += 4 - (LineByteWidth % 4);
        //开辟新的内存，存储颜色值
	if ((Buffer = (BYTE*)malloc(sizeof(BYTE)* LineByteWidth * bih.biHeight)) != NULL)
	{
	   fread(Buffer, LineByteWidth * bih.biHeight, 1, file);
	   fclose(file);
	   return 1;
	}
        //关闭文件
	fclose(file);
	return 0;
}

