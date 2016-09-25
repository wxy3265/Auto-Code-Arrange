/*
	引言
	
  .此为自动缩进之源码
  .实现代码格式自动添加
  .用户可自定义代码风格
  .用户可将自己的代码风格存到文件
  .支持C和C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define INDENTFLAG 26
#define SPACE ' '
#define INDENTREPLACE
#define COMMENT_SIZE 100
typedef struct code
{
	char data;
	char *next;
}code
typedef struct indent
{
	wchar_t data[1000];
	char *next;
}
struct indent
int main()
{
	code *codehead=NULL;
	code *indenthead=NULL
	char filename[256];
	int i=0;
	int j=0;
	FILE *fp;
	//打开文件
	printf("文件名：");
	gets(filename);
	if(fp=fopen(filename,"r+")==NULL)
		{
			printf("文件打开错误");
			getchar();
			exit(1);
		}
		
	//读取文件
	else//如果没出错就读文件
		{
			code *p=NULL;
			while(ch=fgetc(fp)!=EOF)
				{
					if(head == NULL)
					{
						p=(code*)malloc(sizeof(code));
						head=p;
					}
					p.data=ch;
					p=p->next=(code*)malloc(sizeof(code));
				}
			free(p);
			p=NULL;
		}
	//存注释
	i=0;
	code *t , *p;
	t=p=head;
	while(t->next != NULL)
	{
		if(t->data == '/' && t->data == '/')
		{
			j=t;

			while(t->data != '\n')//从"//"到行尾都是注释
			{
				//y表示每行的内容的坐标,挨个存进tp。
				//原有注释用空格覆盖
				t=t->next//检查下一个注释字符
			}
			y=0;//内容起始坐标归零
			x++;//跳到下一个注释
			code[t] = INDENTFLAG;//注释的开始添加一个标志，以便以后添加。
			t=j;//跳过注释
		}
		if(code[t] == '/' && code[t+1] == '*')//从" /* "到" */ "都是注释
		{
			j=t;
			while( ! (code[j] == '*' && code[j+1] == '/'))//这个字符是不是注释的结尾
			{
				tp[x][y++] = code[j];//y表示每行 内容的坐标,挨个存进tp。
				code[j] = SPACE;//原有注释用空格覆盖
				j++;//检查下一个注释字符
			}
			y=0;//内容起始坐标归零
			x++;//跳到下一个注释
			code[t] = INDENTFLAG;//注释的开始添加一个标志，以便以后添加。
			t=j;//跳过注释
		}
		t++;
	}//tp现在有序存储着所有注释，添加时再有序释放
	
/*删除部分*///////////////////////////////
	
	//删回车
	for(j=0;j<strlen(code);j++)
		{
			if(code[j]!='\n')
				{
					temp1[j]=code[j];
				}
		}//原理是当前字符如果不是回车，就给temp1。否则跳过不管。
	//删缩进
	memset(code,'\0',sizeof(code)-1);//清零
	strcpy(code,temp1);
	i=0;
	while(code[i]!='\0')//错误----------------------------------------------------------------------------------------------------------------------------------------
	{	
		if(code[i] == '#' || code[i] ==  ';' 
		  || code[i] == '(' || code[i] == ')'
		  || code[i] == '{' || code[i] == '}'
		  || code[i] == ',' || code[i] == ';'
		  || code[i] == '#' || code[i] == '>'
		  || code[i] == '=' )//删缩进关键字:双向删除
		{
			for(j = i-1 ; isspace(code[j]) ; j++)
			{
				code[j] = INDENTREPLACE;//将注释替换为特定字符
			}
			for(j = i-1 ; isspace(code[j]) ; j--)
			{
				code[j] = INDENTREPLACE;//将注释替换为特定字符
			}
		}
		if(code[i] == '=' && code[i+1] == '=')
		{
			for(j = i-1; isspace[code[j]]; j--)
			{
				code[j] = INDENTREPLACE;
			}
			for(j = i+2; isspace[code[j]]; j++)
			{
				code[j] = INDENTREPLACE;
			}
		//单向删除（向右）
		if(code[i] == '<')
			for(j = i-1 ; isspace(code[j]); j--)
			{
				code[j] = INDENTREPLACE;
			}
		//替换完毕
		i++;
	}
	memset(temp1,'\0',sizeof(temp1)-1);
	for(i=0;i<=strlen[code])

		
}
