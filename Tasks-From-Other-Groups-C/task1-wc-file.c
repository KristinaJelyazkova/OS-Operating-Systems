#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int bytes = 1, size = 1, lines = 0, words = 0, allbytes = 0;
	int fd = open(argv[1], O_RDONLY);
	char buff[1];
	while(bytes > 0){
		bytes = read(fd, buff, size);
		if(bytes > 0){
			if(buff[0] == '\n'){
				lines++;
				words++;
			}
			if(buff[0] == ' '){
				words++;
			}
			allbytes = allbytes + bytes;
		}
	}
	printf("%d %d %d %s\n", lines, words, allbytes, argv[1]);
}	
