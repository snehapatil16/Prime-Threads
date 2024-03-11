#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <math.h>

void runner(int threads, int* count, int min,int max);

int main() {

  int numThreads = 4;
  //pthread_t ths[numThreads];

  int min = 10;
  int max = 100;

  //storing each thread's count in an array
  int* count = (int*)malloc(numThreads * sizeof(int));
  std::thread* ths[numThreads];

  
  for (int i = 0; i < numThreads; i++) {

    int start = (((max-min)/numThreads)*i)-min;
    int stop = (((max-min)/numThreads)*(i+1))-min;
    //Parm* p = (Parm*)malloc(1 * sizeof(Parm));

    //p->numThread = i;
    //p->min = start;
    //p->max = stop;
    //p->count = count;
    //pthread_create(&(ths[i]), NULL, runner, (void*)p);
    std::thread* th = new std::thread(runner, i, count, start, stop);
    ths[i] = th;
  }

  for (int i = 0; i<numThreads; i++) {
    ths[i]->join();
  }

  int nums = 0;
  for (int i = 0; i < numThreads; i++){
    nums += count[i];
  }

  std::cout << "Number of prime numbers: " << nums << "\n";
}

void runner(int threads, int* count, int min, int max) {

  //finding count of prime numbers
  //Parm* theParms = (Parm*)parm;

  count[threads] = 0;
  int temp = 0;
  
  for (int i = min; i <= max; i++) {

    temp = 0;
    for(int j = 2; j <= i/2; j++) {

      if(i%j == 0){
        temp = 1;
	break;
      }
    }
    if(temp == 0 && i >= 2) {
      count[threads]++;
    } 
  }

  //theParms->count[theParms->numThread] = count;
  //pthread_exit(0);
}


