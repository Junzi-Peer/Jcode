//======================================================================
//
//        Copyright (C) 2014
//        All rights reserved
//
//        filename : zookeeper.h
//        description :
//
//        created by zj at  2018-11-14 10:00:00
//        modified by XX at
//
//======================================================================

#ifndef _CZOOKEEPER_H_
#define _CZOOKEEPER_H_

#include "zookeeper.h"
#include "zookeeper_log.h"
#include <iostream>
#include <cstring>
using namespace std;

class CZookeeper
{
public:
    CZookeeper();
    void setHost(string strHost);
    //void setWatcherFn(watcher_fn pfn);
    void setRecvTimeout(int precv_timeout);
    void setFlags(int pflags);
    void setLoglevel(int plogLevel);

    bool init();
    ~CZookeeper();

    

private:
    CZookeeper(const CZookeeper&);
    CZookeeper& operator=(const CZookeeper&);
    /*全局回调函数*/
    static void zk_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx);

private:
    string strHost;
    watcher_fn fn;
    int recv_timeout;
    const clientid_t *clientid;
    void *context;
    int flags;
    ZooLogLevel logLevel;

    zhandle_t* zkhandle;

};

#endif // _ZOOKEEPER_H_

