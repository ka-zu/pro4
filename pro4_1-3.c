#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include "stack.h"
#define BUFLEN 100

int main()
{
	int ch, chst, err, i;
	char buf[BUFLEN];
	init_stack();
	err = 0;
	fprintf(stdout, "Please enter c program : \n");
	while(1)
	{
		fgets(buf,sizeof(buf),stdin);
		if(buf[1]=='\0')
		{
			if(stack_stock() <= 0 && err == 0)
			{
				fprintf(stdout,"Parentheses are correct !! \n");
			}
			else
			{
				fprintf(stdout,"Parentheses error !! \n");
			}
			break;
		}
		//
		for(i=0;i<sizeof(buf);i++)
		{
			switch(buf[i])
			{
			case '[': case '{': case '(':
				chst = buf[i];//入れた値を保存
				push(buf[i]);//プッシュ
				break;
			case ']': case '}': case ')':
				chst = buf[i];//値を保存
				push(buf[i]);//プッシュ
				/*閉じカギカッコの場合
				その前は同じ種類の開き括弧*/
				if(chst == stack[sp])
				{
					pop();//括弧の組を出す
					pop();
				}
				else//そうでない場合
				{
					err = 1;
				}
				break;
			default://それ以外
				break;
			}
		}
	}
}
