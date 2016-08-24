#include<stdio.h>  
#include <sys/types.h>
typedef struct
{
	unsigned short bfType;
	unsigned int bfileSize;
	unsigned int bfReserved;
	unsigned int bOffBits;
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount; // глубина цвета
	unsigned int biCompression;
	unsigned int biSizeImage;
	unsigned int biXPelsPerMeter;
	unsigned int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
} bmp_header_t;
typedef struct
{
	bmp_header_t header;
	char *data;
} bmp_t;
int main(void)  
{  
  const  char *InputName, *OutputName;
  InputName = "input.bmp"; OutputName = "output.bmp";
  FILE *InputFile, *OutputFile;
  bmp_t *bmp = NULL, *blur = NULL;
  if (!(InputFile=fopen(InputName, "r")))
	{
		printf("File not found\n");
		return 1;
	}
  printf("Hello, world!\n");  
  return 0;  
}  
