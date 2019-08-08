#include<iostream>
using namespace std;
void swap(int &p1,int &p2)
{ 	int a;
	a=p1;
	p1=p2;
	p2=a;
}
void adjust_heap(int a[],int parent,int end)
{	//根据父节点确定左子节点和右子节点，进行遍历
	 for (int i = parent*2+1; i<end; i=i*2+1)
	 {	
	 	// cout<<"i1 "<<i<<endl;
	 	if (i+1<end&&a[i]<a[i+1])//选出子节点中大的那个
	 	{
	 		i++;//++可以选出最大值在左树，否则是在右树，
	 	}	
	 	if (a[parent]<=a[i])
	 	{	
	 		swap(a[parent],a[i]);//将最大值与父节点的值交换
	 		parent=i;
	 		/*需要注意！！！！
	 		此时的将被比下去的父节点的坐标给parent，使之成为下一个子树的父节点。
	 		因为是主程序从下而上，当处在上方父节点与子节点换了值，影响的是换值的节点，和左子树换就影响左子树，右子树不考虑，
	 		所以需要沿着换值的节点走，此时i就是下一个循环的条件，也就是换值节点。
	 		*/
	 	}

	 }

}
void max_heap(int a[],int n)
{
	for (int i = n/2-1; i>=0 ; i--)
	{
		// cout<<"parent "<<i<<endl;
		adjust_heap(a,i,n);
	}
	for (int j=n-1;j>0;j--)
    {
        /*
        倒叙循环，每次堆排序的最大的永远在第一位，将其和最末位交换，之后从0也就是根节点进行调整，最终将最末位交换到树中合适的地方去。因为每次只对一个数
        进行交换，所以最多影响一条子节点。也就是parent=i的作用。
        */
        swap(a[0],a[j]);
        adjust_heap(a,0,j);
    }	
}	
int main()
{
	int n=10;
	int a[n]={8,9,6,104,33,0,65,345,67,100};
	max_heap(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}

}