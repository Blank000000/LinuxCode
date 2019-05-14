#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int x;
  for(x = 0; x < 10; x++){
    //输出100以内的随机数
    printf("%d\n", rand_X(100));
  }
}

int rand_X(int x){
  return rand() % x;
}
