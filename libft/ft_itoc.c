#include "libft.h"

char			ft_itoc(const unsigned char value, const bool is_upperсase)
{
	if (value < 10)
		return (value + '0');
	return (value - 10 + (is_upperсase ? 'A' : 'a'));
}