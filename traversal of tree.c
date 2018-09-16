//C语言中关于二叉树的一些遍历方法

typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
}


//先序遍历：根，左，右
void PreOrderTraversal( BinTree BT ){
	if( BT ){
		printf("%d",BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}



//中序遍历：左，根，右
void InOrderTraversal( BinTree BT ){
	if( BT ){
		InOrderTraversal(BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal(BT->Right);
	}
}
/*
中序遍历非递归实现：堆栈实现
具体细节：1.遇到一个节点，就把它压栈，并去遍历它的左子树；2
		  2.当左子树遍历结束后，从栈顶弹出这个节点并访问他；
		  3.然后按其右指针再去中序遍历该节点的右子树
*/
void InOrderTraversal( BinTree BT){
	BinTree T = BT;
	Stack S = CreatStack( MaxSize );//创建并初始化堆栈S
	while( T || !IsEmpty(S)){
		while(T){ //一直向左并将沿途节点压栈
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S)){
			T = Pop(S); //节点弹出堆栈
			printf("%5d",T->Data);//(访问)打印节点
			T = T->Right;//转向右子树
		}
	}
}





//后序遍历：左，右，根
void PostOrderTraversal( BinTree BT ){
	if( BT ){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
}




/*
层序遍历：遍历从根节点开始，首先将根节点入队，然后开始执行循环：节点出队，访问该节点，其左右儿子入队
基本过程：先根节点入队，然后：1.从队列中取一个元素；2.访问该元素所指节点；3.该元素所指节点的左右孩子
节点非空，则将其左右孩子的指针顺序入队。
*/
void LevelOrderTraversal( BinTree BT){
	Queue Q;
	BinTree T;
	if( !BT )//若是空树则直接返回
		return;
	Q = CreatQueue( MaxSize );//创建并初始化队列
	AddQ( Q, BT );
	while( !IsEmptyQ(Q)){
		T = DeleteQ(Q);
		printf("%d\n",T->Data); //访问取出队列的节点
		if( T->Left ) 
			AddQ(Q, T->Left);
		if( T->Right )
			AddQ(Q, T->Right);
	}
}
