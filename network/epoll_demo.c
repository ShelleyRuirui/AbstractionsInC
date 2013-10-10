/**
 *epoll_demo.c
 *gcc epoll_demo.c -pthread
 *http://blog.csdn.net/xiaonamylove/article/details/4252563
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<time.h>
#include<sys/epoll.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<pthread.h>
#include<errno.h>

#define THREAD_MAX 1

#define LISTEN_PORT 8000

#define LISTEN_MAX 1

#define SERVER_IP "127.0.0.1"

typedef struct
{
  char ip4[128];
  int port;
  int fd;
} listen_info;

static listen_info s_listens[LISTEN_MAX];

static unsigned int s_thread_para[THREAD_MAX][8];
static pthread_t s_tid[THREAD_MAX];
pthread_mutex_t s_mutex[THREAD_MAX];

static int init_thread_pool(void);
static int init_listen4(char *ip4,int port,int max_link);

void* test_server4(unsigned int thread_para[]);

int main(int argc,char *argv[])
{
  int i,j,rc;
  int sock_listen;
  int sock_cli;
  int listen_index;

  int epfd;
  int nfds;
  struct epoll_event ev;
  struct epoll_event events[LISTEN_MAX];
  
  socklen_t addrlen;
  struct sockaddr_in addr4;

  rc=init_thread_pool();
  if(rc!=0)
    exit(-1);

  for(i=0;i<LISTEN_MAX;i++)
  {
    sprintf(s_listens[i].ip4,"%s",SERVER_IP);
    s_listens[i].port=LISTEN_PORT+i;
    rc=init_listen4(s_listens[i].ip4,s_listens[i].port,64);
    if(rc<0)
    {
      fprintf(stderr,"Can't create server on %s:%d\n",s_listens[i].ip4,s_listens[i].port);
      perror(NULL);
      exit(-1);
    }
    s_listens[i].fd=rc;
  }

  epfd=epoll_create(8192);
  for(i=0;i<LISTEN_MAX;i++)
  {
    ev.events=EPOLLIN;
    ev.data.u32=i;
    if(epoll_ctl(epfd,EPOLL_CTL_ADD,s_listens[i].fd,&ev)<0){
      fprintf(stderr,"Fail to add socket to epoll fd:%d\n",rc);
      exit(-1)
    }
  }

  for(;;)
  {
    ndfs=epoll_wait(epfd,events,LISTEN_MAX,-1);
    //handle
    for(i=0;i<nfds;i++)
    {
      listen_index=events[i].data.u32;
      sock_listen=s_listens[listen_index].fd;
      addrlen=sizeof(struct sockaddr_in);
      sock_cli=accept(sock_listen,(struct sockaddr*)&addr4,&addrlen);
      if(sock_cli<0)
      {
        fprintf(stderr,"Fail to handle client");
	continue;
      }

      for(j=0;j<THREAD_MAX;j++)
      {
        if(s_thread_para[j][0]==0) break;
      }

      if(j>=THREAD_MAX)
      {
        fprintf(stderr,"Thread pool is filled.Connection abort\n");
	shutdown(sock_cli,SHUT_RDWR);
	close(sock_cli);
	continue;
      }

      s_thread_para[j][0]=1;
      s_thread_para[j][1]=sock_cli;
      s_thread_para[j][2]=listen_index;

      pthread_mutex_unlock(smutex+j);

    }

  }
  exit(0);
}

static int init_thread_pool(void)
{
  int i,rc;

  for(i=0;i<THREAD_MAX;i++)
  {
    s_thread_para[i][0]=0;
    s_thread_para[i][7]=i;
    pthread_mutex_lock(s_mutex+i);
  }

  for(i=0;i<THREAD_MAX;i++)
  {
    rc=pthread_create(s_tid+i,0,(void*)test_server4,(void*)(s_thread_para[i]));
    if(rc!=0)
    {
      fprintf(stderr,"Fail to create thread");
      return -1;
    }
  }
  return 0;
}

static int init_listen4(char *ip4,int port,int max_link)
{
  int sock_listen4;
  struct sockaddr_in addr4;
  unsigned int optval;
  struct linger optval1;

  bzero(&addr4,sizeof(addr4));
  inet_pton(AF_INET,ip4,&(addr4.sin_addr));
  addr4.sin_family=AF_INET;
  addr4.sin_port=htons(port);

  sock_listen4=socket(AF_INET,SOCK_STREAM,0);
  if(sock_listen4<0) return -1;

  optval=0x1;
  setsockopt(sock_listen4,SOL_SOCKET,SO_REUSEADDR,&optval,4);
  
  optval1.l_onoff = 1;
  optval1.l_linger = 60;
  setsockopt(sock_listen4, SOL_SOCKET, SO_LINGER, &optval1, sizeof(struct linger));   
    
  if (0 > bind(sock_listen4, (struct sockaddr *)&addr4, sizeof(addr4)))
  {   
    close(sock_listen4);   
    return(-1);   
  }   
				  
  if (0 > listen(sock_listen4, max_link))   
  {   
    close(sock_listen4);   
    return(-1); 
  }   
  
  return(sock_listen4);   
   
}
