Q_type Q[Q_size];
int f, r;

void init_Q(){
  f = 0;
  r = -1;
}

int stock_Q()
{
  if(f==r+1){
    return 0;
  }
  else if(f == r+2){
	  return Q_size+1;
  }
  else if(f==r){
	  return 1;
  }
  else{
	  return (r-f)+1;
  }
}

void enqueue(Q_type d)
{
	printf("%c",d);
	if((r+2)%Q_size == f){
		printf("Queue is full \n");
		exit(1);
	}

	r = (r+1)%(Q_size-1);
	Q[r]=d;
}

Q_type dequeue()
{
	int x;
	if(f==((r+1)%(Q_size-1))){
		printf("Queue is empty \n");
		exit(1);
	}
	x = Q[f];
	f=(f+1)%(Q_size-1);
	return x;
}

void print_Q()
{
	for(f;f<r;f++)
	{
		printf("%c",Q[f]);
	}
}
