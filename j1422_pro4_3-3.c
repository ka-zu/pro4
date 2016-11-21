#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}LISTEL;

LISTEL *root;

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
    if(buf[i] != ' '){
      noIndex[k++] = i;
    }
    while(buf[i] != '\0'){
      i++;
      if(buf[i-1] == ' ' && buf[i] !=' ' && buf[i] != '\n'){
        noIndex[k++] = i;
      }
    }
    if(buf[i-1] != '\n'){
      fprintf(stderr, "Error : Too long input dasa\n");
      exit(1);
    }
    for(i = 0; i<k; i++){
      n = sscanf(&buf[ noIndex [i] ],"%d",&y);
      if(n != 1){
        fprintf(stderr, "Error : non-number input data\n");
      }
      p = (LISTEL *)malloc(sizeof(LISTEL));
      p->data = y;  p->next = root;  root = p;
    }
  }
}

void print_list(){
  LISTEL *p;
  p = (LISTEL *)malloc(sizeof(LISTEL));
  p = root;
  if(p == NULL){
    fprintf(stderr, "There is no data!");
    return;
  }
  fprintf(stdout, "List data: ");
  while(p != NULL){
    fprintf(stdout, "%4d", p->data);
    p = p->next;
  }
  fprintf(stdout, "\n");
}
//新しいノードをk番目に挿入する
void insert_node(int k, int y){
  int i;
  LISTEL *p, *q;
  if(k <= 0){//0以下番目が入力されたら
    fprintf(stderr, "Target node is not found!");
    return;
  }
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root;
  for(i=1; i<k; i++){//k番目まで移動
    if(p == NULL){//途中でNULLなら
      fprintf(stderr, "Error : Target node is not found!");
      return;
    }
    p = p->next;//次へ移動
  }

  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q->data = y;//qにデータを入れる
  q->next = p->next;//qの次をpの次に
  p->next = q;//pの次をqに
}
//k番目のノードを削除
void delete_node(int k){
  int i;
  LISTEL *p, *q;
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root;
  if(p == NULL || k <= 0){
    fprintf(stderr, "Error : Target node is not found!\n");
    return;
  }
  if(k==1){//一つ目を削除するなら
    root = p->next;
    return;
  }
  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q = NULL;
  //2番目以降
  for(i=0; i<k-2; i++){//(i=2; i<k; i++)でも可
    if(p == NULL){//途中でNULL
      fprintf(stderr, "Error : Target node is not found!\n");
      return;
    }
    p = p->next;//pを次に移動
  }
  q = p;//
  p = p->next;
  q->next = p->next;
}
//xの値を持つノードをyに置き換え
void replace_node(int x,int y){
	int i;
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root;
	while(p != NULL){//pが最後に行くまで
		if(p->data == x){//xの値を持つなら
			p->data = y;//yに置き換え
		}
		p = p->next;//次に移動
	}

}

int main(){
  int k,y,x;
  root = NULL;
  construct_list();
  print_list();

  //insert data
  fprintf(stdout, "*******Insert*******\n");
  fprintf(stdout, "Input insert-location: ");
  scanf("%d", &k);
  fprintf(stdout, "Input insert-data: ");
  scanf("%d", &y);
  insert_node(k,y);
  print_list();

  //delete data
  fprintf(stdout, "*******Delete*******\n");
  fprintf(stdout, "Input delete-location: ");
  scanf("%d", &k);
  delete_node(k);
  print_list();

  //replace_data
  fprintf(stdout, "*******Replace*******\n");
  fprintf(stdout, "Input search data: ");
  scanf("%d", &x);
  fprintf(stdout, "Input replace data: ");
  scanf("%d", &y);
  replace_node(x,y);
  print_list();

  return 0;
}
