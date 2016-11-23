#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>

int count_children(pid_t parent_pid) {
	int count = 0;
	struct dirent *entry;
	DIR *dir = opendir("/proc/");

	FILE *stat_file;
	char statfile_path[256];
	pid_t ppid;
	pid_t pid;
	
	while(entry = readdir(dir)) {
		sprintf(statfile_path, "/proc/%s/stat", entry->d_name);
		if (pid = atoi(entry->d_name)){
			stat_file = fopen(statfile_path, "r");
			fscanf(stat_file, "%*d %*s %*c %d", &ppid);
			fclose(stat_file);
			if (ppid == parent_pid){
//				printf("%d == %d\n", ppid, parent_pid);
//				printf("%d is child\n", pid);
				count ++;
				count += count_children(pid);
			}
		}
	}
	closedir(dir);

	return count;
}

int main(int c, char **v) {
//	printf("!!!!\n%s\n!!!!", v[1]);
	pid_t pid = atoi(v[1]);
	printf("%i\n", count_children(pid) + 1);
	return 0;
}
