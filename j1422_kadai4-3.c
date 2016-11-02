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

void insert_node(int k, int y){
  int i;
  LISTEL *p, *q;
  if(k <= 0){
    fprintf(stderr, "Target node is not found!");
    return;
  }
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root.next;
  for(i=1; i<k; i++){
    if(p == &root){
      fprintf(stderr, "Error : Target node is not found!");
      return;
    }
    p = p->next;
  }

  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q->data = y;
  q->next = p->next;
  p->next = q;
}

void delete_node(int k){
  int i;
  LISTEL *p, *q;
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root.next;
  if(p == &root || k <= 0){
    fprintf(stderr, "Error : Target node is not found!\n");
    return;
  }
  if(k==1){
    root.next = p;
    return;
  }
  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q = root.next;
  //2個以上
  for(i=0; i<k-2; i++){
    if(p == &root){
      fprintf(stderr, "Error : Target node is not found!\n");
      return;
    }
    p = p->next;
  }
  q = p;
  p = p->next;
  q->next = p->next;
}

void replace_node(int x,int y){
	int i;
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	while(p != &root){
		if(p->data == x){
			p->data = y;
		}
		p = p->next;
	}

}

int main(){
  int k,y,x;
  construct_list();
  print_list();
  //データの挿入
  fprintf(stdout, "*******Insert*******\n");
  fprintf(stdout, "Input insert-location: ");
  scanf("%d", &k);
  fprintf(stdout, "Input insert-data: ");
  scanf("%d", &y);
  insert_node(k,y);
  print_list();

  //データの削除
  fprintf(stdout, "*******Delete*******\n");
  fprintf(stdout, "Input insert-location: ");
  scanf("%d", &k);
  delete_node(k);
  print_list();

  //データの置き換え
  fprintf(stdout, "*******Replace*******\n");
  fprintf(stdout, "Input search data: ");
  scanf("%d", &x);
  fprintf(stdout, "Input replace data: ");
  scanf("%d", &y);
  replace_node(x,y);
  print_list();

  return 0;
}
