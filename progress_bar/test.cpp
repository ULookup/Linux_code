#include"progress.h"
#include<unistd.h>

double target_file_size = 1024.0;//M 目标文件大小
double speed = 1.0;//M
void Download(double size,double split)
{
  double current_total = 0.0;
  while(current_total <= size)
  {
    FlushProgress(size,current_total);
    if(current_total >= size) break;
    //下载用sleep模拟
    usleep(5000);//代表一次下载
    current_total += split;
  }
}
int main()
{
  printf("下载中:\n");
  Download(target_file_size,speed);
  return 0;
}
