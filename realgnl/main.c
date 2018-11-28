#include "get_next_line.h"

int		main()
{
	char	**line;
	int		fd;
	line = malloc(10000);
	fd = open("test", O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		printf("%s\n", *line);
	}
	return (0);
}
