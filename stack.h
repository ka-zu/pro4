//j1422 土井 stack.h

stack_type stack[stack_size];
int sp;

//スタックエディタの初期化
void init_stack()
{
	sp = -1;
}

//スタックにデータを格納
void push(stack_type d)
{
 	if( sp < stack_size-1)
	{
		stack[++sp] = d;
	}
	else
	{
		fprintf(stderr, "Error : stack full \n");
		exit(1);
	}
}

//スタック内のデータ数を返す
int stack_stock()
{
	//自分で作る
	return sp+1;
}

//スタックのデータを取り出す
stack_type pop()
{
	if( sp >= 0)
	{
		return stack[sp--];
	}
	else
	{
		fprintf(stderr, "Error : stack empty \n");
		exit(1);
	}
}

//スタック内のデータを出力
void print_stack()
{
	//ここは自分で作る
	int i;
	printf("stack data : ");
	for(i=0;i<=sp;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
