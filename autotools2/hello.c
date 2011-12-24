/* hello.c: A program to show the time since the Epoch */
 
#include <stdio.h>
#include "config.h"
#include "lib/libFunc.h"
#include "lib2/libtest.h"
 
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
 
double get_sec_since_epoch()
{
   double sec;
 
   #ifdef HAVE_GETTIMEOFDAY
      struct timeval tv;
 
      gettimeofday(&tv, NULL);
      sec = tv.tv_sec;
      sec += tv.tv_usec / 1000000.0;
   #else
      sec = time(NULL);
   #endif
 
   return sec;
}
 
int main(int argc, char* argv[])
{
   printf("Hello World at %f\n", get_sec_since_epoch());

   libFunc();
   libtest();
 
   return 0;
}
