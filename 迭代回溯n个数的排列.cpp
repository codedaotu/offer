#include <iostream>
using namespace std;
#include <vector>
void perm(int list[], int k, int m)
{
    if (k == m)//递归的基础部分
    {
        for (int i = 0; i <= m; i++)
        {
            cout << list[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            perm(list, k + 1, m);
            swap(list[k], list[i]);
        }
    }
}

void perm(vector<int> &arr,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<m;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i=k;i<=m;i++)
        {
            swap(arr[k],arr[i]);
            perm(arr,k+1,m);
            swap(arr[k],arr[i]);
        }   
    }
}
int main()
{
    vector<int> list = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    perm(list, 0, list.size());
    return 0;
}
