#include "libft.h"
#include "stdio.h"

int		main(void)
{
	int fd = open("test.c", O_RDONLY);
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}