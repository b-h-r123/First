#include<stdio.h>
int main()
{
	char ch;
	printf("Ã÷ÎÄ:");
	ch = getchar();
	printf("ÃÜÎÄ:");
	while(ch != '\n')
	{
		ch = getchar();
		if((ch>'A' && ch<'W') || (ch>'a' && ch<'w'))
		{
			ch+=4;
			putchar(ch);
			
		}
		else if((ch > 'V' && ch <= 'Z') || (ch > 'v' && ch <= 'z'))
		{
			ch-=22;
			putchar(ch);
		}
		else
		{
			putchar(ch);
		}
	}
	return 0;
}
