#include "wrapper.h"
int Socket( int family , int type , int protocol) {
	int n;
	
	if( (n = socket(family , type , protocol)) < 0 )
		err_sys( "socket error" );
	return n;
}

int Listen(int sock_fd , int backlog) {
	int n;
	
	if( (n = listen(sock_fd , backlog)) < 0 )
		err_sys( "socket listen error" );
	return n;

}
int Bind( int sock_fd, SA *addr, int len) {
	int n;
	
	if( (n = bind(sock_fd, addr , len )) < 0 )
		err_sys( "sock_fd bind error" );
	return n;
}

int Accept( int sock_fd , SA *addr , int *len) {
	int n;
	
	if( (n = accept(sock_fd, addr, len)) < 0 )
		err_sys( "sock_fd accept error" );
	return n;
}
int Close( int sock_fd) {
	int n;
	
	if( (n = close(sock_fd)) != 0 )
		err_sys( "sock_fd close error" );
	return n;
}

int Write(int fd , void *buf , size_t count)
{
	int n;
	
	if( (n = write(fd , buf , count)) < 0 )
		err_sys( "sock_fd write error" );
	return n;
}
int Read(int fd , void *buf , size_t count)
{
	int n;
	
	if( (n = read(fd , buf , count)) < 0 )
		err_sys( "sock_fd write error" );
	return n;
}
int  Connect( int fd , SA *serv , int len)  {
	int n;
	
	if( (n = connect(fd ,serv , len)) < 0 )
		err_sys( "sock_fd Connect error" );
	return n;
}


void err_sys(const char *x) {
	perror(x);
	exit(1);
}
