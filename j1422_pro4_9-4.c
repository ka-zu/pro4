//選択ソート降順
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//選択ソート(降順)
void select_sort(int a[], int n){
  int i,j,t,min;
  for(i=0;i<n-1;i++){
    min = i;//先頭であるi番目を表す（中の値ではなく何番目か入る）
    for(j=i+1;j<n;j++){//
      if( a[j] > a[min] ){//
        min = j;
      }
    }
    t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
}

int main(){
  int d[MAX],n,i;
  n = 0;
  fprintf(stdout, "Input data: ");
  //EOFが入力されるまで、入力された値を配列dに代入
  while(scanf("%d", &d[n]) != EOF){
    n++;
  }
  //選択ソートの実行
  select_sort(d,n);
  //選択ソートの結果の表示
  fprintf(stdout,"Output data: ");
  for(i=0; i<n-1; i++){
    printf("%d ",d[i]);
  }
  printf("%d \n", d[n-1]);
  return 0;
}
