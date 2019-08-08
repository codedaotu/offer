#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
int main()
{	
	int row;
	cin>>row;
	string c;
	cin.ignore();  
	int array[row][row];
	int temp[row][row]={0};

	for(int i=0;i<row;i++)
	{	
		int t=0;
		getline(cin,c);
		for(int j =0;j<c.length();j++)
		{
			if(c[j]!=','&&c[j]!='\n')
			{
				array[i][t]=(int)(c[j]-'0');
				t++;
			}		
		}
	}
	temp[0][0]=array[0][0];
	int min=0;
	for(int i=1;i<row;i++)
	{
		temp[0][i]=temp[0][i-1]+array[0][i];
	}
	for(int j=1;j<row;j++)
	{
		temp[j][0]=temp[j-1][0]+array[j][0];
	}
	for(int i=1;i<row;i++)
	{
		for (int j = 1; j < row; j++)
		{
			if(temp[i-1][j]<temp[i][j-1])
				min=temp[i-1][j];
			else
				min=temp[i][j-1];
			temp[i][j]=min+array[i][j];
		}
	}
	cout<<temp[row-1][row-1];

	return 0;
}