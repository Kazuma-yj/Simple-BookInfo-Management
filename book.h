#ifndef H_BOOK_H
#define H_BOOK_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

struct book
{
	int id;
	char bookname[50];
	char author[50];
	char publisher[50];
	float price;
	int stock;
	int out;
	struct book *ptr;
};
typedef struct book BOOK;//简称为BOOK 

//符号常量定义 
#define LEN sizeof(struct book)

//函数原型声明
int menu(void);
void browse(BOOK *head);
BOOK *creatlinkedlist(void); 
FILE *openfile(char filename[50],char filetype[5]);
void save(BOOK *head,char filename[50],char filetype[5]);
BOOK *sort(BOOK *head);
BOOK *add(BOOK *head);
BOOK *_delete(BOOK *head);
void change(BOOK *head);
void borrow(BOOK *head);
void back(BOOK *head);
BOOK *getin(BOOK *p); 
void search(BOOK *head);
void putout(BOOK *p);


#endif 
