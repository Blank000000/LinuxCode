#include<stdio.h>
#include<math.h>


void menu()
{        
  printf("##################\n");
  printf("##1,add    2,sub##\n");       
  printf("##3,mul    2,div##\n");
  printf("##################\n");
}

int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}


int main()
{
  int x;  
  int y;
  int ret;
  int input = 1;

  while(input)
  {
    menu();
    printf("Please Select:");
    scanf("%d",&input);
    if(input > 0 && input < 5)
    {
      printf("cin num :");
      scanf("%d,%d",&x,&y);
    }
    switch(input)
    {
    case 1:
      ret = add(x, y);
      break;
    case 2:
      ret = sub(x, y);
      break;
    case 3:
      ret = mul(x, y);
      break;
    case 4:
      ret = div(x, y);
      break;
    case 0:
      printf("exit!\n");
      break;
    default:
      printf("earro!  Please try again!\n");
      break;
    }
    printf("%d\n",ret);
  }
}
