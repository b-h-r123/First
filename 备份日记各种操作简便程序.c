#include<stdio.h>
#include<stdlib.h>

void filecopy(FILE *to,FILE *from)
{
	char ch;
	while((ch=fgetc(from))!=EOF)
		fputc(ch,to);
}

int main()
{
	FILE *fp1,*fp2;
	if((fp1=fopen("D:\\Diary\\history.txt","r+"))==NULL)
	{
		printf("文件打开错误\n");
		return 1; 
	}
	if((fp2=fopen("D:\\Diary\\backup.dat","w"))==NULL)
	{
		printf("没有可备份的文件\n");
		fclose(fp1);
		return 1;
	}
	
	filecopy(fp2,fp1);
	fclose(fp2);
	printf("备份成功\n");
	
	fputc('\n',fp1);
	
	fp2=fopen("D:\\Diary\\today.txt","r");
	filecopy(fp1,fp2);
	printf("添加成功\n");
	fclose(fp1);
	fclose(fp2);
	
	fp1 = fopen("D:\\Diary\\today.txt", "w");
    fclose(fp1);
    printf("today.txt已清空\n");
		
	return 0;
}
