#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}LISTEL;

LISTEL *root;

void construct_list(){
	LISTEL *p,*q;
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

			p = (LISTEL *)malloc( sizeof(LISTEL) );
			q = (LISTEL *)malloc( sizeof(LISTEL) );

			p->data = y;

			q=root->next;//���̎��̃m�[�h��q�Ƃ���
			//printf("%d",p->data);
			p->next = q;//�V���Ȓlp�̎���q�ɂ���
			p->prev = q->prev;//p�̑O��q�̑O(�O�̒l)
			//printf("%d",p->data);
			root->next = p;//�O�̃m�[�h�Ƃ��܂̃m�[�h��A��
			q->prev = p;//�O�̃m�[�h�ƍ��̃m�[�h�𔽑΂ɘA��

		}
	}
}

void print_list() {
	LISTEL *p, *q;
	//�A�h���X����
	p = root->next;
	q = root->prev;
	if(p == root || q == root){
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout, "List data (From Last): ");
	while (p != root){
		fprintf(stdout, " %2d", p->data);
		p = p->next;
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "List data (From First): ");
	while (q != root){
		fprintf(stdout, " %2d", q->data);
		q = q->prev;
	}
	fprintf(stdout, "\n");
}

void insert_node(int k , int y){
	int i;
	LISTEL *p, *q;
	if(k <= 0){
		fprintf(stderr, "Target node is not found!");
		return;
	}
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root;
	for(i=1; i<k; i++){
		if(p->next == root){
			fprintf(stderr, "Error : Target node is not found!\n");
			return;
		}
		p = p->next;
	}

	q = (LISTEL *)malloc( sizeof(LISTEL) );
	q->data = y;
	q->next = p->next;//�ǉ�����m�[�h�̎���ǉ��O�̃m�[�h�̂���
	p->next->prev = q;//�ǉ��O�̎��̃m�[�h�̑O��ǉ�����m�[�h��
	p->next = q;
	q->prev = p;
}

void delete_node(int k){
	int i;
	LISTEL *p, *q;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root->next;
	if(p == NULL || k <= 0){
		fprintf(stderr, "Error : Target node is not found!\n");
		return;
	}
	if(k==1){
		p->next->prev = &root;//���̑O��root�ɂ���
		root->next = p->next;//�������̎��ɂ���
		
		return;
	}
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	q = NULL;
	//2�ȏ�
	printf("%d",k);
	for(i=0; i<k-1; i++){
		if(p->next == &root){
			fprintf(stderr, "Error : Target node is not found!\n");
			return;
		}
		//printf("%d",k);
		p = p->next;
	}
	//q = p;
	p->prev->next = p->next;//k�Ԗڂ�p�̑O�̃m�[�h�̎����Ak�Ԗڂ̎��̃m�[�h�ɂ���(p�Ԗڂ��΂�)
	p->next->prev = p->prev;//k�Ԗڂ�p�̎��̃m�[�h�̑O���Ak�Ԗڂ̑O�̃m�[�h�ɂ���(p�Ԗڂ��΂�)
}

void replace_node(int x,int y){
	int i;
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root->next;
	while(p->next != root){
		if(p->data == x){
			p->data = y;
		}
		p = p->next;
	}
}

int main() {
	int k,y,x;
	//root�ɒl�������ĂȂ��̂œ���Ă�����
	root = (LISTEL *)malloc( sizeof(LISTEL) );

	root->next = root;
	root->prev = root;
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
