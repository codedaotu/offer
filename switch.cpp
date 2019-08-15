#include<iostream>
using namespace std;
int main()
{
	int i=10;
	switch(i)
	{
		case 9:i++;//正常后面要加break
		case 10:i++;
		case 11:i++;
		default :i++;
	}
	printf("%d\n",i );
	return 0;
}