#include "libft.h"

void	ft_printarr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
	}
}