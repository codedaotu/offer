#include <iostream>
#define N 7
using namespace std;
void matrixChainOrder(int p[],int length,int m[][N],int s[][N])
{
    int i,l,j,k;
    int q;
    for(i=0;i<length;++i)
        m[i][i]=0;//对角线赋值零
    for(l=2;l<length;++l)//l为子矩阵链的长度，最短是2，最长是6，进行遍历
    {
        for(i=1;i<length-l+1;++i)//根据子矩阵链的长度遍历，若l=2，则是遍历7-2+1,若是3,7-3+1
        {
            j=i+l-1;//确定矩阵链的末尾，l=2时，j=2,3,4,5,6,i=1,2,3,4,5
            m[i][j]=100000;
            for(k=i;k<=j-1;++k)
            {
               q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
               /*
               迭代公式，m[i,j]=m[i,k]+m[k+1,j]+p[i-1]*p[k]*p[j],以k为最佳分断点，但是需要遍历k,选出最小值
               每隔一个矩阵计算一次，所以步进是1，而且要小于
               */
               if(q<m[i][j])
               {
                   m[i][j]=q;
                   s[i][j]=k;//s[][]记录构造最优解所需信息记录每次k的位置
               }
            }
        }
    }
}
void printOptimalParents(int s[][N],int i,int j)//递归打印矩阵
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printOptimalParents(s,i,s[i][j]);
        printOptimalParents(s,s[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    int p[N]={5,10,3,12,5,50,6};
    int m[N][N]={0},s[N][N]={0};
    matrixChainOrder( p,N,m,s);
    cout<<"m矩阵的值为"<<endl;
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<N;++j)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"s矩阵的值为"<<endl;
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<N;++j)
            cout<<s[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"矩阵链中括号放置顺序如下时运算代价最小"<<endl;
    printOptimalParents(s,1,N-1);
    return 0;
}
