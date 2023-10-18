#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line;
	line = (char*)malloc(sizeof(char)*20);
	read(0, line, sizeof(line));
	printf ("%s", line);
	return 1;
}
