//クイックソート　昇順
//さらにログを出力
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX]; //ソートの対象データを格納

void quick_sort(int le, int ri, int n){
  int i,j,k,pivot,tmp,h;

  if(le == ri){ return; }//最初の探索位置が同じなら中身が一つなので抜ける
  //基準値設定
  k = (le + ri) / 2;
  pivot = d[k];
  i = le; j =ri;

  fprintf(stdout,"<< Sort region: left = %d, right = %d, pivot = %d>>\n",le,ri,pivot);//ログ：ソート範囲
  fprintf(stdout,"Before: ");//ログ：ソート前
  for(h = 0; h<n; h++){
    fprintf(stdout, "%d ", d[h]);
  }
  fprintf(stdout, "\n", d[h]);

  while(i <= j){//探索開始位置がおなじか揃うまで繰り返し
    //ここの二行で昇順か降順か決まる
    while(d[i] < pivot){ i++; }//基準値以上の値を探索し、添え字をiに
    while(d[j] > pivot){ j--; }//基準値以下の値を探索し、添え字をjに
    if(i >= j){ break; }//探索の結果添え字がすれ違っていたらbreak;
    //値を交換
    tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
    i++; j--;
  }

  fprintf(stdout,"After: ");//ログ：ソート後
  for(h = 0; h<n; h++){
    fprintf(stdout, "%d ", d[h]);
  }
  fprintf(stdout, "\n", d[h]);

  fprintf(stdout,"Partition: left[%d - %d], right[%d - %d]\n\n",le,i-1,j+1,ri);//ログ：分割された範囲

  //探索範囲を分割
  if(le < i-1){
    fprintf(stdout,"<< Left call : quick_sort(%d, %d) >>\n",le,i-1);//ログ：左側クイックソートの呼びだし
    quick_sort(le, i-1,n);//左の要素が1でないなら、分割した左側をクイックソート
  }

  if(ri > j+1){
    fprintf(stdout,"<< Right call : quick_sort(%d, %d) >>\n",j+1,ri);//ログ：右側クイックソートの呼び出し
    quick_sort(j+1, ri,n);//右の要素が1でないなら、分割した右側をクイックソート
  }
}

int main(){
  int n,i;
  n = 0;
  fprintf(stdout, "Input data: ");
  while(scanf("%d", &d[n]) != EOF){
    n++;
  }
  fprintf(stdout, "\n");

  quick_sort(0,n-1,n);//最初の呼び出し

  fprintf(stdout,"Output data:");
  for(i = 0; i<n-1; i++){
    fprintf(stdout, "%d ", d[i]);
  }
  fprintf(stdout, "%d\n", d[n-1]);
  return 0;
}
