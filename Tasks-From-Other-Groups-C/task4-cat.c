#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int bytes = 0, size = 1024;
	char buff[1024];
	while( (bytes = read(0, buff, size)) > 0){
		write(1, buff, bytes);
	}
	return 0;
}
