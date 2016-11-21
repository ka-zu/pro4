//j1422 �y�� stack.h

stack_type stack[stack_size];
int sp;

//スタックの初期化
void init_stack()
{
	sp = -1;
}

//スタックにデータを格納
void push(stack_type d)
{
 	if( sp < stack_size-1)//スタックサイズより少なかったら
	{
		stack[++sp] = d;//+1してから追加
	}
	else//等しいか多かったら
	{
		fprintf(stderr, "Error : stack full \n");//スタックがいっぱい
		exit(1);
	}
}

//スタック内のデータを返す
int stack_stock()
{
	//spの初期値は-1なので+1する
	return sp+1;
}

//スタック内のデータを取り出す
stack_type pop()
{
	if( sp >= 0)//スタック内に値があったら
	{
		return stack[sp--];//取り出してから-1する
	}
	else
	{
		fprintf(stderr, "Error : stack empty \n");//スタックが空
		exit(1);
	}
}

//スタック内の値を出力
void print_stack()
{
	int i;
	printf("stack data : ");
	for(i=0;i<=sp;i++)//spの値のぶん繰り返す
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
