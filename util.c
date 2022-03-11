#include "book.h"

//菜单 ：获取输入，返回指令 
int menu(void)
{
	int choose;

	printf("\n\n\n\n");
	printf("                            中华人民共和国国家典藏馆欢迎您\n"); 
	printf("                            ------------------------------\n\n\n\n\n"); 
	printf("     指令列表：\n");
	printf("     ---------\n\n\n\n");
	printf("     [1].浏览全部书籍信息            [2].查找书籍                 [3].新增书籍\n");
	printf("     --------------------            ------------                 ------------\n\n\n\n"); 
	printf("     [4].删除书籍                    [5].修改书籍信息             [6].书籍借阅\n");
 	printf("     ------------                    ----------------             ------------\n\n\n\n");
 	printf("                                     [7].书籍归还\n"); 
	printf("                                     ------------\n\n\n\n\n");
	printf("     请输入您的指令：");
	while(scanf("%d",&choose)==0||choose<1||choose>7)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	return choose;
}

//函数功能：创建链表-返回头指针
BOOK *creatlinkedlist(void)
{
	FILE *file;
	file = openfile("Book Information.txt","r");//打开文件 

	BOOK *head,*p;	
	char c[50];
	int sgn;
	head=NULL;
	p=(BOOK*)malloc(LEN);//头插法创建链表 
	sgn=fscanf(file,"%d%s%s%s%f%d%d",&p->id,p->bookname,p->author,p->publisher,&p->price,&p->stock,&p->out); 
	while(sgn==7)//利用fscanf返回值控制循环 
	{
		p->ptr=head;
		head=p;
		p=(BOOK*)malloc(LEN);
		sgn=fscanf(file,"%d%s%s%s%f%d%d",&p->id,p->bookname,p->author,p->publisher,&p->price,&p->stock,&p->out); 
	} 
	fclose(file);//关闭文件 
	return(head);
}

//函数功能：打开文件
FILE *openfile(char filename[50],char filetype[5]) 
{
	FILE *file;
	file=fopen(filename,filetype);
	if(file==NULL)
	{
		printf("openfile: Failed to open the txt file.\n");
		exit(1);
	}
//	else
//	{	printf("\nopenfile: Succeed to open the txt file.\n");}
	return(file);
}

//函数功能：保存到文件
void save(BOOK *head,char filename[50],char filetype[5])
{
	FILE*file;
	file = openfile(filename,filetype);//打开文件 
	
	BOOK *p=head;
	while(p!=NULL)
	{
		fprintf(file,"%d\n%s\n%s\n%s\n%.2f\n%d\n%d\n",
			p->id,p->bookname,p->author,p->publisher,p->price,p->stock,p->out);
		p=p->ptr;
	}
	fclose(file);
//	printf("\nsave:succeed to save the file.\n");
} 

//函数功能：排序
BOOK *sort(BOOK *head)
{
	BOOK *p,*p0,*p1,*p2,*temp,*a,*b;
	p=head;
	int i=0,j=0,num=0,sgn1=0,sgn0=0;
	//获得结点的个数 
	while(p!=NULL)
	{
		num+=1;
		p=p->ptr;
	}
	//冒泡排序 
	for(i=1;i<num;i++)
	{
		a=head;
		b=head->ptr;
		
		sgn0=0;//第一轮循环未发生交换，sgn0值为0 
		
		for(j=0;j<num-i;j++)
		{
			sgn1=0;//两个结点未发生交换时，sgn1值为0 
			
			if((a->id)>(b->id))//将结点按id的升序排列 
			{
				sgn1=1;//发生交换，sgn1，sgn0值更改为1 
				sgn0=1;
				
				if(j==0)//1、2结点的交换涉及到头指针，单独操作 
				{	
					p0=head;
					p1=p0->ptr;//p0,p1,p2指向前三个结点 
					p2=p1->ptr;
					
					head=p1;
					p0->ptr=p2;//前两个结点交换 
					p1->ptr=p0;
					
					temp=p1;
					p1=p0;     // 恢复p0,p1,p2的顺序
					p0=temp;
				}
				else
				{					
					p0->ptr=p2;
					p1->ptr=p2->ptr;//后两个结点交换
					p2->ptr=p1;
					
					temp=p1;
					p1=p2;     // 恢复p0,p1,p2的顺序
					p2=temp;
					
					p0=p0->ptr;
					p1=p1->ptr;//p0,p1,p2向后位移一个结点 
					p2=p2->ptr;
				}
			}
			
			if(sgn1==1)//若两个结点发生交换，恢复a,b的顺序 
			{
				temp=a;
				a=b;
				b=temp;
			}
			a=a->ptr;
			b=b->ptr;//判断完两个结点后，a,b向后位移一个结点 
			
		}
		
		if(sgn0==0)
		{
			break;//如果第一轮没有发生交换，排序结束 
		} 
	}
	return(head);
 } 
 
 //函数功能：获得输入（书名 ，作者，出版社，价格，库存，借出） 
 BOOK *getin(BOOK *p)
 {
 	printf("\n\n请输入书名：    "); 
	scanf("%s",p->bookname);
	while(strlen(p->bookname)>=50)
	{	
		printf("\n输入过长，请重新输入："); //防止字符数组长度溢出 
		scanf("%s",p->bookname);
	}
	printf("\n请输入作者：    "); 
	scanf("%s",p->author);
	while(strlen(p->author)>=50)
	{	
		printf("\n输入过长，请重新输入："); 
		scanf("%s",p->author);
	}
	printf("\n请输入出版社：  "); 
	scanf("%s",p->publisher);
	while(strlen(p->publisher)>=50)
	{	
		printf("\n输入过长，请重新输入："); 
		scanf("%s",p->publisher);
	}
	printf("\n请输入建议售价："); 
	while(scanf("%f",&p->price)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}//误输字符串后，字符串会停留在缓冲区，
	printf("\n请输入库存量：  "); 
	while(scanf("%d",&p->stock)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}//清空缓冲区防止陷入死循环 
	printf("\n请输入借出数：  "); 
	while(scanf("%d",&p->out)!=1)
	{printf("\n输入发生错误，请重新输入：");rewind(stdin);}
	
	return (p);
 }
 
 //函数功能：打印一个结点 
 void putout(BOOK *p)
 {
 	printf("\n\n图书编号：%d\n图书名称：%s\n作者：    %s\n出版社：  %s\n建议售价：%.2f\n库存量：  %d\n借出数：  %d",
		p->id,p->bookname,p->author,p->publisher,p->price,p->stock,p->out);
 }
