//マージソート　昇順　単方向リストをソート
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node {
  int data;
  struct node *next;
}LIST;

LIST *root;

void construct_list(){
  LIST *p;
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
      p = (LIST *)malloc(sizeof(LIST));
      p->data = y;//pにデータを入れる
      p->next = root;//pの次をrootにする
      root = p;//rootの値をpにする
    }
  }
}

void print_list(){
  LIST *p;
  p = (LIST *)malloc(sizeof(LIST));
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

//リストを分割する部分
LIST* merge(LIST *Head){
  LIST *p,*q,*form,*latt;//form:分割した前　latt:分割した後ろ

  //pはrootの次qはpの2つ次
  p = Head;
  q = Head;

  if(p == q){//並び替え対象のデータ数が１の場合
    return Head;
  }

  //qを2つ移動
  if(q->next != NULL){
    q = q->next;
  }
  if(q->next != NULL){
    q = q->next;
  }

  //qがNULLに移動したときpの次が分割する位置の計算
  while(q != NULL){
    p = p->next;
    q = q->next;
    if( q != NULL ){
      q = q->next;
    }
    else{
      break;
    }
  }

  q = p->next;
  p->next = NULL;

  return sort(merge(Head),merge(q));//再度マージソート
}

//並び変える部分
LIST* sort(LIST *form,LIST *latt)
{
  LIST *p;
  LIST head;

  p = &head;

  while(form != NULL && latt != NULL){
    if(form->data <= latt->data){
      p->next = form;
      p = form;
      form = form->next;
    }
    else{
      p->next = latt;
      p = latt;
      latt = latt->next;
    }
  }

  if (form == NULL){
    p->next = latt;
  }else{
    p->next = form;
  }

  return head.next;
}

int main(){
  root = NULL;
  construct_list();
  fprintf(stdout, "Input data: ");
  print_list();

  root = merge(root);

  fprintf(stdout, "Output data: ");
  print_list();
  return 0;
}
