#include "book.h"

//�˵� ����ȡ���룬����ָ�� 
int menu(void)
{
	int choose;

	printf("\n\n\n\n");
	printf("                            �л����񹲺͹����ҵ�عݻ�ӭ��\n"); 
	printf("                            ------------------------------\n\n\n\n\n"); 
	printf("     ָ���б�\n");
	printf("     ---------\n\n\n\n");
	printf("     [1].���ȫ���鼮��Ϣ            [2].�����鼮                 [3].�����鼮\n");
	printf("     --------------------            ------------                 ------------\n\n\n\n"); 
	printf("     [4].ɾ���鼮                    [5].�޸��鼮��Ϣ             [6].�鼮����\n");
 	printf("     ------------                    ----------------             ------------\n\n\n\n");
 	printf("                                     [7].�鼮�黹\n"); 
	printf("                                     ------------\n\n\n\n\n");
	printf("     ����������ָ�");
	while(scanf("%d",&choose)==0||choose<1||choose>7)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	return choose;
}

//�������ܣ���������-����ͷָ��
BOOK *creatlinkedlist(void)
{
	FILE *file;
	file = openfile("Book Information.txt","r");//���ļ� 

	BOOK *head,*p;	
	char c[50];
	int sgn;
	head=NULL;
	p=(BOOK*)malloc(LEN);//ͷ�巨�������� 
	sgn=fscanf(file,"%d%s%s%s%f%d%d",&p->id,p->bookname,p->author,p->publisher,&p->price,&p->stock,&p->out); 
	while(sgn==7)//����fscanf����ֵ����ѭ�� 
	{
		p->ptr=head;
		head=p;
		p=(BOOK*)malloc(LEN);
		sgn=fscanf(file,"%d%s%s%s%f%d%d",&p->id,p->bookname,p->author,p->publisher,&p->price,&p->stock,&p->out); 
	} 
	fclose(file);//�ر��ļ� 
	return(head);
}

//�������ܣ����ļ�
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

//�������ܣ����浽�ļ�
void save(BOOK *head,char filename[50],char filetype[5])
{
	FILE*file;
	file = openfile(filename,filetype);//���ļ� 
	
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

//�������ܣ�����
BOOK *sort(BOOK *head)
{
	BOOK *p,*p0,*p1,*p2,*temp,*a,*b;
	p=head;
	int i=0,j=0,num=0,sgn1=0,sgn0=0;
	//��ý��ĸ��� 
	while(p!=NULL)
	{
		num+=1;
		p=p->ptr;
	}
	//ð������ 
	for(i=1;i<num;i++)
	{
		a=head;
		b=head->ptr;
		
		sgn0=0;//��һ��ѭ��δ����������sgn0ֵΪ0 
		
		for(j=0;j<num-i;j++)
		{
			sgn1=0;//�������δ��������ʱ��sgn1ֵΪ0 
			
			if((a->id)>(b->id))//����㰴id���������� 
			{
				sgn1=1;//����������sgn1��sgn0ֵ����Ϊ1 
				sgn0=1;
				
				if(j==0)//1��2���Ľ����漰��ͷָ�룬�������� 
				{	
					p0=head;
					p1=p0->ptr;//p0,p1,p2ָ��ǰ������� 
					p2=p1->ptr;
					
					head=p1;
					p0->ptr=p2;//ǰ������㽻�� 
					p1->ptr=p0;
					
					temp=p1;
					p1=p0;     // �ָ�p0,p1,p2��˳��
					p0=temp;
				}
				else
				{					
					p0->ptr=p2;
					p1->ptr=p2->ptr;//��������㽻��
					p2->ptr=p1;
					
					temp=p1;
					p1=p2;     // �ָ�p0,p1,p2��˳��
					p2=temp;
					
					p0=p0->ptr;
					p1=p1->ptr;//p0,p1,p2���λ��һ����� 
					p2=p2->ptr;
				}
			}
			
			if(sgn1==1)//��������㷢���������ָ�a,b��˳�� 
			{
				temp=a;
				a=b;
				b=temp;
			}
			a=a->ptr;
			b=b->ptr;//�ж�����������a,b���λ��һ����� 
			
		}
		
		if(sgn0==0)
		{
			break;//�����һ��û�з���������������� 
		} 
	}
	return(head);
 } 
 
 //�������ܣ�������루���� �����ߣ������磬�۸񣬿�棬����� 
 BOOK *getin(BOOK *p)
 {
 	printf("\n\n������������    "); 
	scanf("%s",p->bookname);
	while(strlen(p->bookname)>=50)
	{	
		printf("\n������������������룺"); //��ֹ�ַ����鳤����� 
		scanf("%s",p->bookname);
	}
	printf("\n���������ߣ�    "); 
	scanf("%s",p->author);
	while(strlen(p->author)>=50)
	{	
		printf("\n������������������룺"); 
		scanf("%s",p->author);
	}
	printf("\n����������磺  "); 
	scanf("%s",p->publisher);
	while(strlen(p->publisher)>=50)
	{	
		printf("\n������������������룺"); 
		scanf("%s",p->publisher);
	}
	printf("\n�����뽨���ۼۣ�"); 
	while(scanf("%f",&p->price)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}//�����ַ������ַ�����ͣ���ڻ�������
	printf("\n������������  "); 
	while(scanf("%d",&p->stock)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}//��ջ�������ֹ������ѭ�� 
	printf("\n������������  "); 
	while(scanf("%d",&p->out)!=1)
	{printf("\n���뷢���������������룺");rewind(stdin);}
	
	return (p);
 }
 
 //�������ܣ���ӡһ����� 
 void putout(BOOK *p)
 {
 	printf("\n\nͼ���ţ�%d\nͼ�����ƣ�%s\n���ߣ�    %s\n�����磺  %s\n�����ۼۣ�%.2f\n�������  %d\n�������  %d",
		p->id,p->bookname,p->author,p->publisher,p->price,p->stock,p->out);
 }
