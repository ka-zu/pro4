//循環リスト
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}LISTEL;

LISTEL root;//先頭ノードを持つポインタ
//連結リストを構築
void construct_list(){
  LISTEL *p;
  int n, y, i, k, noIndex[50];
  char buf[100];
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
      p->data = y;//pにデータを入れる
      p->next = root.next;//pの次をrootの次(&root)にする
      root.next = p;//rootの次をpにする
    }
  }
}
//リストの中身を表示
void print_list(){
  LISTEL *p;
  p = (LISTEL *)malloc(sizeof(LISTEL));
  p = root.next;
  if( p == &root){
    fprintf(stdout, "There is no data!");
    return;
  }
  fprintf(stdout, "List data: ");

  while(p != &root){//一周回ってrootに戻るまで
    fprintf(stdout, "%4d",p->data);
    p = p->next;//次へ移動
  }
  fprintf(stdout, "\n");
}
//ノードの挿入
void insert_node(int k, int y){
  int i;
  LISTEL *p, *q;
  if(k <= 0){
    fprintf(stderr, "Target node is not found!");
    return;
  }
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root.next;//rootの次からスタート
  for(i=1; i<k; i++){
    if(p == &root){//一周回っていたなら
      fprintf(stderr, "Error : Target node is not found!");
      return;
    }
    p = p->next;
  }

  q = (LISTEL *)malloc( sizeof(LISTEL) );//挿入するノード
  q->data = y;//ノードにデータを入れる
  q->next = p->next;//挿入したいノードの次を今の次に
  p->next = q;//今のノードの次に挿入したいノードに
}

//ノードの削除
void delete_node(int k){
  int i;
  LISTEL *p, *q;
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root.next;
  if(p == &root || k <= 0){//ノードが一周する・0以下を指定する
    fprintf(stderr, "Error : Target node is not found!\n");
    return;
  }
  if(k==1){
    root.next = p->next;//root(一番最初)の次を　次の次に
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
  root.next = &root;//ルートの次を初期化
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
