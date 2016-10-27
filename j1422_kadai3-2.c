#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}LISTEL;

LISTEL *root;

void construct_list(){
  LISTEL *p;
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
      p = (LISTEL *)malloc(sizeof(LISTEL));
      p->data = y;  p->next = root;  root = p;
    }
  }
}

void print_list(){
  LISTEL *p;
  p = (LISTEL *)malloc(sizeof(LISTEL));
  p = root;
  if(p == NULL){
    fprintf(stderr, "There is no data!");
    return;
  }
  fprintf(stdout, "List data: ");
  while(p != NULL){
    fprintf(stdout, "%4d", p->data);
    p = p->next;
  }
  fprintf(stdout, "\n");
}

/*void overWrite_node(int k, int y){
  int i;
  LISTEL *p, *q;
  if(k <= 0){
    fprintf(stderr, "Target node is not found!");
    return;
  }
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root;
  for(i=1; i<k; i++){
    if(p == NULL){
      fprintf(stderr, "Error : Target node is not found!");
      return;
    }
    p = p->next;
  }
  p->data = y;
  q = (LISTEL *)malloc( sizeof(LISTEL) );
  p = q;
  q = p->next;
}*/

void insert_node(int k, int y){
  int i;
  LISTEL *p, *q;
  if(k <= 0){
    fprintf(stderr, "Target node is not found!");
    return;
  }
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root;
  for(i=1; i<k; i++){
    if(p == NULL){
      fprintf(stderr, "Error : Target node is not found!");
      return;
    }
    p = p->next;
  }

  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q->data = y;
  q->next = p->next;
  p->next = q;
}

void delete_node(int k){
  int i;
  LISTEL *p, *q;
  p = (LISTEL *)malloc( sizeof(LISTEL) );
  p = root;
  if(p == NULL || k <= 0){
    fprintf(stderr, "Error : Target node is not found!\n");
    return;
  }
  if(k==1){
    root = p->next;
    return;
  }
  q = (LISTEL *)malloc( sizeof(LISTEL) );
  q = NULL;
  //2個以上
  printf("%d",k);
  for(i=0; i<k-2; i++){
    if(p == NULL){
      fprintf(stderr, "Error : Target node is not found!\n");
      return;
    }
	printf("%d",k);
    p = p->next;
  }
  q = p;
  p = p->next;
  q->next = p->next;
}

int main(){
  int k, y;
  root = NULL;
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
