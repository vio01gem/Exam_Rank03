#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		bytes;
	static char	line[100000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read(fd, line, 100000);
	if (bytes <= 0)
		return (NULL);
	line[bytes] = '\0';
	return (line);
}

// int main()
// {
// 	int fd;
//    	fd = open("test.txt",O_RDONLY);
//     char *line;

// 	line = get_next_line(fd);
// 	printf("%s",line);
// }