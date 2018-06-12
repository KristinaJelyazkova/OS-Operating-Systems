#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_RDONLY);
	int m, n;
	scanf("%d %d", &m, &n);
	int bytes = 1, size =1;
	char buff[1];
	int count = 0;
	while(bytes > 0){
		bytes = read(fd, buff, size);
		if(bytes > 0){
			count++;
			if(buff[0] == '\n'){
				count = 0;
				printf("\n");
				continue;
			}
			if(count >= m && count <= n){
				printf("%c", buff[0]);
			}
		}
	}
	close(fd);
}

