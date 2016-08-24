#include<stdio.h>  
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
int main(void)  
{  
  const  char *InputName, *OutputName;
  InputName = "input.bmp"; OutputName = "output.bmp";
  FILE *InputFile, *OutputFile;
  //bmp_t *bmp = NULL, *blur = NULL;
  printf("Hello, world!\n");  
  printf("%s\n",InputName);
  printf("%s\n",OutputName);
  printf("char占%d位\n",sizeof(char));
  printf("double占%d位\n",sizeof(double));
  printf("float占%d位\n",sizeof(float));
  printf("unsigned int占%d位\n",sizeof(unsigned int));
  printf("unsigned short占%d位\n",sizeof(unsigned short));
  printf("long占%d位\n",sizeof(long));
  printf("long long占%d位\n",sizeof(long long));
  printf("long double占%d位\n",sizeof(long double));
  return 0;  
}  
