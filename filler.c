#include "header/filler.h"

int		main(void)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr("azavrazh: ");
		ft_putstr(line);
	}
	return (0);
}