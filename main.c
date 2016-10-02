/*
	引言
	
  .此为自动缩进之源码
  .实现代码格式自动添加
  .用户可自定义代码风格
  .用户可将自己的代码风格存到文件
  .支持C
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
	struct code *prior;
	wchar_t data;
	struct code *next;
}code;
typedef struct indent
{
	wchar_t *data;
	struct indent *next;
}indent;
int main()
{
	code *codehead=NULL;
	code *indenthead=NULL;
	char filename[256];
	int i=0;
	int j=0;
	FILE *fp;
	//打开文件
	printf("文件名：");
	scanf("%256s",filename);
	char ch;
	if( (fp = fopen(filename,"r+")) == NULL)
		{
			printf("文件打开错误");
			getchar();
			exit(1);
		}
		
	//读取文件
	else//如果没出错就读文件
		{
			code *codehead=NULL;
			code *p,*temp;
			while(ch=fgetc(fp)!=EOF)
				{
					if(codehead == NULL)
					{
						p = (code*)malloc(sizeof(code));
						codehead=p;
						p -> prior = NULL;
					}
					temp=p;
					p->data=ch;
					p->next = (code*)malloc(sizeof(code));
					p=p->next;
					p->prior=temp;
				}
			free(p);
			p=NULL;
		}
	//存注释
	i=0;
	code *code_t , *indent_t , *cat , *free_t;
	code_t = codehead;
	while(code_t->next != NULL)
	{
		if(code_t -> next -> data == '/' && code_t -> next -> next ->data == '/')
		{
			temp = (code*)malloc(sizeof(code));
			temp -> data =INENTFLAG;
			code_t -> next = temp;
			temp -> next = code_t -> next;
			temp -> prior = code_t;
			cat = code_t;
			code_t = code_t -> next;

			indentstr = (wchar_t*)calloc(INDENSIZE,sizeof(wchar_t));
 
			while( ! (code_t ->next -> data != '\n')//这个字符是不是注释的结尾
			{
				cat = code_t;
				code_t = code_t->next;
				if(indenthead == NULL)
				{
					indenthead = (indent*)malloc(sizeof(indent));
				}
	
				if(i<=INDENTSIZE)
					*(indentstr + i++) = code_t -> data;//此处改为用字符串暂存
	
				free_t = code_t;
				code_t = code_t->next;
				free(free_t);
			}
			indent_t -> data = indentstr;
			indent_t->next = (indent*)malloc(sizeof(indent));
			indent_t = indent_t->next;

			cat->next = code_t;//此时code_t已经跳过了注释，cat连接到代码。
			i=0;

		}
	}
		//以上重构完毕
		if(code_t->next->data == '/' && code_t->next-next->data == '*')//从" /* "到" */ "都是注释
		{

			temp = (code*)malloc(sizeof(code));
			temp -> data =INENTFLAG;
			code_t -> next = temp;
			temp -> next = code_t -> next;
			temp -> prior = code_t;
			cat = code_t;
			code_t = code_t -> next;

			indentstr = (wchar_t*)calloc(INDENSIZE,sizeof(wchar_t));

			while( ! (code_t ->next -> data == '*' && code_t -> next -> next -> data== '/'))//这个字符是不是注释的结尾
			{
				cat = code_t;
				code_t = code_t->next;
				if(indenthead == NULL)
				{
					indenthead = (indent*)malloc(sizeof(indent));
				}
				if(i<=INDENTSIZE)
					*(indentstr + i++) = code_t -> data;//此处改为用字符串暂存
				free_t = code_t;
				code_t = code_t->next;
				free(free_t);
			}
			indent_t -> data = indentstr;
			indent_t->next = (indent*)malloc(sizeof(indent));
			indent_t = indent_t->next;

			cat->next = code_t;//此时code_t已经跳过了注释，cat连接到代码。
			i=0;
		}
		code_t = code_t -> next;
	}//现在有序存储着所有注释，添加时再有序释放
	
/*删除部分*///////////////////////////////
	
	//删回车
	code_t = codehead;
	while(code_t -> next != NULL)
	{
		if(code_t->next->data == '\n')
		{
			free_t= code_t->next;
			code_t -> next =code_t ->next ->next;
			free(free_t);
		}
		code_t = code_t -> next;
	}
	//删缩进 
	i=0;
	//以上重构完毕
	/*
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
	*/
		
}
