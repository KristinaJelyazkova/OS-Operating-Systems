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
}
