#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/un.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <linux/socket.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/socket.h>

#define LEN 100
#define MAXCLIENT 6

struct ucred cr;

int main(){

	int cl= sizeof(cr);
	struct sockaddr_un server;
	int lstner;
	char wtmp[] = "/home/newstorage/5893_pam/lab11/lab11POT.server";
	int sendbuff;
	lstner = socket(AF_UNIX, SOCK_STREAM, 0);
	if (lstner < 0) {
		perror("Server error socket");
		exit(1);
	}
	unlink(wtmp);
	bzero(&server, sizeof(server));
	server.sun_family = AF_UNIX;
	strcpy(server.sun_path, wtmp);
	if (bind(lstner, (struct sockaddr*)&server, sizeof(server)) <0){
		perror("Error bind");
		exit(2);
	}
	listen(lstner, MAXCLIENT);
	int sock, res;
	int bytes_read;
	char buf[LEN];
	while (1) {
		sock = accept(lstner, NULL, NULL);
		if (sock < 0) {
			perror("Error accept");
			continue;
		}
		while(1) {
			getsockopt(sock, SOL_SOCKET, SO_PEERCRED, &cr, &cl);
			bytes_read = recv(sock, buf, LEN, 0);
			if (bytes_read <= 0)
				break;
			printf("FROM PID %d MESS: %s\n", cr.pid, buf);
		}
		close(sock);
	}
	return(0);
}
