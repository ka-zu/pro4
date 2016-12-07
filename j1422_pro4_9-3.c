//バブルソート降順
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//バブルソート(降順)
void bubble_sort(int a[], int n){
  int i,j,t;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j-1] < a[j]){
        t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
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
  //バブルソートの実行
  bubble_sort(d,n);
  //バブルソートの結果の表示
  fprintf(stdout,"Output data: ");
  for(i=0; i<n-1; i++){
    printf("%d ",d[i]);
  }
  printf("%d \n", d[n-1]);
  return 0;
}
