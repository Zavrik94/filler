#include "libft.h"

void	ft_printnumbarr(int **arr, int	x, int y)
{
	int i;
	int	c;
	size_t	max_len;
	size_t	cur_len;

	i = -1;
	max_len = 2;
	while (arr[++i])
	{
		c = -1;
		while (arr[++c])
			if (ft_strlen(ft_itoa(arr[i][c])) > max_len)
				max_len = ft_strlen(ft_itoa(arr[i][c]));
	}
	i = -1;
	while (++i < y)
	{
		c = -1;
		while (++c < x)
		{
			cur_len = max_len - ft_strlen(ft_itoa(arr[i][c])) + 1;
			while (--cur_len != 0)
				ft_putchar(' ');
			ft_putstr(ft_itoa(arr[i][c]));
		}
		ft_putchar('\n');
	}
}