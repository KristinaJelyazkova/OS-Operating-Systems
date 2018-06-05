#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd1, fd2;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	int x = 1;
	char buff[513];
	int size = 512;
	while(x > 0){
		x = read(fd1, buff, size);
		write(fd2, buff, x);
	}
}

