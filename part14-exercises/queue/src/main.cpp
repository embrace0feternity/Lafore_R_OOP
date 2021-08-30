/*
 	  	 Напишите шаблон класса для работы с очередью. Определите несколько
	очередей разных типов и поработайте с их данными.
 */


#include "queue.h"
#include <time.h>
#include <random>

int main()
{
	const int SIZE = 6;
	srand(time(0));

	Queue<int> queueA1, queueB1, queueC1;	int idata;
	for (int i=0; i<SIZE; i++)
	{
		idata = 1+rand()%20;
		queueA1.push(idata);
	}
	queueA1.showQueue();

	try
	{
		for (int i=0; i<SIZE-1; i++) queueA1.pop();
		queueA1.showQueue();

		//queueB1 = queueA1;
		//queueB1 = queueC1; // C1 has no elements and calls 'operator= error'
	} catch (const exeptions& other)
	{
		std::cerr << other.where << ' ' << other.what << std::endl << std::endl;
	}


	//---------------------------------------------------------------
	Queue<double> queue2;	double ddata;
	for (int i=0; i<SIZE; i++)
	{
		ddata = (rand()%2000)/100.;
		queue2.push(ddata);
	}
	queue2.showQueue();

	try
	{
		for (int i=0; i<SIZE-1; i++) queue2.pop();
		queue2.showQueue();
	} catch (const exeptions& other)
	{
		std::cerr << other.where << ' ' << other.what << std::endl << std::endl;
	}

	//---------------------------------------------------------------
	Queue<std::string> queue3;
	std::string sstr[4] =
	{
			"I feel their watching",
			"With eyes of disdain",
			"I feel lamenting",
			"from blood that was stained",
	};
	for (int i=3; i>=0; i--) queue3.push(sstr[i]);
	queue3.showQueue();
	try
	{
		for (int i=0; i<2; i++) queue3.pop();
		queue3.showQueue();
	} catch (const exeptions& other)
	{
		std::cerr << other.where << ' ' << other.what << std::endl << std::endl;
	}
	return 0;
}
