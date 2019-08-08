#include <iostream>
using namespace std;
int log(int n);//复杂度为O(logN)
int square(int n);//复杂度为O(N2)
int main ()
{

	cout<<log(5);

}

int log(int n)
{
	int count =1;
	while (count<n)
	{
		count = count*2;
	}
	return count;
}
int square(int n)
{	int count =1;
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			count = count +1;
		}
	}
}