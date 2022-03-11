#include "book.h"
int main()
{
	int choose;
	BOOK *head;
	
	//创建链表，获得头指针 
	head=creatlinkedlist();
	
	//将链表排序 
	head=sort(head);
	
	
	do
	{	 
		choose=menu();	//从菜单获取指令
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
		printf("\n\n退出系统请输入0, 继续操作请输入1 ：");
		while(scanf("%d",&choose)==0||choose!=choose*choose)
		{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	
	}while(choose==1);
	
	//询问是否保存到文件 
	printf("    \n\n不保存请输入0,   保存到文件请输入1 ：");
	while(scanf("%d",&choose)==0||choose!=choose*choose)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	
	if(choose==0)
	{
		exit(1);
	 } 
	else
	{
		//保存到文件
		save(head,"Book Information.txt","w"); 
	}
	
	return 0;
}
