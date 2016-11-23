#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
	pid_t pid = getpid();
	pid_t ppid;
	char path[256];
	printf("%d\n", pid);

	FILE *fp;

	sprintf(path, "/proc/%d/stat", pid);
	printf("%s\n", path);
	fp = fopen(path, "r");
	fscanf(fp, "%*d %*s %*c %d", &ppid);
	printf("%d\n", pid);
	printf("%d\n", ppid);

	return 0;
}
