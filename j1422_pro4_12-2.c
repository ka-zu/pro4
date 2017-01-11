//ヒープソート　降順
//１３行目　j > k
//１７行目　v <= d[i]
//で降順になる
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int d[MAX];

void downheap(int j, int k){
  int i,v;
  v = d[j];
  while( j <= k/2 ){
    i = 2*j;
    if( i<k && d[i] > d[i+1] ){
      i++;
    }
    if(v <= d[i] || j > k ){
      break;
    }
    d[j] = d[i];
    d[i] = v;
    j = i;
  }
}

void heap_soat(int n){
  int i,j,k,t;
  //1番目からn番目のデータをヒープ化する
  for( j = n/2; j >= 1; j--){
    downheap(j , n);
  }
  k = n;
  while(k > 1){
    t = d[1];
    d[1] = d[k];
    d[k] = t;
    downheap(1,--k);
  }
}

int main(){
  int n,i,seed;
  n = 0;
  //乱数の種を入力
  fprintf(stdout, "Input random-seed: ");
  scanf("%d", &seed);
  //並び替えに使うデータの個数を入力
  fprintf(stdout, "Input the number of data: ");
  scanf("%d", &n);
  //データの個数に対するエラー処理
  if(n > MAX){
    fprintf(stderr, "N is too large!\n");
    exit(1);
  }
  srand(seed);//乱数の種を設定
  //乱数の生成
  for(i=1; i<=n; i++){
    d[i] = (rand()*rand()/1000)%100;
  }
  //生成されたデータ(並び替え前のデータ)の出力
  fprintf(stdout, "\nInput data:\n");
  for(i=1; i<=n; i++){
    fprintf(stdout, "d[%3d]: data = %5d\n", i, d[i]);
  }
  heap_soat(n);//ヒープソート実行
  //並び替え後のデータを出力
  fprintf(stdout, "\nOutput data:\n");
  for(i=1; i<=n; i++){
    fprintf(stdout, "d[%3d]: data = %5d\n", i, d[i]);
  }
  return 0;
}
