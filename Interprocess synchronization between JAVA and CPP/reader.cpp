#include <stdio.h>
#include <unistd.h>

FILE *lockFile, *dataFile;

//mutex = 1 writer finished;
//mutex = 2 reader finished;

void readerUnlock(){
    lockFile = fopen("mutex.txt","w");
    fputc('2', lockFile);
    fclose(lockFile);
}

void readerLock(){
    while(1){
        lockFile = fopen("mutex.txt","r");
        char mutex;
        mutex = fgetc(lockFile);
        fclose(lockFile);
        if (mutex != '1'){
            printf("get lock failed\n");
            usleep(100000);
            continue;
        } else {
            lockFile = fopen("mutex.txt","w");
            fputc('1', lockFile);
            fclose(lockFile);
            break;
        }
    }
}

int main(){
    char buff[30];
    while(1){
        readerLock();
        dataFile = fopen("data.txt","r");
        while(fscanf(dataFile, "%s", buff)!=EOF){
            printf("I got %s\n", buff);
        }
        fclose(dataFile);
        readerUnlock();
    }
}