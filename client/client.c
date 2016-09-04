#include "unp.h"
#include "wrapper.h" 
int main(int argc , char *argv[])
{
	int sockfd ,n;
	char buff[ MAXLINE +1 ];
	struct sockaddr_in serv;
	struct timeval timeout;

	sockfd = Socket(AF_INET , SOCK_STREAM , 0) ;

	bzero( &serv , sizeof(serv));

	serv.sin_family = AF_INET;
	serv.sin_port = htons(7232);
	if( inet_pton( AF_INET , argv[1] , &serv.sin_addr) <= 0) {
		printf(" inet_pton error check arg %s", argv[1] );
		return 1;
        }

	timeout.tv_sec =10;
	timeout.tv_usec = 0;
	if(setsockopt(sockfd , SOL_SOCKET, SO_RCVTIMEO , (char*)&timeout, sizeof(timeout) ) < 0)
		printf("error timeout error\n");

	Connect(sockfd , (SA *) &serv , sizeof( serv) );

	while(  (n= Read(sockfd ,buff , MAXLINE)) >0 ) {
		buff[n] =0;
		fputs(buff ,stdout);
	}
	return 0;
}
