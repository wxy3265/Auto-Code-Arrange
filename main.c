/*
	����
	
  .��Ϊ�Զ�����֮Դ��
  .ʵ�ִ����ʽ�Զ����
  .�û����Զ��������
  .�û��ɽ��Լ��Ĵ�����浽�ļ�
  .֧��C��C++
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
					p.data=ch;
					p=p->next=(code*)malloc(sizeof(code));
				}
			free(p);
			p=NULL;
		}
	//��ע��
	i=0;
	code *t , *p;
	t=p=head;
	while(t->next != NULL)
	{
		if(t->data == '/' && t->data == '/')
		{
			j=t;

			while(t->data != '\n')//��"//"����β����ע��
			{
				//y��ʾÿ�е����ݵ�����,�������tp��
				//ԭ��ע���ÿո񸲸�
				t=t->next//�����һ��ע���ַ�
			}
			y=0;//������ʼ�������
			x++;//������һ��ע��
			code[t] = INDENTFLAG;//ע�͵Ŀ�ʼ���һ����־���Ա��Ժ���ӡ�
			t=j;//����ע��
		}
		if(code[t] == '/' && code[t+1] == '*')//��" /* "��" */ "����ע��
		{
			j=t;
			while( ! (code[j] == '*' && code[j+1] == '/'))//����ַ��ǲ���ע�͵Ľ�β
			{
				tp[x][y++] = code[j];//y��ʾÿ�� ���ݵ�����,�������tp��
				code[j] = SPACE;//ԭ��ע���ÿո񸲸�
				j++;//�����һ��ע���ַ�
			}
			y=0;//������ʼ�������
			x++;//������һ��ע��
			code[t] = INDENTFLAG;//ע�͵Ŀ�ʼ���һ����־���Ա��Ժ���ӡ�
			t=j;//����ע��
		}
		t++;
	}//tp��������洢������ע�ͣ����ʱ�������ͷ�
	
/*ɾ������*///////////////////////////////
	
	//ɾ�س�
	for(j=0;j<strlen(code);j++)
		{
			if(code[j]!='\n')
				{
					temp1[j]=code[j];
				}
		}//ԭ���ǵ�ǰ�ַ�������ǻس����͸�temp1�������������ܡ�
	//ɾ����
	memset(code,'\0',sizeof(code)-1);//����
	strcpy(code,temp1);
	i=0;
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
