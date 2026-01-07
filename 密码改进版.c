#include<stdio.h>
int main()
{
	char ch;
	printf("Ã÷ÎÄ:"); 
	ch = getchar();
	printf("ÃÜÎÄ:");
	while(ch != '\n')
	{
		if((ch>='A' && ch<='z') || (ch>='a' && ch<='z'))
		{
			ch+=4;
			if((ch>='Z' && ch<='Z'+4) || (ch>='z' && ch<='z'+4))
			{
				ch-=26;
			}
		}
		putchar(ch);
		ch = getchar();
		
	 } 
	 printf("\n");
	return 0;
}
