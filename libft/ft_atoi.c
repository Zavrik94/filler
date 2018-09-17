/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:32:04 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/17 23:22:07 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				f;
	long long int	res;

	res = 0;
	f = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'\
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			f = -1;
		str++;
		if (!(*str <= '9' && *str >= '0') && *str != '-')
			return (0);
	}
	while (*str <= '9' && *str >= '0')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (f == -1 ? -res : res);
}
