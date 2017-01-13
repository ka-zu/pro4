//マージソート　昇順　単方向リストをソート
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node
{
	int data;
	struct node *next;
}LIST;

//プロトタイプ宣言しないとおかしくなる
void construct_list();
void print_list();
LIST *merge_list(LIST *);
LIST *merge_sort(LIST *,LIST *);

LIST *root;

int main()
{
	int data[MAX],num=0;

	root = NULL;

	construct_list();
	printf("Input Data>");
	print_list();

	root = merge_list(root);

	printf("Output data: ");
	print_list();
	return 0;
}

//リストを分割する部分
LIST* merge_list(LIST *Head)
{
	LIST *p,*q,*a,*b;

	//並び替え対象のデータ数が１の場合
	if(Head == NULL || Head->next == NULL)	return Head;

	//pはrootの次qはpの2つ次
	p = Head;
	q = Head->next->next;

	//qがNULLに移動したときpの次が分割する位置の計算
	while(q != NULL)
	{
		p=p->next;
		q=q->next;
		if(q!=NULL)
			q=q->next;
		else{
			break;
		}
	}

	q=p->next;
	p->next = NULL;

	return merge_sort(merge_list(Head),merge_list(q));//再度マージ・ソート
}

//並び替える部分
LIST *merge_sort(LIST *a,LIST *b)
{
	LIST *p;
	LIST head;

	p = &head;

	while(a != NULL && b != NULL)
	{
		if(a->data <= b->data)
		{
			p->next = a;
			p = a;
			a = a->next;
		}
		else
		{
			p->next = b;
			p = b;
			b = b->next;
		}
	}

	if(a == NULL) p->next = b;
	else p->next = a;

	return head.next;
}

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
