#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd = open(argv[2], O_RDONLY);
	int bytes = 0, size = 1, count = 0;
	int string_size = strlen(argv[1]);
	char buff[1];
	while( (bytes = read(fd, buff, size)) > 0){
		count++;
		if(buff[0] == argv[1][0]){
			char buff2[80];
			int x = string_size - 1;
			read(fd, buff2, x);
			buff2[x] = '\0';
			if(strcmp(buff2, &(argv[1][1])) == 0){
				printf("victory!\n");
				exit(54);
			}
			lseek(fd, count, SEEK_SET);
		}
	}
}
