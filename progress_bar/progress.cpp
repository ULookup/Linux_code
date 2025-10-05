#include "progress.h"
#include <string.h>
#include <unistd.h>


#define length 101
#define LABLE '#'
void FlushProgress(double target,double current)
{
  //step 0: 定义光标
  const char* sym = "|/-\\";
  static int index = 0;
  static int len = strlen(sym);
  //step 1: 更新进度
  double rate = (current / target)*100;
  //step 2: 整数个进度递增，刷新一个#
  int cnt = (int)rate;
  //step 3: 构建缓冲区
  char bar[length];
  memset(bar,0,sizeof(bar));
  for(int i = 0; i < cnt; i++)
    bar[i] = LABLE;
  //step 4: 刷新
  printf("[%-100s][%.1lf%%][%c]\r",bar,rate,sym[index++]);
  index %= len;
  fflush(stdout);
  //step 5: 处理100%情况
  if(rate>=100.0)
    printf("\n");
}
////version 1
//void progress()
//{
//  const char* symb = "|/-\\";
//  int s_len = strlen(symb);
//  char bar[length];
//  memset(bar,'\0',sizeof(bar));
//  int cnt = 0;
//  while(cnt<=100)
//  {
//    printf("[%-100s][%d%%][%c]\r",bar,cnt,symb[cnt%s_len]);
//    fflush(stdout);
//    bar[cnt++] = LABLE;
//    usleep(50000);
//  }
//  printf("\n");
//}
