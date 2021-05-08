#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
int countc(char*file);
int countw(char*file);
int main(int argc, char *argv[])
{
	char data;
	FILE *fb=fopen(argv[2],"r");
	if(!fb)
	{
		printf("文件读取失败\n");
		return -1;
	}
	if(!strcmp(argv[1],"-c"))
	{
		countc(argv[2]);
	}
	else if(!strcmp(argv[1],"-w"))
	{
		countw(argv[2]);
	}
	else
	{
		printf("输入出错\n");
	}
	return 0;
}
int countc(char*file)
{
	FILE *fb;
	fb=fopen(file,"r");
	char temp;
    int num = 0;
    temp = fgetc(fb); 
    while( temp != EOF )
	{
		temp = fgetc(fb);
    	num++;
    }
	printf("该文本文件的字符数为：%d\n",num);
}
int countw(char*file)
{
	FILE *fb=fopen(file,"r");
	int w = 0;
    char a = fgetc(fb);
	while(a!= EOF)
	{
		if((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
		{
				w++;
			while((a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9'))
			{
				a =fgetc(fb);
            }
        }
		else
		{
			a =fgetc(fb);
		}
	}
		printf("该文本文件的单词数为：%d\n",w);
}
