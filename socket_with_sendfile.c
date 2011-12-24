#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

#define BUFLEN 1000

int
main (int argc, char *argv[]) {

    int s,conn,in_fd;
    struct sockaddr_in in;
    char buffer[BUFLEN+1];
    struct hostent *host;
    struct servent *serv;
    struct stat st;

    if (argc !=2) {
        printf ("uso: %s port\n" , argv[0]);
        exit (1);
    }

    if ((s = socket (AF_INET,SOCK_STREAM,0)) == -1) {
        printf ("socket: %s\n",strerror(errno));
        exit (1);
    }
  
    memset (&in,0,sizeof(in)); 
    

    //
    // port
    if ((serv = getservbyname(argv[1],"tcp"))){
        in.sin_port = serv->s_port;
    }else{
        in.sin_port = htons(atoi(argv[1]));
    }

    in.sin_addr.s_addr = htonl(INADDR_ANY);
    in.sin_family = AF_INET;


    printf ("binding...\n");

    if (bind (s,(struct sockaddr*) &in,sizeof(in))) {
        printf ("bind: %s\n",strerror(errno));
        exit (1);
    }

    if (listen (s,10) < 0) {
        printf ("listen... %s\n",strerror(errno));
        exit(1);
    }

    printf ("accepting...\n");

    conn = accept (s,NULL,NULL);
    if (conn == -1) {
        printf ("accept: %s\n",strerror(errno));
        exit(1);
    }

    //send (conn,"teste\n\0",7,0);
    if ((in_fd = open ("./socket.c",O_RDONLY)) < 0) {
        printf ("open... %s\n",strerror(errno));
        exit(1);
    }

    if (fstat(in_fd,&st) < 0) {
        printf ("stat: %s\n",strerror(errno));
        exit(1);
    }

    printf ("sending file ./socket with %d bytes\n",st.st_size);

    sendfile (conn,in_fd,NULL,st.st_size);

    close (conn);

    return 0;
}
