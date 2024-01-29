#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char buffer[2048];
    while(1==1){
        printf("directory:\n");
        fgets(buffer, 2048, stdin);
        printf("%s",buffer);
    }
}