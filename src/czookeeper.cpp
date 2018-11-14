

#include "czookeeper.h"
using namespace std;
void CZookeeper::zk_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx){
    printf("Something happened.\n");
    printf("type: %d\n", type);
    printf("state: %d\n", state);
    printf("path: %s\n", path);
    printf("watcherCtx: %s\n", (char *)watcherCtx);
}
CZookeeper::CZookeeper()
{
    strHost = "";
    fn = zk_watcher_g;
    recv_timeout = 0;

    //默认为0 不重连之前会话ID
    clientid = 0;
    context = NULL;
    flags = 0;
    logLevel = ZOO_LOG_LEVEL_INFO;

    zkhandle = NULL;
}

void CZookeeper::setHost(string pHost)
{
    strHost = pHost;
}
/*
void CZookeeper::setWatcherFn(watcher_fn pfn)
{
    fn = pfn;
}
*/
void CZookeeper::setRecvTimeout(int precv_timeout)
{
    recv_timeout = precv_timeout;
}
void CZookeeper::setFlags(int pflags)
{
    flags = pflags;
}
void CZookeeper::setLoglevel(int plogLevel)
{
    if(plogLevel = 0){
        logLevel = ZOO_LOG_LEVEL_INFO;
    }else{
        logLevel = ZOO_LOG_LEVEL_INFO;
    }
    
}
bool CZookeeper::init()
{
    zoo_set_debug_level(logLevel); 
    //zhandle_t* zkhandle = zookeeper_init(host,zktest_watcher_g, timeout, 0, "hello zookeeper", 0);
    zkhandle = zookeeper_init(strHost.c_str(),fn, recv_timeout, clientid, context, flags);
    if (zkhandle ==NULL)
    {
        cout << "zookeeper init failed..."<<endl;
        return false;
    }

    cout << "zookeeper init success..." << endl;
    return true;
}

