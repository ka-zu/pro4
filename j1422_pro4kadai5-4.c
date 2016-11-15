#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	double num;
	char station[10];
	struct node *next;
	struct node *prev;
}LISTEL;

LISTEL root;

void construct_list(int argc,char *argv){
	LISTEL *p,*q;
	int n, y, i, k, noIndex[50];
	char buf[100];
	double num=0.0;
	FILE *fp;
	fp = fopen(argv,"r");
	if(fp==NULL)
	{
		printf("ファイルが開けませんでした\n");
		exit(1);
	}

	while(n = fscanf( fp, "%[^\t]\t%lf",buf,&num) != EOF)
	{
			p = (LISTEL *)malloc( sizeof(LISTEL) );
			q = (LISTEL *)malloc( sizeof(LISTEL) );

			sprintf(p->station,"%s",buf);
			p->num = num;

			q=root.next;//今の次のノードをqとする
			p->next = q;//新たな値pの次をqにする
			p->prev = q->prev;//pの前はqの前(前の値)
			root.next = p;//前のノードといまのノードを連結
			q->prev = p;//前のノードと今のノードを反対に連結
	}
	fclose(fp);
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
		fprintf(stdout, " %s", p->station);
		fprintf(stdout, " %.1lf", p->num);
		p = p->next;
	}
	fprintf(stdout, "\n");
	fprintf(stdout, "List data (From First): ");
	while (q != &root){
		fprintf(stdout, " %s", q->station);
		fprintf(stdout, " %.1lf", q->num);
		q = q->prev;
	}
	fprintf(stdout, "\n");
}

int main(int argc , char *argv[]) {
	root.next = &root;
	root.prev = &root;
	construct_list(argc,argv[1]);
	print_list();
	
	return 0;
}
