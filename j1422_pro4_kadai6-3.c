#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}TREE;

TREE *root;

void construct_tree(){
  TREE *p,*q;
  int n, y, i, k, noIndex[50];
  char buf[100];
  p = (TREE *)malloc( sizeof(TREE) );
  while(1){
    fprintf(stdout, "Input data: ");
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
      fprintf(stderr, "Error:Too long input data\n");
      exit(1);
    }
    //入力されたノードを格納して木を構築する
    for(i=0;i<k;i++){
      n = sscanf(&buf[ noIndex[i] ], "%d", &y);
      if(n != 1){
        fprintf(stderr, "Error:non-number input data\n");
        continue;
      }
      if (i == 0) {//最初だけ根を構成する
        q = (TREE *)malloc( sizeof(TREE) );
        q->data = y;
        q->left = NULL;
        q->right = NULL;
        root = q;
      }else{//節や葉を構成する
        p = root;
        while(p != NULL){
          if(y < p->data){//入れる値が今見ている値より小さいとき
            if(p->left != NULL){//左が空いなかったら
              p = p->left;//左へ移動
            }
            else{//空いていたら
              q = (TREE *)malloc( sizeof(TREE) );
              q->data = y;
              q->left = NULL;
              q->right = NULL;
              p->left = q;//新しく葉(節)にする
              break;
            }
          }
          else if(y > p->data){
            if(p->right != NULL){
              p = p->right;
            }
            else{
              q = (TREE *)malloc( sizeof(TREE) );
              q->data = y;
              q->left = NULL;
              p->right = NULL;
              p->right = q;
              break;
            }
          }
        }
      }
    }
  }
}

void print_tree(int depth, TREE *p){
  int i;
  if(p == NULL){
    return;
  }
  //木のデータを出力
  print_tree(depth+1,p->right);
  for(i=0;i<depth;i++){
    fprintf(stdout, "    ");
  }
  fprintf(stdout," %4d\n", p->data);
  print_tree(depth+1, p->left);
}

void insert_node(int y, TREE *p){
  TREE *q;
  //空でないか確認
  if(p == NULL){
    fprintf(stderr, "Error:There is no data!");
    return;
  }
  q = (TREE *)malloc( sizeof(TREE) );
  q->data = y;
  q->left = NULL;
  q->right = NULL;
  if(y < p->data){
    if(p->left != NULL){
      insert_node(y,p->left);
    }else{
      q = (TREE *)malloc( sizeof(TREE) );
      q->data = y;
      q->left = NULL;
      q->right = NULL;
      p->left = q;
    }
  }
  else if(y > p->data){
    if(p->right != NULL){
      insert_node(y,p->right);
    }else{
      q = (TREE *)malloc( sizeof(TREE) );
      q->data = y;
      q->left = NULL;
      q->right = NULL;
      p->right = q;
    }
  }
}

int delete_node(int y){//左側の最大値から求める
  TREE *n, *p_n, *l_b;//自分　親　左の子
  int d;
  n = root;
  p_n = NULL;
  d = 0;
  //空でないか確認
  if(n == NULL){
    fprintf(stderr, "Error:There is no data!");
    return -1;
  }
  while(n != NULL && n->data != y){
      if(n->data > y){//今の値より子が小さければ
        p_n = n;//次の親となる
        n = n->left;//左の子に移動
        d = -1;
      }
      else{//子が大きければ
        p_n = n;
        n = n->right;
        d = 1;
      }
    }
    if(d==0){
      fprintf(stderr,"Error:Serch data not found!\n");
      return 0;
    }
    //削除するプログラム
    if(n->left == NULL && n->right == NULL ){//どちらもNULLなら葉
      if(d == -1){
        p_n->left = NULL;
      }
      else if(d == 1){
        p_n->right = NULL;
      }
    }
    else if(n->left == NULL || n->right == NULL){//どちらかがNULLなら一つの子を持つ親
      //fprintf(stdout,"parent of one \n");
      if(d == -1){//親の左から来た
        if(n->left != NULL){//左に値がある
          p_n->left = n->left;//親の左と一つの子を結ぶ
        }
        else{//右に値がある
          p_n->left = n->right;//親の左と一つの子を結ぶ
        }
      }
      else if(d == 1){//親の右から来た
        if(n->left != NULL){
          p_n->right = n->left;//親の右と一つの子を結ぶ
        }
        else{
          p_n->right = n->right;//親の右と一つの子を結ぶ
        }
      }
    }
    else{//どちらもNULLでなかったら二人の子を持つ親
      //fprintf(stdout,"parent of two \n");
      //左の気からの最大数を削除する方法
      p_n = n;
      n = n->left;//左に移動
      while(n->left != NULL && n->right != NULL){//左の枝最大の値になるまで移動
          if(n->right != NULL){//右に値があるなら
            n = n->right;//右の子に移動
          }
          else{
            n = n->left;
          }
      }
      delete_node(n->data);//左の最大値（葉）を削除
      p_n->data = n->data;//消したい節に代入
    }

  return 1;
}

int main(){
  int y;
  root = NULL;
  construct_tree();
  print_tree(0,root);
  //insert data
  fprintf(stdout, "*******Insert_node*******\n");
  fprintf(stdout, "Input insert data: ");
  scanf("%d",&y);
  insert_node(y,root);
  print_tree(0,root);
  //delete data
  fprintf(stdout,"*******Delete*******\n");
  fprintf(stdout,"Input delete-location: ");
  scanf("%d",&y);
  delete_node(y);
  print_tree(0,root);

  return 0;
}
