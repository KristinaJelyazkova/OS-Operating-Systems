#include<stdio.h>
#include<fcntl.h>

void cat(char *filename){
	int fd = open(filename, O_RDONLY);
	int x = 1;
	char buff[513];
	int size = 512;
	while(x > 0){
		x = read(fd, buff, size);
		write(1, buff, x);
	}
}

int main(int argc, char *argv[]){
	int i = 1;
	while(argv[i] != NULL){
		cat(argv[i]);
		i++;
	}
}    
	
