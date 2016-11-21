//単方向リスト
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}LISTEL;

LISTEL *root;//リストの最初のノードを指すポインタ

void construct_list(){
  LISTEL *p;
  int n, y, i, k, noIndex[50];
  char buf[100];
  while(1){
    fprintf(stdout, "Input data: ");
    fgets(buf, sizeof(buf), stdin);

    if(buf[0] == '\n'){
      return;
    }
    i=0; k=0;
    //最初に入力された文字がスペースでない場合
    if(buf[i] != ' '){
      noIndex[k++] = i;
    }
    //2つ目以降に入力された文字がスペースでない場合
    while(buf[i] != '\0'){
      i++;
      if(buf[i-1] == ' ' && buf[i] !=' ' && buf[i] != '\n'){
        noIndex[k++] = i;
      }
    }
    //文字数がオーバーしていたら
    if(buf[i-1] != '\n'){
      fprintf(stderr, "Error : Too long input dasa\n");
      exit(1);
    }
    //入力された数字をリストに格納する
    for(i = 0; i<k; i++){
      n = sscanf(&buf[ noIndex [i] ],"%d",&y);
      if(n != 1){
        fprintf(stderr, "Error : non-number input data\n");
      }
      p = (LISTEL *)malloc(sizeof(LISTEL));
      p->data = y;//pにデータを入れる
      p->next = root;//pの次をrootにする
      root = p;//rootの値をpにする
    }
  }
}
//連結リストを出力
void print_list(){
  LISTEL *p;
  p = (LISTEL *)malloc(sizeof(LISTEL));
  p = root;
  if(p == NULL){//p=NULLはroot=NULLなのでデータがない
    fprintf(stderr, "There is no data!");
    return;
  }
  fprintf(stdout, "List data: ");
  while(p != NULL){//pがNULLになるまで
    fprintf(stdout, "%4d", p->data);
    p = p->next;//pを次に移動
  }
  fprintf(stdout, "\n");
}

int main(){
  root = NULL;
  construct_list();
  print_list();
  return 0;
}
