#include <stdio.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

//#include "zookeeper.h"
#include "czookeeper.h"
//#include "zookeeper_log.h"
using namespace std;
int x =10;
//同步方式获取节点数据
/*
void get(zhandle_t* zkhandle)
{
    printf("同步方式获取节点数据-----------------------\n");
    char buffer1[64];
    int bufferlen1=sizeof(buffer1);
 
    int flag1=zoo_get(zkhandle,"/zk",0,
                      buffer1,&bufferlen1,NULL);
    if (flag1 ==ZOK)
    {
        printf("节点/zk的数据为: %s\n",buffer1);
    }
}

void zkMywatcher(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
    printf("Something happened.\n");
    printf("type: %d\n", type);
    printf("state: %d\n", state);
    printf("path: %s\n", path);
    printf("watcherCtx: %s\n", (char *)watcherCtx);
}

void zktest_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
    printf("Something happened.\n");
    printf("type: %d\n", type);
    printf("state: %d\n", state);
    printf("path: %s\n", path);
    printf("watcherCtx: %s\n", (char *)watcherCtx);
}
//删除节点
void zkdelete(zhandle_t *zkhandle,char *str)
{
    int flag = zoo_delete(zkhandle,str,-1);
    if (flag==ZOK)
    {
        printf("delete node success\n");
    }
}

*/
void *TestThread(void* arg)
{
    int input = *(int*)arg;
    cout << "threadId: "<< input <<"  running"<<endl;

    string strHost = "10.135.96.164:2181,10.104.93.81:2181,10.135.21.100:2181";
    CZookeeper Zookeeper;
    Zookeeper.setHost(strHost);
    //Zookeeper.setWatcherFn(zktest_watcher_g);
    Zookeeper.setRecvTimeout(30000);
    Zookeeper.setFlags(0);
    Zookeeper.setLoglevel(0);
    if(!Zookeeper.init()){
        cout <<"aaaaaa!!!!!!!!!"<<endl;
    }
    cout <<"good"<<endl;




    //ZK BEGIN
    /*
    const char* host = "10.135.96.164:2181,10.104.93.81:2181,10.135.21.100:2181";

    int timeout = 30000;
    char buffer[512];
    int *bufferlen;
    char *p = new char[10];
    zoo_set_debug_level(ZOO_LOG_LEVEL_INFO); //设置日志级别,避免出现一些其他信息
    //zhandle_t* zkhandle = zookeeper_init(host,zktest_watcher_g, timeout, 0, "hello zookeeper", 0);
    zhandle_t* zkhandle = zookeeper_init(host,zktest_watcher_g, timeout, 0, p, 0);
    cout << "dddd"<<endl;
    cout << zkhandle<<endl;    
    if (zkhandle ==NULL)
    {
        cout << "zookeeper is null"<<endl;
        fprintf(stderr, "Error when connecting to zookeeper servers...\n");
        exit(EXIT_FAILURE);
    }
 
    get(zkhandle);
    char buf[1024];
    int blen = sizeof(buf);
    struct Stat stat;
    int rc = zoo_wget(zkhandle,"/zk",zkMywatcher,NULL,buf,&blen,&stat);
    cout<<"同步？"<<endl;
    if(ZOK != rc){
        cout<< "zoo_wget failed..."<<endl;
    }

    */
    //char str[]="/xyz30000000014";
    // wexists(zkhandle,str);
    // printf("---------------\n");
    //create(zkhandle,str);
    //get(zkhandle);
    // getChildren(zkhandle,str);
    //getACL(zkhandle,str);
    //delete p;
    //zkdelete(zkhandle,str);
    //ZK END

    while(1){
        x ++;
        cout<<"im here "<< x <<endl;
        sleep(2);
    }
}

extern "C"  unsigned long int  Init(int y){
    cout<<y<<endl;
    pthread_t threadId;
    static int input = 12;

    int ret = pthread_create(&threadId, NULL, TestThread, (void*)&input);//input是局部变量，配合非阻塞，配合传地址，极大可能在线程中出现问题。
    if(ret != 0)
    {
        cout<< "create thread error"<<endl;
    }
    cout<<"main thread running"<<endl;
    //pthread_join(threadId,NULL);//阻塞
    pthread_detach(threadId);//非阻塞
    //return 0;
    return ( unsigned long int )threadId;

}