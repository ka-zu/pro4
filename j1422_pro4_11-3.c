//マージソート　昇順　ログ出力
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int tmp[MAX]; //対象データを一時的に保存する配列

void merge_sort(int a[], int le, int ri, int n, int nest){
  int i, j, k, m;

  fprintf(stdout, "\nNest = %d [ %d - %d ]\n",nest,le,ri);//ログ出力　再帰の階層と範囲
  if(le >= ri){//並び替え対象のデータ数が１の場合
    fprintf(stdout, "\n");
    return;
  }

  m = (le + ri) / 2;//等分割をする場所を計算

  fprintf(stdout, "<< Left call : merge_sort(%d , %d) >>\n\n",le,m);
  merge_sort(a, le, m, n, nest+1);//左側を再度マージソート
  fprintf(stdout, "Nest = %d [ %d - %d ]\n",nest,le,ri);//ログ出力　再帰の階層と範囲
  fprintf(stdout, "<< Right call : merge_sort(%d , %d) >>\n\n",m+1,ri);
  merge_sort(a, m+1, ri, n, nest+1);//右側を再度マージソート
  fprintf(stdout, "Nest = %d [ %d - %d ]\n",nest,le,ri);//ログ出力　再帰の階層と範囲


  fprintf(stdout, "Pertition : left[%d - %d], right[%d - %d]\n",le, m, m+1, ri);
  fprintf(stdout, "<< Sort region : left = %d, right = %d, m = %d >>\n",le, ri, m);
  fprintf(stdout, "Before :  ");
  for(i=0; i<n; i++){
    fprintf(stdout, "%d  ", a[i]);
  }
  fprintf(stdout, "\n", a[i]);

  for(i = le; i<=m; i++){//左側をそのままコピーをする
    tmp[i] = a[i];
  }
  for(j=m+1; j<=ri; j++){//右側を、順番逆に変えてコピーする
    tmp[ri+m+1-j] = a[j];
  }
  i = le;
  j = ri;
  for(k=le; k<=ri; k++){//マージ＆ソート
    if(tmp[i] <= tmp[j]){
      a[k] = tmp[i++];
    }
    else{
      a[k] = tmp[j--];
    }
  }

  fprintf(stdout, "After :  ");
  for(i=0; i<n; i++){
    fprintf(stdout, "%d  ", a[i]);
  }
  fprintf(stdout, "\n", a[i]);

}

int main(){
  int n,i;
  int d[MAX];
  n = 0;
  fprintf(stdout, "Input data: ");
  while(scanf("%d", &d[n]) != EOF){
    n++;
  }
  merge_sort(d, 0, n-1, n, 1);
  fprintf(stdout, "Output data: ");
  for(i=0; i<n-1; i++){
    fprintf(stdout, "%d ", d[i]);
  }
  fprintf(stdout, "%d \n", d[n-1]);
  return 0;
}
