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
					p->data=ch;
					p=p->next=(code*)malloc(sizeof(code));
				}
			free(p);
			p=NULL;
		}
	//存注释
	i=0;
	code *code_t , *indent_t , *cat *free_t;
	t=p=head;
	while(t->next != NULL)
	{
		if(code_t->next->data == '/' && code_t->next->next->data == '/')//为了让cat得到正确的地址所以提前一个字符
		{
			cat = code_t;
			code_t = code_t->next;//重回正轨
			while(code_t->data != '\n')//从"//"到行尾都是注释
			{
				if(indenthead == NULL)//存储注释字符
				{
					*indent_t = (indent *)malloc(sizeof(indent);)
					head = code_t;
				}
				indent_t->data[i++] = code_t->data;
				free_t = indent_t;//释放注释字符
				code_t = code_t->next;//检查下一个注释字符
				free(free_t);
			}
			indent_t = indent_t->next = (indent *)malloc(sizeof(indent));
			cat->next = t;//拼接链表，跳过注释
			i=0;
		}
		//以上重构完毕
		if(code_t->next->data == '/' && code_t->next->next->data == '*')//从" /* "到" */ "都是注释
		{
			cat = code_t;
			code_t = code_t->next; 
			while( ! (code_t ->next -> data == '*' && code_t -> next -> next -> data== '/'))//这个字符是不是注释的结尾
			{
				cat = code_t;
				code_t-> = code_t
				if(indenthead == NULL)
				{
					*indent_t = (indent *)malloc(sizeof(indent));
					head = code_t;
				}
				indent_t->data[i++] = code_t -> data;
				free_t = indent_t;
				code_t = code_t->next;
				free(free_t);
			}
			indent_t = indent->next = (indent *)malloc(sizeof(indent));
			cat->next = t;
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
