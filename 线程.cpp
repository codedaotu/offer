#include <iostream>
#include <pthread.h>
#include <cstdlib>
using namespace std;
#define NUM_T 5
struct thread_data
{
   int  thread_id;
   char *message;
};
void* say_hello (void* args)
{
	struct thread_data *my_data;
	my_data=(struct thread_data*) args;
	cout<<"ID"<<my_data->thread_id<<endl;
	cout<<"message"<<my_data->message<<endl;
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	
	pthread_t threads[NUM_T];
	struct thread_data td[NUM_T];
	int re;
	for (int i = 0; i < NUM_T; ++i)
	{
		cout<<" creating thread"<<i<<endl;
		td[i].thread_id=i;
		td[i].message=(char *)"ok";
		re = pthread_create(&threads[i],NULL,say_hello,(void*)&td[i]);
		if(re)
		{
			cout<<"error"<<re<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}