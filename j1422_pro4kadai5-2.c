//双方向リスト　構築　表示　挿入
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}LISTEL;

LISTEL root;

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

			q=root.next;//今の次のノードをqとする
			//printf("%d",p->data);
			p->next = q;//新たな値pの次をqにする
			p->prev = q->prev;//pの前はqの前(前の値)
			//printf("%d",p->data);
			root.next = p;//前のノードといまのノードを連結
			q->prev = p;//前のノードと今のノードを反対に連結

		}
	}
}

void print_list() {
	LISTEL *p, *q;
	//アドレスを代入
	p = root.next;
	q = root.prev;
	if(p == &root || q == &root){
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout, "List data (From Last): ");
	while (p != &root){
		fprintf(stdout, " %2d", p->data);
		p = p->next;
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "List data (From First): ");
	while (q != &root){
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
	p = &root;
	for(i=1; i<k; i++){
		if(p->next == &root){
			fprintf(stderr, "Error : Target node is not found!\n");
			return;
		}
		p = p->next;
	}

	q = (LISTEL *)malloc( sizeof(LISTEL) );
	q->data = y;
	q->next = p->next;//追加するノードの次を追加前のノードのつぎに
	p->next->prev = q;//追加前の次のノードの前を追加するノードに
	p->next = q;
	q->prev = p;
}

void delete_node(int k){
	int i;
	LISTEL *p, *q;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	q = root.prev;
	if(p == NULL || k <= 0){
		fprintf(stderr, "Error : Target node is not found!\n");
		return;
	}
	if(k==1){
		p->next->prev = &root;
		root.next = p->next;

		return;
	}
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	q = NULL;
	//2個以上
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
	p->prev->next = p->next;//k番目のpの前のノードの次を、k番目の次のノードにする(p番目を飛ばす)
	p->next->prev = p->prev;////k番目のpの次のノードの前を、k番目の前のノードにする(p番目を飛ばす)
}

int main() {
	int k,y;
	root.next = &root;
	root.prev = &root;
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

	return 0;
}
