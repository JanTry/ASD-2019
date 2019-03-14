#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(void){
  const int N=100000;
  srand(time(0));
  int t[10];
  int i;
  for(i=0;i<10;i++) t[i]=0;
  for(i=0;i<N;i++) t[rand()%10]++;
  for(i=0;i<10;i++){
    printf("%d",i);
    printf(" wystapilo w %f",((float)t[i])*100/N);
    printf(" procent przypadkow\n");
  }
}
