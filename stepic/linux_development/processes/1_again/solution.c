#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
	pid_t proc_ppid;
	char path[256] = "/proc/self/stat";

	FILE *fp = fopen(path, "r");
	fscanf(fp, "%*d %*s %*c %d", &proc_ppid);

	printf("%d\n", proc_ppid);

	return 0;
}

