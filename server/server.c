#include "wrapper.h"
void thread_create( const pthread_t *attr , void *(*startfn)(void *) , void *arg)
{
   typedef struct  sthread_handle
   {
	pthread_t  threadid;
	struct sthread_handle *link;
   }thread_handle;
   
   static thread_handle *head = NULL;
   thread_handle *temp = NULL;
   int rc;

   if( head == NULL) {
	head = malloc(sizeof(thread_handle) );
	bzero(head ,sizeof(thread_handle));
	temp = head;
   } else {
	temp = head;
	while( temp->link != NULL)
		temp = temp->link;
	temp->link = malloc(sizeof(thread_handle) );
	bzero(temp->link ,sizeof(thread_handle));
	temp = temp->link;
   }

   rc = pthread_create( &(temp->threadid) , attr , startfn , arg);
   if ( rc ) {
	printf(" ERROR : return from pthresd_create %d \n" , rc );
	}
  
}
void *threadfn(void *args)
{
	time_t ticks;
	int connfd = (int) args;
	char buff[MAXLINE];
	for(;;) {
		ticks= time(NULL);
		snprintf(buff , sizeof(buff) , "%.24s\r\n" ,ctime(&ticks) );
		Write(connfd , buff , strlen(buff));
		sleep(5);
	}
	Close(connfd);
	pthread_exit(NULL);

}
int main( int argc ,char *argv[] )
{
	int listenfd ;
	int connfd;
	struct sockaddr_in servaddr;

	listenfd = Socket( AF_INET ,SOCK_STREAM , 0);

	bzero(&servaddr , sizeof(servaddr) );

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
	servaddr.sin_port =htons(7232);

	Bind( listenfd , (SA *) &servaddr , sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	for(;;) {
		connfd = Accept(listenfd , (SA*) NULL , NULL);
		thread_create( NULL ,threadfn , (void *) connfd);
	}
	pthread_exit( NULL );
	return 0;
}
