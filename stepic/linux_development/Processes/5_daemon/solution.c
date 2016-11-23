#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() 
{
	pid_t daemon_pid;
	FILE *stat_file = fopen("/proc/self/stat", "r");
	fscanf(stat_file, "%d", &daemon_pid);
	fclose(stat_file);
	printf("%i\n", daemon_pid);

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	daemon();

	sleep(100000);
}
