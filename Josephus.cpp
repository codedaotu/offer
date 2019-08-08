#include <iostream>
using namespace std;
int joserecursion(int N,int M)
{
	if(N==1){
		return 0;
	}
	else{
		return (joserecursion(N-1,M)+M)%N;
	}
}
int kill(int N,int M)
{	int result = M-1;
	//第一个死的人
	cout<<(M-1)%N;
	for (int i = N; i>=2 ; i--)
	//循环输出死的人,n为总人数，
	{	result = M-1;
		for (int j = i; j <= N; j++)
		{
			result = (result+M)%j;
		}
		cout<<"->"<<result;
	}
	return 0;
}
int main()
{ int N = 9 ,M = 5;
	'A'<'D';
cout<<joserecursion(N,M)<<endl;
kill(N,M);
}

