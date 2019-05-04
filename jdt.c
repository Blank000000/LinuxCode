#nclude<stdio.h>
#include<unistd.h>
#define NONE "\e[0m"
#define RED  "\e[0;31m"
#define BLUE "\e[0;34m"

int main()
{
  int i = 0;
  char bar[102] = "#";
  const char *lable="|/-\\";
  while(i <= 100 ){
    if(i <= 25 || (i <= 75 && i>= 50))
    printf("RED[%d%%][%c][%s]\r",NONE, i, lable[i%4], bar);
    else
      printf("BLUE[%d%%][%c][%s]\r",NONE, i, lable[i%4], bar);
    fflush(stdout);
    i++;
    usleep(1000000);
  } 
  return 0;
}
