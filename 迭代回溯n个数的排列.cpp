#include <iostream>
using namespace std;
#include <vector>
void perm(vector<int> &arr,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<=m;i++)
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
    vector<int> list = { 1, 2, 3 };
    perm(list, 0, list.size()-1);
    return 0;
}
