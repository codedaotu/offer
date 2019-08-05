#include<iostream>
#include<string.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return a%b==0? b:gcd(b,a%b);
}
int main()
{
	return 0;
}