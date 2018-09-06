#include "libft.h"

void	ft_printarr_fd(int fd, char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		ft_putstr_fd(arr[i], fd);
		ft_putchar_fd('\n', fd);
	}
}