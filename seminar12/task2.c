#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	execvp("tee", argv);
}
