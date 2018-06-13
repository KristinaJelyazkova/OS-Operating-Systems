#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	int x = 1;
	char buff[2];
	int size = 1;
	while(x > 0){
		x = read(0, buff, size);
		write(fd, buff, x);
	}
	int fd1 = open(argv[1], O_RDONLY);
	int i = 2;
	while(argv[i] != NULL){
		int x = 1;
		int fd2 = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0755);
		while(x > 0){
			x = read(fd1, buff, size);
			write(fd2, buff, x);
		}
		i++;
		lseek(fd1, 0, 0);
	}
}
