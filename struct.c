#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

struct data {

    char name[50];
    int age;

};

typedef struct data ROW;


void save (int fd,ROW *r){

    printf ("%d\n",write (fd,r,sizeof (ROW)));
    printf ("%s\n",strerror (errno));
    printf ("saved : %s %d %d\n",r->name,r->age,sizeof(struct data));
}

void readall(int fd) {

    struct data d;
    int v;

    lseek (fd,0,SEEK_SET);

    while ((v = read (fd,&d,sizeof(struct data)))  )
        printf ("read: %s %d %d\n",d.name,d.age,v);

}

int main () {

    struct data d;
    ROW row;
    int fd;

    if ((fd = open ("/tmp/teste.dat",O_RDWR,O_APPEND|O_CREAT)) == -1) {
        printf ("error opening file");
        return (1);
    }
    printf (" --- fd %d\n" ,fd);

    strcpy (d.name,"tercio" );
    d.age = 40;

    printf ("%s %d %d\n",d.name,d.age,sizeof(struct data));
    save (fd,&d);

    strcpy (row.name,"marcia" );
    row.age = 37;

    printf ("%s %d %d\n",row.name,row.age,sizeof(ROW));

    save (fd,&row);

    readall(fd);

    close (fd);

    return 0;
}
