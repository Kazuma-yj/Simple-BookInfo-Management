#include "book.h"
int main()
{
	int choose;
	BOOK *head;
	
	//�����������ͷָ�� 
	head=creatlinkedlist();
	
	//���������� 
	head=sort(head);
	
	
	do
	{	 
		choose=menu();	//�Ӳ˵���ȡָ��
		switch(choose)
		{
			case 1: browse(head);break;	
			case 2: search(head);break;
			case 3: head=add(head);break;
			case 4: head=_delete(head);break;
			case 5: change(head);break;
			case 6: borrow(head);break; 
			case 7: back(head);break; 
		} 
		printf("\n\n�˳�ϵͳ������0, ��������������1 ��");
		while(scanf("%d",&choose)==0||choose!=choose*choose)
		{printf("\n���뷢���������������룺");rewind(stdin);}
	
	}while(choose==1);
	
	//ѯ���Ƿ񱣴浽�ļ� 
	printf("    \n\n������������0,   ���浽�ļ�������1 ��");
	while(scanf("%d",&choose)==0||choose!=choose*choose)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	
	if(choose==0)
	{
		exit(1);
	 } 
	else
	{
		//���浽�ļ�
		save(head,"Book Information.txt","w"); 
	}
	
	return 0;
}
