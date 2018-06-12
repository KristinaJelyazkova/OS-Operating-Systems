#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		int fd = open(argv[1], O_RDONLY);
		int bytes = 1;
		char buff[1];
		int size = 1;
		int flag = 1;
		while(bytes > 0){
			bytes = read(fd, buff, size);
			if(flag != 0){
				flag = 0;
				write(1, buff, bytes);
			}
			else if (bytes > 0) {
				write(1, " ", 1);
				write(1, buff, bytes);
			}
		}
	}
	else{
		int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		write(fd, argv[2], sizeof(argv[2]) - 1);
	}
}
