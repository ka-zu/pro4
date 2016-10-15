//j1422 土井　kadai2-1
#include <stdio.h>
#include <stdlib.h>
#define stack_type char
#define stack_size 100
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
			if(ch >= 97 && ch <= 122 && pch == ' ')
			{
				small = 1;
				//push(ch);
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
			while(stack_stock()>0)
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
