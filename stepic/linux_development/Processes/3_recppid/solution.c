#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

pid_t parent_pid(pid_t child_pid) 
{
	char stat_file_path[256];
	pid_t parent_pid;

	sprintf(stat_file_path, "/proc/%i/stat", child_pid);
	FILE *stat_file = fopen(stat_file_path, "r");
	fscanf(stat_file, "%*d %*s %*c %d", &parent_pid);
	fclose(stat_file);

	return parent_pid;
}

int main(int c, char **v) 
{
	pid_t target_pid = atoi(v[1]);
	//scanf("%d", &target_pid);
	while (target_pid != 1) {
		printf("%i\n", target_pid);
		target_pid = parent_pid(target_pid);
	}
	printf("1\n");
	return 0;
}

