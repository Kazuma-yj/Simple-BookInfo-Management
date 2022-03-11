#include "book.h"
//�������ܣ�������� 
void browse(BOOK *head)
{
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("���ȫ��ͼ����Ϣ��\n");
	BOOK *p;
	p=head;
	while(p!=NULL)
	{	
		putout(p);//��ӡһ����� 
		p=p->ptr;
	}
}

//�������ܣ�ģ������
void search(BOOK *head)
{
	BOOK *p;
	p=head; 
	char in[50]; 
	char id[50];
	int sgn0;
	int choose; 
	 
	printf("\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("������ID��������������������Ϣ��\n\n");
	printf("(���������ո񻻳��»�������)\n\n��");
	
	scanf("%s",in);//��ȡ�û����� 
	
	sgn0=0;
	while(p!=NULL)/*��һ��ѭ������������*/ 
	{
		sprintf(id,"%d",p->id);
		
		if(strcmp(id,in)==0)
		{
			sgn0=1;
			putout(p);//��ӡһ����� 
		}
		else if(strstr(p->bookname,in)!=NULL)
		{
			sgn0=1;
			putout(p);//��ӡһ����� 
		}
		else if(strstr(p->author,in)!=NULL)
		{
			sgn0=1;
			putout(p);
		}
		else if(strstr(p->publisher,in)!=NULL)
		{
			sgn0=1;
			putout(p);
		}
		p=p->ptr;
	}
	if(sgn0==0)
	{
		printf("��δ���ҵ������Ϣ\n\n"); 
		printf("��������������1���˳�����������0��");
		while(scanf("%d",&choose)==0||choose<0||choose>1) 
		{printf("\n���뷢���������������룺");rewind(stdin);}
		switch (choose)
		{
			case 0:break;
			case 1:search(head);//�ݹ���� 
		}
	}
}

//�������ܣ��������
BOOK *add(BOOK *head)
{
	BOOK *p=head;
	
	//��ý��ĸ��� 
	int num=0;
	while(p!=NULL)
	{
		num+=1;
		p=p->ptr;
	}
	
	p=(BOOK*)malloc(LEN);//Ϊp�����ڴ� 
	printf("\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("����������ͼ�������Ϣ��\n\n");
	printf("(���������ո񻻳��»�������)\n\n\n");
	printf("ͼ���ţ�      %d",1000001+num);
	p->id=100001+num;
	
	p=getin(p);//������� 
	
	printf("\n\n����Ϊ�������ݣ�"); 
	
	putout(p);//��ӡһ����� 
	
	p->ptr=head;
	head=p;
	
	head=sort(head);//�������������� 
 
	return(head);
} 

//�������ܣ�ɾ�����
BOOK *_delete(BOOK *head)
{
	BOOK *p1,*p2,*p0;
	p1 = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 

	if(head==NULL)
	{
		printf("\n����пտ���Ҳ......");
		return; 
	}
	
	int id;
	printf("\n�������ɾ���鼮��ID��");
	while(scanf("%d",&id)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	
	if(head->id==id)
	{
		head=head->ptr;
		printf("\nID%d�鼮�ɹ��������ɾ��"); 
		
		p0=head;
		while(p0!=NULL)
		{
			p0->id-=1;
			p0=p0->ptr;
		}
	}
	else
	{
		p2=head;
		p1=head->ptr;
		/*while(p1->id!=id&&p1!=NULL) ��p1Ϊ��ָ��ʱ������ָ��ṹ��ĳ�Ա ��������Ч��ַ������*/
		while(p1!=NULL&&p1->id!=id) /*��һ���ж�˳�򣬵�p1Ϊ��ָ��ʱ��ֱ�ӽ���ѭ����p1->id����ִ�� */
		{
			p1=p1->ptr;
			p2=p2->ptr;
		}
		if(p1==NULL)
		{
			printf("\nδ�ҵ����������ID"); 
		}
		else
		{
			p2->ptr=p1->ptr;
			printf("\nID%d�鼮�ɹ��������ɾ��",id);
			
			p0=p1->ptr;
			while(p0!=NULL)
			{
				p0->id-=1;
				p0=p0->ptr;
			}
			
		}
	}
	return(head);
		
 } 
 
 //�������ܣ��޸Ľ���ֵ
 void change(BOOK *head)
 {
 	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 

	if(head==NULL)
	{
		printf("\n����пտ���Ҳ......");
		return; 
	}
	
	int id;
	printf("\n��������޸��鼮��ID��");
	while(scanf("%d",&id)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) /*��p1Ϊ��ָ��ʱ��ֱ�ӽ���ѭ����p1->id����ִ�� */
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\nδ�ҵ����������ID"); 
	}
	else
	{
		p=getin(p);//������� 

		printf("\n\n����Ϊ���º����ݣ�"); 
		
		putout(p);//��ӡһ����� 
	}
	
} 

//�������ܣ�����
void borrow(BOOK *head)
{
	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	
	if(head==NULL)
	{
		printf("\n����пտ���Ҳ......\n\n");
		return; 
	}
	
	int id;
	printf("\n������������鼮��ID��");
	while(scanf("%d",&id)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) //��p1Ϊ��ָ��ʱ��ֱ�ӽ���ѭ����p1->id����ִ�� 
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\nδ�ҵ����������ID"); 
	}
	else if(p->stock==0)
	{
		printf("\n�鼮���޿��");
	}
	else
	{
		p->out+=1;
		p->stock-=1;
		printf("\n�鼮���ĳɹ�\n"); 
		printf("����Ŀǰ�����Ϊ��%d\n",p->stock);
		printf("����Ŀǰ�����Ϊ��%d",p->out);
	}
} 

//�������ܣ��黹
void back(BOOK *head)
{
	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	
	if(head==NULL)
	{
		printf("\n�����鼮��Ϣ����Ӧ���ǻ���ͼ�����");
		return; 
	}
	
	int id;
	printf("\n��������黹�鼮��ID��");
	while(scanf("%d",&id)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) //��p1Ϊ��ָ��ʱ��ֱ�ӽ���ѭ����p1->id����ִ�� 
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\nδ�ҵ����������ID"); 
	}
	else if(p->out==0)
	{
		printf("\n...��û���鼮��裬��Ӧ���ǻ���ͼ�����");
	}
	else
	{
		p->out-=1;
		p->stock+=1; 
		printf("\n�鼮�黹�ɹ�\n");
		printf("����Ŀǰ�����Ϊ��%d\n",p->stock);
		printf("����Ŀǰ�����Ϊ��%d",p->out);
	}
}
