#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
char buf_msg[BUFSIZE];
ssize_t nread;
char wtmp[]="/home/newstorage/5893_pam/lab11/lab11POT.server";

int main(int argc, char *argv[]){
    if(argc !=2){
		perror("Error not found name file");
        exit(1);
	}
    int sock, fi1;
    struct sockaddr_un server;
    sock = socket(AF_UNIX,SOCK_STREAM,0);
    if(sock<0){
        perror("Error socket");
        exit(1);
	}
    bzero(&server,sizeof(server));
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path,wtmp);

    int LEN = sizeof(server);
    if(connect(sock,(const struct sockaddr *)&server,LEN)<0){
        perror("Error connect");
        exit(2);
	}
    if((fi1 = open(argv[1],O_RDONLY)) ==-1){
        perror("Error open file");
        exit(1);
	}
    while((nread = read(fi1,buf_msg,BUFSIZE))>0){
        send(sock,buf_msg,sizeof(buf_msg),0);
	}
    printf("Sended: %s\n", buf_msg);
    close(sock);
    close(fi1);
    return 0;
}
