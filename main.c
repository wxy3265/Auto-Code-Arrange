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
	//���ļ�
	printf("�ļ�����");
	gets(filename);
	if(fp=fopen(filename,"r+")==NULL)
		{
			printf("�ļ��򿪴���");
			getchar();
			exit(1);
		}
		
	//��ȡ�ļ�
	else//���û����Ͷ��ļ�
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
	//��ע��
	i=0;
	code *code_t , *indent_t , *cat *free_t;
	t=p=head;
	while(t->next != NULL)
	{
		if(code_t->next->data == '/' && code_t->next->next->data == '/')//Ϊ����cat�õ���ȷ�ĵ�ַ������ǰһ���ַ�
		{
			cat = code_t;
			code_t = code_t->next;//�ػ�����
			while(code_t->data != '\n')//��"//"����β����ע��
			{
				if(indenthead == NULL)//�洢ע���ַ�
				{
					*indent_t = (indent *)malloc(sizeof(indent);)
					head = code_t;
				}
				indent_t->data[i++] = code_t->data;
				free_t = indent_t;//�ͷ�ע���ַ�
				code_t = code_t->next;//�����һ��ע���ַ�
				free(free_t);
			}
			indent_t = indent_t->next = (indent *)malloc(sizeof(indent));
			cat->next = t;//ƴ����������ע��
			i=0;
		}
		//�����ع����
		if(code_t->next->data == '/' && code_t->next->next->data == '*')//��" /* "��" */ "����ע��
		{
			cat = code_t;
			code_t = code_t->next; 
			while( ! (code_t ->next -> data == '*' && code_t -> next -> next -> data== '/'))//����ַ��ǲ���ע�͵Ľ�β
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
	while(code[i]!='\0')//����----------------------------------------------------------------------------------------------------------------------------------------
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

		
}
