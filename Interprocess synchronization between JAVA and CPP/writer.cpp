#include <stdio.h>
#include <unistd.h>

FILE *lockFile, *dataFile;

//mutex = 1 writer finished;
//mutex = 2 reader finished;

void unlock(){
    lockFile = fopen("mutex.txt","w");
    fputc('1', lockFile);
    fclose(lockFile);
}

void lock(){
    while(1){
        lockFile = fopen("mutex.txt","r");
	    if (lockFile == NULL){
	    	printf("file open failed!\n");
    	}
        char mutex;
        mutex = fgetc(lockFile);
        fclose(lockFile);
        if (mutex != '2'){
            printf("get lock failed\n");
            usleep(500000);
            continue;
        } else {
            lockFile = fopen("mutex.txt","w");
            fputc('2', lockFile);
            fclose(lockFile);
            break;
        }
    }
}

int main(){
    int cnt = 0;
    while(1){
        lock();
        dataFile = fopen("data.txt","w");
        for (int i = 0;i <= 4;i++){
            cnt++;
            printf("writing!\n");
            fprintf(dataFile, "I am writing %d\n", cnt);
        }
        fclose(dataFile);
        unlock();
        usleep(1000000);
    }
}
