//j1422 �y�� stack.h

stack_type stack[stack_size];
int sp;

//�X�^�b�N�G�f�B�^�̏�����
void init_stack()
{
	sp = -1;
}

//�X�^�b�N�Ƀf�[�^���i�[
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

//�X�^�b�N���̃f�[�^����Ԃ�
int stack_stock()
{
	//�����ō��
	return sp+1;
}

//�X�^�b�N�̃f�[�^�����o��
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

//�X�^�b�N���̃f�[�^���o��
void print_stack()
{
	//�����͎����ō��
	int i;
	printf("stack data : ");
	for(i=0;i<=sp;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
