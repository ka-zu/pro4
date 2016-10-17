//j1422 土井　kadai2-1
#include <stdio.h>
#include <stdlib.h>
#define stack_type char
#define stack_size 100
#define format "%c"
#include "stack.h"
int main()
{
	int ch, pch, small;
	small = 0;
	init_stack();
	fprintf(stdout, "Please enter English text:\n");
	pch = ' ';
	while((ch = getchar()) != '\n')
	{
		if(ch != ' ')
		{
			if(ch >= 97 && ch <= 122 && pch == ' ')//頭文字がa(97)~z(122)のとき
			{
				small = 1;//小文字フラグ
			}else if(pch == ' '){
				small = 0;
			}

			if(small==1)
			{
				push(ch);
			}else if(small == 0){
				printf("%c",ch);
			}

		}else{
			while(stack_stock()>0)//小文字の単語がプッシュし終わったら
			{
				fprintf(stdout, "%c",pop() );
			}
			printf(" ");
		}pch = ch;
	}
	while(stack_stock()>0)
	{
		fprintf(stdout, "%c",pop() );
	}
	fprintf(stdout, "\n");
}
