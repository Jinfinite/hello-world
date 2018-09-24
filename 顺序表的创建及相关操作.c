/*
* @Author: JuXiang
* @Email:  juzi.yun97@gmail.com
* @Date:   2018-09-24 18:01:51
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100		//顺序表初始存储空间长度
#define INCREMENT 10	//存储空间增长因子

typedef struct{
	int *elem;		//顺序表的基地址
	int length;		//当前顺序表中有效元素的个数
	int listsize;	//当前顺序表的存储空间长度
}SqList;


void Init_Sq(SqList *L);	//初始化顺序表
void Creat_Sq(SqList *L);	//创建顺序表
void Insert_Sq(SqList *L,int i,int e);	//插入操作
void Delete_Sq(SqList *L,int i,int *e);	//删除操作
void Traverse_Sq(SqList *L);	//遍历顺序表

int main(){
	int e = 0;
	SqList L;
	Init_Sq(&L);
	Creat_Sq(&L);
	Traverse_Sq(&L);
	Insert_Sq(&L,2,9);
	Traverse_Sq(&L);
	Delete_Sq(&L,3,&e);
	printf("%d",e);
}

void Init_Sq(SqList *L){
	L->elem = (int *)malloc(MAXSIZE * sizeof(int));	//申请内存空间
	if(!L->elem)	//申请失败则退出函数
		return;
	L->length = 0;	//初始化时，顺序表的长度为零
	L->listsize = MAXSIZE;	//初始顺序表的存储空间大小
	return;
}

void Creat_Sq(SqList *L){
	int i = 0,j = 0,x = 0;
	printf("请输入所要创建顺序表的长度：");
	scanf("%d",&j);	//接收将要输入的线性表的长度信息
	for(i; i<j && i<L->listsize; ++i){
		printf("\n请输入元素值: ");
		scanf("%d",&x);
		L->elem[i] = x;	//往顺序表中添加元素
		++L->length;	//更新顺序表有效元素个数的值
	}
	return;
}

void Insert_Sq(SqList *L,int i,int e){
	int j = 0;
	if(i<1 || i>L->length+1)	//判断插入位置是否合法
		return;
	if(L->length >= L->listsize){//判断顺序表是否已满，如果已满，则增加内存空间
		int *newbase = (int *)realloc(L->elem,(L->length+INCREMENT)*sizeof(int));
		if(!newbase)//增加内存空间失败，则退出函数
			return;
		L->elem = newbase;	
		L->listsize += INCREMENT;
	}
	for(j = L->length; j >= i; --j)
		L->elem[j] = L->elem[j-1];	//将元素后移
	L->elem[i-1] = e;	//插入元素
	++L->length;	//更新顺序表有效元数据个数的值
	return;
}

void Delete_Sq(SqList *L,int i,int *e){
	int j = 0;
	if(i<1 || i>L->length)	//判断删除位置是否合法
		return;
	*e = L->elem[i-1]; 	//接收将要删除元素的值
	for(j = i; j<L->length; ++j)
		L->elem[j-1] = L->elem[j];	//元素前移
	--L->length;	//更新顺序表有效元数据个数的值
	return;
}

void Traverse_Sq(SqList *L){	//遍历顺序表
	int i = 0;
	for(i; i<L->length;++i)
		printf("%d ",L->elem[i]);
	printf("\n");
	return;
}