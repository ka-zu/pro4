//クイックソート　降順
//構造体配列をソートS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct item{
  double data;
  int num;
}Item;

Item d[MAX]; //ソートの対象データを格納

void quick_sort(int le, int ri){
  int i,j,k;
  double pivot;
  Item tmp;

  if(le == ri){ return; }//最初の探索位置が同じなら中身が一つなので抜ける
  //基準値設定
  k = (le + ri) / 2;
  pivot = d[k].data;
  i = le; j =ri;

  while(i <= j){//探索開始位置がおなじか揃うまで繰り返し
    //ここの二行で昇順か降順か決まる
    while(d[i].data > pivot){ i++; }//基準値以上の値を探索し、添え字をiに
    while(d[j].data < pivot){ j--; }//基準値以下の値を探索し、添え字をjに
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
  int n,i,seed;
  n = 0;

  //乱数の種の設定
  fprintf(stdout, "Input random-seed: ");
  scanf("%d",&seed);

  //並び替えに使うデータの個数を入力
  fprintf(stdout, "Input the number of data: ");
  scanf("%d", &n);

  //データの個数に対するエラー処理
  if(n > MAX){
    fprintf(stderr, "N is too large!\n");
    exit(1);
  }
  else if(n < 0){
    fprintf(stderr, "N is too small!\n");
    exit(1);
  }

  //乱数の生成
  for (i=0; i<n; i++) {
    d[i].data = ((double)rand()/(double)(n+0.3));
    d[i].num = 100+i;
  }

  fprintf(stdout,"\nInput data:\n");
  for(i = 0; i<n; i++){
    fprintf(stdout, "d[%3d]: data = %10.3f, num = %4d\n",i, d[i].data, d[i].num);
  }

  quick_sort(0,n-1);//最初の呼び出し

  fprintf(stdout,"\nOutput data:\n");
  for(i = 0; i<n; i++){
    fprintf(stdout, "d[%3d]: data = %10.3f, num = %4d\n",i, d[i].data, d[i].num);
  }  return 0;
}
