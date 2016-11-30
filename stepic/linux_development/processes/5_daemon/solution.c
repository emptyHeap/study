#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() 
{
	pid_t pid;
	pid = fork();
	if (pid > 0) 
		return 0; 

	setsid();
	// determine self pid
	pid_t daemon_pid;
	FILE *stat_file = fopen("/proc/self/stat", "r");
	fscanf(stat_file, "%d", &daemon_pid);
	fclose(stat_file);
	printf("%i\n", daemon_pid);

	// close all std
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	sleep(10000);

	return 0;
}
