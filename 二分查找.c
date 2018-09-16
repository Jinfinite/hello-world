/*
* @Author: JuXiang
* @Email:  juzi.yun97@gmail.com
* @Date:   2018-09-15 20:17:33
*/

//二分查找适合于顺序表，而不适合链表
//二分查找的前提是顺序表的关键字有序排列
int BinarySearCh(List Tbl,ElemenType K){
	int left,right,mid,NoFound = -1;
	left = 1;					//初始化左边界
	right = Tbl->length;		//初始化右边界
	while(left <= right){
		mid = (left + right)/2; //计算中间元素坐标
		if(K < Tbl->Element[mid])
			right = mid - 1; //调整右边界
		else if(K > Tbl->Element[mid])
			left = mid + 1;	//调整左边界
		else
			return mid;	//查找成功，返回数据元素的下标
	}
	return NoFound; //查找不成功，返回-1
}