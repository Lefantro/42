#include <stdio.h>
#include <stdlib.h> 

int problems_in_line (char*line)
{ int is_key;
is_key = 1;
	while (*line)
	{
		if (*line == ':')
			is_key = 0;
		line++;
	}
if (is_key)
	return 0;
return 1;
}

void extract_value (char *line, char *value)
{	
	char prev;
	while (*line !=':')
		line++;
	line++;

	while (*line == ' ')
		line++;

	prev = ' ';
	while (*line)
	{
		if (! ((prev == ' ')&&(*line ==' ')))
		{

			*value = *line;
            value++;

		}
		prev = *line;
		line++;
	}
	*(value+1)='\0';

}


int main()
{
    char *i;
    i = (char*)malloc(sizeof(char)*100);
    extract_value ("123  :  oh  haha", i);
    printf ("%s", i);
}