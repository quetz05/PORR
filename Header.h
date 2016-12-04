#ifndef THREAD_H
#define THREAD_H
#include <thread>

using namespace std;

struct Thread
{
	Thread();
	virtual void run();

	thread _thread;
};



#endif // THREAD_H