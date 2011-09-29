#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

#define BUFLEN 1000

int
main (int argc, char *argv[]) {

    int s;
    struct sockaddr_in in;
    char buffer[BUFLEN+1];
    char *req = "GET / HTTP/1.0\n\n";
    struct hostent *host;
    struct servent *serv;

    if (argc !=3) {
        printf ("uso: %s host port\n" , argv[0]);
        exit (1);
    }

    if ((s = socket (AF_INET,SOCK_STREAM,0)) == -1) {
        printf ("socket: %s\n",strerror(errno));
        exit (1);
    }
  
    memset (&in,0,sizeof(in)); 
    
    in.sin_family = AF_INET;
    if ((host = gethostbyname(argv[1]))){
        memcpy (&in.sin_addr.s_addr,host->h_addr,host->h_length);
    }else{
        in.sin_addr.s_addr = inet_addr(argv[1]);
    }


    //
    // port
    if ((serv = getservbyname(argv[2],"tcp"))){
        in.sin_port = serv->s_port;
    }else{
        in.sin_port = htons(atoi(argv[2]));
    }


    printf ("connecting to: %s:%d\n",inet_ntoa(in.sin_addr),ntohs(in.sin_port));

    if (connect (s,(struct sockaddr*) &in,sizeof(in))) {
        printf ("connect: %s\n",strerror(errno));
        exit (1);
    }

    send (s,req,strlen(req),0);

    printf ("reading....\n");

    while (recv (s,buffer,BUFLEN,0) > 0)
        printf ("%s",buffer);


    close (s);

    return 0;
}
