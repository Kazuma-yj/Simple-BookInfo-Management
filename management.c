#include "book.h"
//函数功能：浏览链表 
void browse(BOOK *head)
{
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("浏览全部图书信息：\n");
	BOOK *p;
	p=head;
	while(p!=NULL)
	{	
		putout(p);//打印一个结点 
		p=p->ptr;
	}
}

//函数功能：模糊查找
void search(BOOK *head)
{
	BOOK *p;
	p=head; 
	char in[50]; 
	char id[50];
	int sgn0;
	int choose; 
	 
	printf("\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("请输入ID，书名，出版社等相关信息：\n\n");
	printf("(建议您将空格换成下划线输入)\n\n：");
	
	scanf("%s",in);//获取用户输入 
	
	sgn0=0;
	while(p!=NULL)/*第一层循环，遍历链表*/ 
	{
		sprintf(id,"%d",p->id);
		
		if(strcmp(id,in)==0)
		{
			sgn0=1;
			putout(p);//打印一个结点 
		}
		else if(strstr(p->bookname,in)!=NULL)
		{
			sgn0=1;
			putout(p);//打印一个结点 
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
		printf("并未查找到相关信息\n\n"); 
		printf("继续查找请输入1，退出查找请输入0：");
		while(scanf("%d",&choose)==0||choose<0||choose>1) 
		{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
		switch (choose)
		{
			case 0:break;
			case 1:search(head);//递归调用 
		}
	}
}

//函数功能：新增结点
BOOK *add(BOOK *head)
{
	BOOK *p=head;
	
	//获得结点的个数 
	int num=0;
	while(p!=NULL)
	{
		num+=1;
		p=p->ptr;
	}
	
	p=(BOOK*)malloc(LEN);//为p分配内存 
	printf("\n\n-----------------------------------------------------------------------------------\n\n"); 
	printf("请输入新增图书相关信息：\n\n");
	printf("(建议您将空格换成下划线输入)\n\n\n");
	printf("图书编号：      %d",1000001+num);
	p->id=100001+num;
	
	p=getin(p);//获得输入 
	
	printf("\n\n以下为新书数据："); 
	
	putout(p);//打印一个结点 
	
	p->ptr=head;
	head=p;
	
	head=sort(head);//将链表重新排序 
 
	return(head);
} 

//函数功能：删除结点
BOOK *_delete(BOOK *head)
{
	BOOK *p1,*p2,*p0;
	p1 = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 

	if(head==NULL)
	{
		printf("\n书库中空空如也......");
		return; 
	}
	
	int id;
	printf("\n请输入待删除书籍的ID：");
	while(scanf("%d",&id)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	
	if(head->id==id)
	{
		head=head->ptr;
		printf("\nID%d书籍成功从书库中删除"); 
		
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
		/*while(p1->id!=id&&p1!=NULL) 当p1为空指针时不可以指向结构体的成员 ！！！无效地址！！！*/
		while(p1!=NULL&&p1->id!=id) /*换一下判断顺序，当p1为空指针时会直接结束循环，p1->id不会执行 */
		{
			p1=p1->ptr;
			p2=p2->ptr;
		}
		if(p1==NULL)
		{
			printf("\n未找到您所输入的ID"); 
		}
		else
		{
			p2->ptr=p1->ptr;
			printf("\nID%d书籍成功从书库中删除",id);
			
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
 
 //函数功能：修改结点的值
 void change(BOOK *head)
 {
 	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 

	if(head==NULL)
	{
		printf("\n书库中空空如也......");
		return; 
	}
	
	int id;
	printf("\n请输入待修改书籍的ID：");
	while(scanf("%d",&id)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) /*当p1为空指针时会直接结束循环，p1->id不会执行 */
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\n未找到您所输入的ID"); 
	}
	else
	{
		p=getin(p);//获得输入 

		printf("\n\n以下为更新后数据："); 
		
		putout(p);//打印一个结点 
	}
	
} 

//函数功能：借阅
void borrow(BOOK *head)
{
	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	
	if(head==NULL)
	{
		printf("\n书库中空空如也......\n\n");
		return; 
	}
	
	int id;
	printf("\n请输入待借阅书籍的ID：");
	while(scanf("%d",&id)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) //当p1为空指针时会直接结束循环，p1->id不会执行 
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\n未找到您所输入的ID"); 
	}
	else if(p->stock==0)
	{
		printf("\n书籍暂无库存");
	}
	else
	{
		p->out+=1;
		p->stock-=1;
		printf("\n书籍借阅成功\n"); 
		printf("该书目前库存量为：%d\n",p->stock);
		printf("该书目前借出数为：%d",p->out);
	}
} 

//函数功能：归还
void back(BOOK *head)
{
	BOOK *p = head;
	printf("\n\n\n-----------------------------------------------------------------------------------\n\n"); 
	
	if(head==NULL)
	{
		printf("\n并无书籍信息，您应该是还错图书馆了");
		return; 
	}
	
	int id;
	printf("\n请输入待归还书籍的ID：");
	while(scanf("%d",&id)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	

	while(p!=NULL&&p->id!=id) //当p1为空指针时会直接结束循环，p1->id不会执行 
	{
		p=p->ptr;
	}
	if(p==NULL)
	{
		printf("\n未找到您所输入的ID"); 
	}
	else if(p->out==0)
	{
		printf("\n...并没有书籍外借，您应该是还错图书馆了");
	}
	else
	{
		p->out-=1;
		p->stock+=1; 
		printf("\n书籍归还成功\n");
		printf("该书目前库存量为：%d\n",p->stock);
		printf("该书目前借出数为：%d",p->out);
	}
}
