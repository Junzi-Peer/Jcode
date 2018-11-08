#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
    int port = 9090;
    void *handle;
    void (*Demo)(int);
    char *error;

    handle = dlopen("./libdemo.so",RTLD_LAZY);
    if(!handle){
        cout<<"handle is null";
        exit(1);
    }

    Demo = (void (*)(int))dlsym(handle,"Hello");
    if((error=dlerror()) != NULL){
        cout<<"error";
        exit(1);
    }

    Demo(10);
    if(dlclose(handle)<0){
        cout<<"close failed";
    }
    return 0;
}

