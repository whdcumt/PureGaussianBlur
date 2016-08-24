#include<stdio.h>  
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
  printf("int占%d位\n",sizeof(int));
  printf("short占%d位\n",sizeof(short));
  printf("long占%d位\n",sizeof(long));
  printf("long long占%d位\n",sizeof(long long));
  printf("long double占%d位\n",sizeof(long double));
  return 0;  
}  
