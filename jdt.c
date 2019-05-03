#nclude<stdio.h>
#include<unistd.h>

int main()
{
  int i = 0;
  char bar[102] = "#";
  const char *lable="|/-\\";
  while(i <= 100 ){
    printf("[%d%%][%c][%s]\r", i, lable[i%4], bar);
    fflush(stdout);
    bar[i++] = '#';
    usleep(1000000);
  } 
  return 0;
}
