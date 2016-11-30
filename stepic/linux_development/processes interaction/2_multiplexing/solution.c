#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>

int read_int(int fd, fd_set *set)
{
//	FILE *fifo = fdopen(fd, "r");
//	if (fifo == NULL) {
//		return 0;
//	}
//	char input;
//	int result = 0;
//	while (1) {
//		input = fgetc(fifo);
//		if (input == EOF) {
//			break;
//		}
//		result += (input - '0');
//	}
//	fclose(fifo);
//	return result;
	
	char buf[255];
	int result = 0;

	size_t bytes = read(fd, buf, 255);
	buf[bytes] = 0;
	if (bytes == 0) {
		FD_CLR(fd, set);
		return 0;
	}

//	size_t i;
//	for (i = 0; i < bytes; i++) {
//		if (buf[i] == '\n') continue; 
//		result += buf[i] - '0';
//	}

	return atoi(buf);
}

int main()
{
	int f1 = open("./in1", O_RDONLY);
	int f2 = open("./in2", O_RDONLY);

	if (! (f1 && f2) ) {
		return 0;
	}

	fd_set read_set;
	int sum = 0;

	do {
		FD_ZERO(&read_set);
		FD_SET(f1, &read_set);
		FD_SET(f2, &read_set);

		int result = select(f2+1, &read_set, NULL, NULL, NULL);

		if (result == -1) {
			break;
		} else if (result == 0) {
		}

		if (FD_ISSET(f1, &read_set)) {
			sum +=read_int(f1, &read_set);
		}
		if (FD_ISSET(f2, &read_set)) {
			sum +=read_int(f2, &read_set);
		}

	} while (FD_ISSET(f1, &read_set) || FD_ISSET(f2, &read_set));


	close(f1);
	close(f2);

	printf("%i\n", sum);
	return 0;
}
