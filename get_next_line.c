#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);

#endif

char	*get_next_line(int fd)
{
	int		i;
	int		bytes;
	char	*buffer;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE > INT_MAX))
		return (NULL);
	i = 0;
	bytes = read(fd, &character, 1);
	buffer = malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
	while (bytes > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (i == 0))
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}

// int main()
// {
//     int fd;
//    fd = open("test.txt",O_RDONLY);
//     char *line;

//    while((line = get_next_line(fd)))
//    {
//     	printf("%s",line);
//    		free(line);
//     }
// }
