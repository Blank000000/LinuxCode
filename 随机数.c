#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand((int)time(0));//使用系统时间作为随机种子
  
  int x;
  for(x = 0; x < 10; x++){
    //输出100以内的随机数
    printf("%d\n", rand_X(100));
  }
}

int rand_X(int x){
  return rand() % x;
}
