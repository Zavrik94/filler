#include "libft.h"

char			ft_itoc(const unsigned char value, const bool is_uppercase)
{
	if (value < 10)
		return (value + '0');
	return (value - 10 + (is_uppercase ? 'A' : 'a'));
}