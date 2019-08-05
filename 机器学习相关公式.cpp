/*
机器学习公式
*/
using namespace std;
#include<math.h>
#include<vector>
int N = 10;
/*
逻辑回归
*/
vector<double> theta(N,0);
double sum_list(vector<double> &x_input)
{
	double s=0;
	for(int i=0;i<N;i++)
	{
		s+=x_input[i]*theta[i];
	}
	return s;
}
double logistic(vector<double> &x_input)
{
	double power=sum_list(x_input);
	double p=1.0/(1+exp(-power));
	return p;
}

/*
决策树
*/
double entropy(vector<double> &proba)
{
	int len=proba.size();
	int h=0;
	for(int i=0;i<len;i++)
	{
		h+=proba[i]*log(proba[i]);
	}
	return -h;	
}

int main()
{
	return 0;	
}
