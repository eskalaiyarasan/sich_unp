#ifndef _H_unp_lolAawdotOwe_
#define _H_unp_lolAawdotOwe_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>

#include <sys/select.h>
#include <sys/sysctl.h>
#include <poll.h>
//#include <sys/event.h>
#include <pthread.h>

#include <sys/ioctl.h>
//#include <sys/sockio.h>
#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif

#ifndef SHUT_RD
#define SHUT_RD		0
#define SHUT_WR		1
#define SHUT_RDWR	2
#endif

#define bzero(ptr , n)	memset(ptr ,0 ,n)

#define LISTENQ		1024
#define MAXLINE		4096
#define BUFFSIZE	8192

#define UNIXSTR_PATH  	"/tmp/unix.stream"
#define UNIXDG_PATH	"/tmp/unix.dg"

#define SA	struct sockaddr 
#endif
