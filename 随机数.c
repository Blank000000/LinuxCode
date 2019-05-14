#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand((int)time(0));//使用系统时间作为随机种子
  
  int temp = 1;
  int i;
  int x = 0;
  int y = 10;
  while(i <= 10){
    //输出10个100以内的随机数
    temp = rand() % (y - x + 1) + x;//生成[0,10]的所有随机数
    if(temp>10||temp<0){
      printf("错误！\n");
      break;
    }
    if(i == temp){
      printf("temp = %d\n",temp);
      i++;
    }
  }
}
