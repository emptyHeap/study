#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main() 
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir("/proc/");
	entry = readdir(dir);

	FILE *statfile;
	char statfile_path[256];
	int amount = 0;
	do {
		sprintf(statfile_path, "/proc/%s/stat", entry->d_name);
		if (atoi(entry->d_name)){
			char pname[256];
			statfile = fopen(statfile_path, "r");
			fscanf(statfile, "%*d %s %*c %*d", pname);
			fclose(statfile);

			if (strcmp(pname, "(genenv)") == 0) {
				amount ++;
			}
		}
	} while ((entry = readdir(dir)));

	closedir(dir);

	printf("%i\n", amount);

	return 0;
}
