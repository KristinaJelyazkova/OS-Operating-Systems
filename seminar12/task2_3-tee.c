#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	if(argc > 100){
		printf("error");
	}
	int fd[100];
	int i = 1;
	while(argv[i] != NULL){
		fd[i] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0755);
		i++;
	}
	int x = 1;
	char buff[201];
	int size = 200;
	while(x > 0){
		x = read(0, buff, size);
		int i = 1;
		while(argv[i] != NULL){
			write(fd[i], buff, x);
			i++;
		}
	}
}
