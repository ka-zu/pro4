//マージソート　降順
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int tmp[MAX]; //対象データを一時的に保存する配列

void merge_sort(int a[], int le, int ri){
  int i, j, k, m;
  if(le >= ri){//並び替え対象のデータ数が１の場合
    return;
  }
  m = (le + ri) / 2;//等分割をする場所を計算
  merge_sort(a, le, m);//左側を再度マージソート
  merge_sort(a, m+1, ri);//右側を再度マージソート
  for(i = le; i<=m; i++){//左側をそのままコピーをする
    tmp[i] = a[i];
  }
  for(j=m+1; j<=ri; j++){//右側を、順番逆に変えてコピーする
    tmp[ri+m+1-j] = a[j];
  }
  i = le;
  j = ri;
  for(k=le; k<=ri; k++){//マージ＆ソート
    if(tmp[i] >= tmp[j]){
      a[k] = tmp[i++];
    }
    else{
      a[k] = tmp[j--];
    }
  }
}

int main(){
  int n,i;
  int d[MAX];
  n = 0;
  fprintf(stdout, "Input data: ");
  while(scanf("%d", &d[n]) != EOF){
    n++;
  }
  merge_sort(d, 0, n-1);
  fprintf(stdout, "Output data: ");
  for(i=0; i<n-1; i++){
    fprintf(stdout, "%d ", d[i]);
  }
  fprintf(stdout, "%d \n", d[n-1]);
  return 0;
}
