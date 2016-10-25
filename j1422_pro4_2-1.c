#include <stdio.h>
#include <stdlib.h>
#define Q_size 10
#define Q_type int
#include "j1422_queue.h"

int main()
{
  int c;
  int i;
  int num;

  init_Q();//キューの初期化

  //
  fprintf(stdout, "Queue size: %d",Q_size );
  fprintf(stdout, "\nPlease enter text:" );

  //
  while ((c = getchar()) != '\n') {
    enqueue(c);
  }
  printf("Front: %d   Rear: %d",f,r);//先頭　末尾の位置を出力
  fprintf(stdout, "\nArray Q data: ");
  for(i = 0;i<count;i++)//キューの配列内のデータを出力
  {
    fprintf(stderr, "%c ",Q[i]);
  }

  fprintf(stdout, "\nPlease enter dequeue number: ");
  scanf("%d",&num );//dequeueする値受け取り,格納

  fprintf(stdout, "Dequeue data: ");
  for(i=0;i<num;i++)
  {
    fprintf(stderr, "%c ",dequeue() );
  }

  fprintf(stdout, "\nPlease enter next text(MAX num:%d)",Q_size - count );
  c = getchar();
  while ((c=getchar()) != '\n') {
    enqueue(c);
  }

  fprintf(stderr, "Queue all data: ");
  while (count != 0) {
    fprintf(stderr, "%c ",dequeue() );
  }

  fprintf(stderr, "\nArray Q data:");
  for(i=0;i<Q_size;i++)
  {
    fprintf(stderr, "%c ",Q[i]);
  }
}
