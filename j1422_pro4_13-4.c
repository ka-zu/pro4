//基数ソート　基数：１０　昇順
//ログ出力
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int d[MAX];

unsigned digit(unsigned x, int k){//k桁目の数値を返す
  int i;
  for(i = 0; i < k; i++){//k桁目がⅠの位になるまで割る
    x = x / 10;
  }
  return x % 10;
}

void radix_sort(int n){
  int pass, order[10], i, j, b[MAX];//orderは0~9まである
  for(pass = 0; pass < 5; pass++){//最大桁数は５桁

    for(j = 0; j < 10; j++){//オーダーの初期化
      order[j] = 0;
    }
    for(i = 1; i <= n; i++){
      order[digit(d[i], pass)]++;
    }
    for(i=1; i<=9; i++){//次のデータを格納する配列を計算
      order[i] = order[i-1] + order[i];
    }
    for(i = n; i >= 1; i--){
      b[order[digit(d[i], pass)]--] = d[i];
    }
    for(i = 1; i <= n; i++){
      d[i] = b[i];
    }

    //ソート途中をログ出力
    for(i = 1; i <= n; i++){
      fprintf(stdout, " %5d", d[i]);
    }
    fprintf(stdout, "\n");

  }
}

int main(){
  int n, i, seed;
  n = 0;
  fprintf(stdout, "Input random-seed: ");
  scanf("%d", &seed);
  fprintf(stdout, "Input the number of data: ");
  scanf("%d", &n);
  if(n > MAX){
    fprintf(stderr, "N is too large!\n");
    exit(1);
  }
  srand(seed);
  for(i = 1; i <= n; i++){
    d[i] = rand() %100000;
  }
  fprintf(stdout, "\nInput data:\n");
  for(i = 1; i <= n; i++){
    fprintf(stdout, "d[%3d]: data = %5d\n", i, d[i]);
  }
  fprintf(stdout, "\nRadix Sorting Process.\n");//ソート開始ログ
  radix_sort(n);
  fprintf(stdout, "\nOutput data:\n");
  for(i = 1; i <= n; i++){
    fprintf(stdout, "d[%3d]: data = %5d\n", i, d[i]);
  }

  return 0;
}
