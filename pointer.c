#include <stdio.h>


void lista (int *d) {

   printf ("lista: %d %d %d\n" ,d[0],d[1],d[2]); 

}


void lines (char *words[]) {

    printf ("word : %s\n",words[0]);
    printf ("word : %s\n",words[1]);
    printf ("word : %s\n",words[2]);
}

int main(int argc, char *argv[]) {

    char *p, **pw;
    char *buffer = "teste";
    int n, *pn, **ppn;
    int a[3] = {1,2,3};
    char *words[] = {"xxxxx","xxxxx","xxxxx"};

    p = buffer;
    printf ("%s --- %s\n",p,argv[0]);

    n = 10;

    pn = &n;
    ppn = &pn;

    **ppn = 12;

    printf ("%d %d %d\n" ,n,*pn,**ppn);

    pn = a;
    printf ("%d %d %d %d\n",a[0],a[1],a[2],*pn);

    pn ++;
    printf ("%d %d %d %d\n",a[0],a[1],a[2],*pn);

    *pn = 22;
    printf ("%d %d %d %d\n",a[0],a[1],a[2],*pn);

    lista (a); 

    lines(words);
    
    p = words;
    pw[1][2] = 'O';
    //pw[2][4] = 'O';

    lines(words);

    return 0;
}
