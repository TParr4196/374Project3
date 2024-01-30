#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


void commandLine(char* *commands){
    execvp(commands[0],commands);
    perror("command not registered");
    exit(1);
}


int main(){
    while(1==1){
        char buffer[2048];
        printf("mush: ");
        fgets(buffer, 2048, stdin);

        char* buf="";
        buf=strtok(buffer," \n");
        char* command[128];
        
        int i = 0;
        while(buf!=NULL){
            command[i]=buf;
            buf=strtok(NULL," \n");
            i++;
        }
        command[i]=NULL;
        if(strcmp("cd",command[0])==0){
            int check=chdir(command[1]);
            if(check==-1){
                perror("invalid directory");
            }
        }
        else if(strcmp("exit",command[0])==0){
            exit(0);
        }
        else if(command[0]!=NULL){
            pid_t pid = fork();
            if(pid<0){
                perror("forking error");
            }
            else if(pid==0){
                commandLine(command);
            }
            else {
                wait(NULL);
            }
        }
    }
}