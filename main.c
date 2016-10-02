/*
	����
	
  .��Ϊ�Զ�����֮Դ��
  .ʵ�ִ����ʽ�Զ����
  .�û����Զ��������
  .�û��ɽ��Լ��Ĵ�����浽�ļ�
  .֧��C
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
	//���ļ�
	printf("�ļ�����");
	scanf("%256s",filename);
	char ch;
	if( (fp = fopen(filename,"r+")) == NULL)
		{
			printf("�ļ��򿪴���");
			getchar();
			exit(1);
		}
		
	//��ȡ�ļ�
	else//���û����Ͷ��ļ�
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
	//��ע��
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
 
			while( ! (code_t ->next -> data != '\n')//����ַ��ǲ���ע�͵Ľ�β
			{
				cat = code_t;
				code_t = code_t->next;
				if(indenthead == NULL)
				{
					indenthead = (indent*)malloc(sizeof(indent));
				}
	
				if(i<=INDENTSIZE)
					*(indentstr + i++) = code_t -> data;//�˴���Ϊ���ַ����ݴ�
	
				free_t = code_t;
				code_t = code_t->next;
				free(free_t);
			}
			indent_t -> data = indentstr;
			indent_t->next = (indent*)malloc(sizeof(indent));
			indent_t = indent_t->next;

			cat->next = code_t;//��ʱcode_t�Ѿ�������ע�ͣ�cat���ӵ����롣
			i=0;

		}
	}
		//�����ع����
		if(code_t->next->data == '/' && code_t->next-next->data == '*')//��" /* "��" */ "����ע��
		{

			temp = (code*)malloc(sizeof(code));
			temp -> data =INENTFLAG;
			code_t -> next = temp;
			temp -> next = code_t -> next;
			temp -> prior = code_t;
			cat = code_t;
			code_t = code_t -> next;

			indentstr = (wchar_t*)calloc(INDENSIZE,sizeof(wchar_t));

			while( ! (code_t ->next -> data == '*' && code_t -> next -> next -> data== '/'))//����ַ��ǲ���ע�͵Ľ�β
			{
				cat = code_t;
				code_t = code_t->next;
				if(indenthead == NULL)
				{
					indenthead = (indent*)malloc(sizeof(indent));
				}
				if(i<=INDENTSIZE)
					*(indentstr + i++) = code_t -> data;//�˴���Ϊ���ַ����ݴ�
				free_t = code_t;
				code_t = code_t->next;
				free(free_t);
			}
			indent_t -> data = indentstr;
			indent_t->next = (indent*)malloc(sizeof(indent));
			indent_t = indent_t->next;

			cat->next = code_t;//��ʱcode_t�Ѿ�������ע�ͣ�cat���ӵ����롣
			i=0;
		}
		code_t = code_t -> next;
	}//��������洢������ע�ͣ����ʱ�������ͷ�
	
/*ɾ������*///////////////////////////////
	
	//ɾ�س�
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
	//ɾ���� 
	i=0;
	//�����ع����
	/*
	{	
		if(code[i] == '#' || code[i] ==  ';' 
		  || code[i] == '(' || code[i] == ')'
		  || code[i] == '{' || code[i] == '}'
		  || code[i] == ',' || code[i] == ';'
		  || code[i] == '#' || code[i] == '>'
		  || code[i] == '=' )//ɾ�����ؼ���:˫��ɾ��
		{
			for(j = i-1 ; isspace(code[j]) ; j++)
			{
				code[j] = INDENTREPLACE;//��ע���滻Ϊ�ض��ַ�
			}
			for(j = i-1 ; isspace(code[j]) ; j--)
			{
				code[j] = INDENTREPLACE;//��ע���滻Ϊ�ض��ַ�
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
		//����ɾ�������ң�
		if(code[i] == '<')
			for(j = i-1 ; isspace(code[j]); j--)
			{
				code[j] = INDENTREPLACE;
			}
		//�滻���
		i++;
	}
	memset(temp1,'\0',sizeof(temp1)-1);
	for(i=0;i<=strlen[code])
	*/
		
}
