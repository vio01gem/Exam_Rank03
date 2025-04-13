#include "get_next_line.h"

char	*get_next_line(int fd) // lol its basically get_the_file
{
	int		bytes;
	char *line; //<--

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1000000); //<--
	bytes = read(fd, line, 1000000);
	if (bytes <= 0)
		return (free(line), NULL); //<--
	line[bytes] = '\0';
	return (line);
}

// int main()
// {
// 	int fd;
//    	fd = open("test.txt",O_RDONLY);
//     char *line;

//    	while((line = get_next_line(fd)))
//    	{
//     	printf("%s",line);
//    		free(line);
//     }
// }