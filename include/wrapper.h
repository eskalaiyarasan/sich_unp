#ifndef _H_WRAPPER_azUDomUSTOxyc_
#define _H_WRAPPER_azUDomUSTOxyc_
#include "unp.h"
int Socket( int family , int type , int protocol);

int Bind( int sock_fd, SA *addr, int len) ;

int Accept( int sock_fd , SA *addr , int *len) ;
int Close( int sock_fd) ;

int Write(int fd , void *buf , size_t count);
int Read(int fd , void *buf , size_t count);
int  Connect( int fd , SA *serv , int len)  ;
void err_sys(const char *x) ;



#endif
