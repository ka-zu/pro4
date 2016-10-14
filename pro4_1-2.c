//j1422 土井　kadai2-1
#include <stdio.h>
#include <stdlib.h>
#define stach_type char
#include "stack.h"
int main()
{
  int ch, pch, small;
  small = 0;
  init_stack();
  fprintf(stdout, "Please enter English text.:\n");
  pch = "";
  while((ch = getchar()) != '\n')
  {
    if(ch != '')
    {
      if(ch >= 'a' && ch <= 'z' && pch = ' ')
      {
        push(ch);
      }else{
        fprintf(stdout, "%c",pop() );
      }
    }else{
      printf(" ");
    }pch = ch;
  }
  while(stack_stock()>0)
  {
    fprintf(stdout, "%c",pop() );
  }
  fprintf(stdout, "\n");
}
