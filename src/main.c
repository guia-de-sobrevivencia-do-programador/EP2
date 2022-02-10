#include <dirent.h>
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXBUFFSIZE 32

size_t input_dirs_len;
char** input_dirs;
const char* output_dir;

char* join_path(const char* directory, const char* filename)
{
	char* realpath = (char*)calloc(sizeof(char), FILENAME_MAX);
	if (!realpath) {
		perror("calloc");
		exit(1);
	}

	char* path_format =
	    (directory[strlen(directory) - 1] == '/') ? "%s/%s" : "%s%s";

	sprintf(realpath, path_format, directory, filename);
	return realpath;
}

void dump_file_into_file(int infile, int out_file)
{
	char buff[MAXBUFFSIZE];
	int buff_len;
	while ((buff_len = read(infile, buff, MAXBUFFSIZE)) != 0) {
		write(out_file, buff, buff_len);
	}
}

void merge_files(const char* filename)
{
	char* out_filepath = join_path(output_dir, filename);
	int out_file = open(out_filepath, O_WRONLY | O_CREAT, 0666);
	for (int i = 0; i < input_dirs_len; ++i) {
		char* filepath = join_path(input_dirs[i], filename);
		int file = open(filepath, O_RDONLY);
		if (file == -1) {
			perror("open");
			exit(1);
		}
		dump_file_into_file(file, out_file);
		close(file);
	}
	close(out_file);
}

void find_matching_files()
{
	static int dir_index = 0;
	static char* current_entry_name;
	++dir_index;

	DIR* input_dir = opendir(input_dirs[dir_index]);
	if (!input_dir) {
		perror("opendir");
		exit(1);
	}

	struct dirent* entry;
	while ((entry = readdir(input_dir))) {
		if (dir_index == 0)
			current_entry_name = entry->d_name;
		else if (strcmp(entry->d_name, current_entry_name) != 0)
			continue;

		if (entry->d_name[0] == '.')
			continue;

		if (dir_index == (input_dirs_len - 1)) {
			printf("Found matching file %s\n", current_entry_name);
			merge_files(current_entry_name);
		}
		else
			find_matching_files();
	}

	closedir(input_dir);
	--dir_index;
}

int main(int argc, char* argv[])
{
	if (argc < 4) {
		printf("Usage: %s <input1> <input2> ... <inputN> <output>\n", argv[0]);
		return 1;
	}

	input_dirs_len = argc - 2;
	input_dirs = (char**)calloc(sizeof(char*), input_dirs_len);
	if (!input_dirs) {
		perror("calloc");
		exit(1);
	}

	for (int i = 1; i < (argc - 1); ++i) {
		input_dirs[i - 1] = argv[i];
	}

	output_dir = argv[argc - 1];
	find_matching_files();
	free(input_dirs);
}
