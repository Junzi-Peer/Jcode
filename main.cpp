#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
int main(int argc, char **argv) {
    int port = 9090;
    void *handle;
    unsigned long int  (*Init)(int);
    char *error;

    //handle = dlopen("./libdemo.so",RTLD_NOW);
    
    handle = dlopen("./libdemo.so",RTLD_LAZY);
    if(!handle){
        cout<<"handle is null"<<endl;
        exit(1);
    }

    Init = ( unsigned long int  (*)(int))dlsym(handle,"Init");
    if((error=dlerror()) != NULL){
        cout<<"error"<<endl;
        exit(1);
    }

    unsigned long int  threadId = Init(10);
    cout<<"threadId = " << threadId<<endl;

    
    while(1){
        sleep(10);
        cout<<"sleep"<<endl;
    }

    if(dlclose(handle)<0){
        cout<<"close failed"<<endl;
    }
    return 0;
}

