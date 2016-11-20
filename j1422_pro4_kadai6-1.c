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

int main(){
  root = NULL;
  construct_tree();
  print_tree(0,root);
  return 0;
}
