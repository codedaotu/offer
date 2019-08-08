#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int m,n;
	cin>>m>>n;
	while(m!=-1)
	{	
		int a[m][n];
		for (int j = 0; j < m; ++j) 
            for (int i = 0; i < n; ++i) 
                cin >> a[j][i];
	int left=0,right=n-1,top=0,bottom=m-1;
	int k=0;
	while(left<=right&&top<=bottom)
	{
		for(int i=left;i<=right;i++) 
			if(k==n*m-1)cout<<a[top][i];
			else 
				{
					cout<<a[top][i]<<',';
					k++;
				}
		for(int i=top+1;i<=bottom;i++) 
			if(k==n*m-1) cout<<a[i][right];
			else 
				{
					cout<<a[i][right]<<',';
					k++;
				}
		for(int i=right-1;i>=left&&top<bottom;i--) 
			if(k==n*m-1)cout<<a[bottom][i];
			else
			{
				cout<<a[bottom][i]<<',';
				k++;
			}	
		for(int i=bottom-1;i>top&&left<right;i--) 
			if(k==n*m-1)cout<<a[i][left];	
			else
			{
				cout<<a[i][left]<<',';
				k++;
			}	
		left++,top++,right--,bottom--;
	}
cin>>m>>n;
}
return 0;}