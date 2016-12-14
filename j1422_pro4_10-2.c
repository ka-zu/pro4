//クイックソート　降順
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX]; //ソートの対象データを格納

void quick_sort(int le, int ri){
  int i,j,k,pivot,tmp;

  if(le == ri){ return; }//最初の探索位置が同じなら中身が一つなので抜ける
  //基準値設定
  k = (le + ri) / 2;
  pivot = d[k];
  i = le; j =ri;

  while(i <= j){//探索開始位置がおなじか揃うまで繰り返し
    //ここの二行で昇順か降順か決まる
    while(d[i] > pivot){ i++; }//基準値以上の値を探索し、添え字をiに
    while(d[j] < pivot){ j--; }//基準値以下の値を探索し、添え字をjに
    if(i >= j){ break; }//探索の結果添え字がすれ違っていたらbreak;
    //値を交換
    tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
    i++; j--;
  }
  //探索範囲を分割
  if(le < i-1){ quick_sort(le, i-1); }//左の要素が1でないなら、分割した左側をクイックソート
  if(ri > j+1){ quick_sort(j+1, ri); }//右の要素が1でないなら、分割した右側をクイックソート
}

int main(){
  int n,i;
  n = 0;
  fprintf(stdout, "Input data: ");
  while(scanf("%d", &d[n]) != EOF){
    n++;
  }
  quick_sort(0,n-1);//最初の呼び出し
  for(i = 0; i<n-1; i++){
    fprintf(stdout, "%d ", d[i]);
  }
  fprintf(stdout, "%d \n", d[n-1]);
  return 0;
}
