#include "get_next_line.h"

int		main()
{
	char	**line;
	int		fd;
	char	*buf;
	int		ret;
	line = malloc(10000);
	fd = open("test", O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	//write(2, "1\n", 2);
//	printf("%d", ret);
	while (get_next_line(fd, line) > 0)
	{
		printf("%s\n", *line);
	}
	return (0);
}
