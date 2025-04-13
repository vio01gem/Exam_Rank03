#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		bytes;
	char	*line;
	char	character;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	bytes = read(fd, &character, 1);
	line = malloc(1000000);
	while (bytes > 0)
	{
		line[i++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (i == 0))
		return (free(line), NULL);
	line[i] = '\0';
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
