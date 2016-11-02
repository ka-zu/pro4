#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}LISTEL;

LISTEL root;//先頭ノードを持つポインタ

void construct_list(){
  LISTEL *p;
  int n, y, i, k, noIndex[50];
  char buf[100];
  root.next = &root;//ルートの次を初期化
  while(1){
    fprintf(stdout, "Input data:");
    fgets(buf, sizeof(buf), stdin);
    if(buf[0] == '\n'){
      return;
    }
    i=0;  k=0;
    if(buf[i] != ' '){
      noIndex[k++] = i;
    }
    while(buf[i] != '\0'){
      i++;
      if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n'){
        noIndex[k++] = i;
      }
    }
    if(buf[i-1] != '\n'){
      fprintf(stderr, "Error: To long input data!\n");
      exit(1);
    }
    for(i=0; i<k; i++){
      n=sscanf(&buf[ noIndex[i] ], "%d", &y);
      if(n != 1){
        fprintf(stderr, "Error:non-number input data\n");
        continue;
      }
      p = (LISTEL *)malloc(sizeof(LISTEL));
      p->data = y;
      p->next = root.next;
      root.next = p;
    }
  }
}

void print_list(){
  LISTEL *p;
  p = (LISTEL *)malloc(sizeof(LISTEL));
  p = root.next;
  if( p == &root){
    fprintf(stdout, "There is no data!");
    return;
  }
  fprintf(stdout, "List data: ");

  while(p != &root){
    fprintf(stdout, "%4d",p->data);
    p = p->next;
  }
  fprintf(stdout, "\n");
}

int main(){
  construct_list();
  print_list();
  return 0;
}
