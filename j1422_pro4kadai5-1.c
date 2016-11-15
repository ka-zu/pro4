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

int main() {
	root.next = &root;
	root.prev = &root;
	construct_list();
	print_list();
	return 0;
}
