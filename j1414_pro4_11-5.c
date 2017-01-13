//j1414 小林佳樹 11-5.c
//j4角先輩の助言をいただきました

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//連結リストの構造体宣言
typedef struct node
{
	int data;
	struct node *next;
}LIST;

//プロトタイプ宣言
void construct_list();
void print_list();
LIST *merge_sort(LIST *);
LIST *sort(LIST *,LIST *);

//グローバル変数宣言
LIST *root;	//リストの最初のノードを指すポインタ

int main()
{
	int data[MAX],num=0;

	root = NULL;

	construct_list();
	printf("Input Data>");
	print_list();

	root = merge_sort(root);
	
	printf("Output data: ");
	print_list();
	return 0;
}

//マージソート
LIST* merge_sort(LIST *Head)
{
	LIST *p,*q,*a,*b;
	
	if(Head == NULL || Head->next == NULL)	return Head;

	p = Head;
	q = Head->next->next;

	while(q != NULL)
	{
		p=p->next;
		q=q->next;
		if(q!=NULL)
			q=q->next;
		else break;
	}

	q=p->next;
	p->next = NULL;

	return sort(merge_sort(Head),merge_sort(q));
}

LIST *sort(LIST *a,LIST *b)
{
	LIST *p;
	LIST top;

	p = &top;

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

	return top.next;
}

//連結リストを構築する関数
void construct_list()
{
	LIST *p;
	int n, y, i, k, noIndex[50];
	char buf[100];
	while(1)
	{
		fprintf(stdout,"Input Data: ");
		fgets(buf, sizeof(buf), stdin);

		if(buf[0] == '\n')	{return;}
		i = 0, k = 0;
		//最初に入力された文字がスペースでない場合、配列の場所をnoIndex[]に格納
		if(buf[i] != ' ')		{noIndex[k++] = i;}
		//2つ目以降に入力された文字がスペースでない場合、配列の場所をnoIndex[]に格納
		while(buf[i] != '\0')
		{
			i++;
			if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n')		{noIndex[k++] = i;}
		}
		//文字数がオーバーした場合
		if(buf[i-1] != '\n')
		{
			fprintf(stderr, "Error : Too long input data\n");
			exit(1);
		}
		//入力された数字をリストに格納する
		for(i=0;i<k;i++)
		{
			n = sscanf(&buf[noIndex[i] ], "%d", &y);
			if(n != 1)
			{
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			p = (LIST *)malloc(sizeof(LIST));
			p->data = y; p->next = root; root = p;

		}
	}
}

//連結リストを出力する関数
void print_list()
{
	LIST *p;
	p = (LIST *)malloc( sizeof(LIST));
	p = root;
	if(p == NULL)
	{
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout,"List data:");
	while(p != NULL)
	{
		fprintf(stdout,"%4d",p->data);
		p = p->next;
	}
	fprintf(stdout,"\n");
}
