//j1414 ���щ��� 11-5.c
//j4�p��y�̏��������������܂���

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

//�A�����X�g�̍\���̐錾
typedef struct node
{
	int data;
	struct node *next;
}LIST;

//�v���g�^�C�v�錾
void construct_list();
void print_list();
LIST *merge_sort(LIST *);
LIST *sort(LIST *,LIST *);

//�O���[�o���ϐ��錾
LIST *root;	//���X�g�̍ŏ��̃m�[�h���w���|�C���^

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

//�}�[�W�\�[�g
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

//�A�����X�g���\�z����֐�
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
		//�ŏ��ɓ��͂��ꂽ�������X�y�[�X�łȂ��ꍇ�A�z��̏ꏊ��noIndex[]�Ɋi�[
		if(buf[i] != ' ')		{noIndex[k++] = i;}
		//2�ڈȍ~�ɓ��͂��ꂽ�������X�y�[�X�łȂ��ꍇ�A�z��̏ꏊ��noIndex[]�Ɋi�[
		while(buf[i] != '\0')
		{
			i++;
			if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n')		{noIndex[k++] = i;}
		}
		//���������I�[�o�[�����ꍇ
		if(buf[i-1] != '\n')
		{
			fprintf(stderr, "Error : Too long input data\n");
			exit(1);
		}
		//���͂��ꂽ���������X�g�Ɋi�[����
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

//�A�����X�g���o�͂���֐�
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
