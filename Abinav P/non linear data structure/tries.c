#include<Stdio.h>
#include<stdlib.h>

struct branch {
    struct data chars[27];
};

struct data {
    char data;
    char *s;
    struct branch *next;
};


struct branch create_branch(struct branch *head){
    struct branch *main=malloc(sizeof(struct branch));
    return main;
}


struct 

void main(){
    struct branch *mainbranch;
}