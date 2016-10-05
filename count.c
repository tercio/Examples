#include <stdio.h>


int main(int argc, char *argv[]) {


  int number = 0, i =0, n = 0, count = 0;

  if (argc != 2) {

    printf ("usage: %s number\n",argv[0]);
    return -1;
  }

  number = atoi(argv[1]);


  while (number > 0) {

    if ((number & 1) == 1) count ++;

    number >>= 1;

  }


  printf ("number: %d - number of bits 1 = %d\n" ,number,count);

  return 0;
}
