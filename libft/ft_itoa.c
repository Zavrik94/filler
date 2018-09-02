/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:05:37 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/10 22:45:24 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cnt(int c)
{
	int i;

	i = 0;
	while (c / 10 > 10)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

static void		ft_do(char *dst, char *s, int n)
{
	int			i;
	long int	tmp;
	int			count;

	i = 0;
	count = 0;
	tmp = n;
	if (n < 0)
		tmp = -tmp;
	while (tmp / 10 > 0)
	{
		i = tmp % 10;
		tmp = tmp / 10;
		dst[count] = 48 + i;
		count++;
	}
	i = tmp % 10;
	dst[count++] = 48 + i;
	if (n < 0)
		dst[count++] = '-';
	dst[count--] = '\0';
	i = 0;
	while (count >= 0)
		s[i++] = dst[count--];
	s[i] = '\0';
}

char			*ft_itoa(int n)
{
	char		*dst;
	char		*s;
	long int	tmp;
	int			count;

	tmp = n;
	count = 0;
	if (n < 0)
	{
		tmp = -tmp;
		count++;
		count = ft_cnt(tmp);
		dst = (char *)malloc(count + 4);
		s = (char *)malloc(count + 4);
	}
	else
	{
		count = ft_cnt(tmp);
		dst = (char *)malloc(count + 2);
		s = (char *)malloc(count + 2);
	}
	if (dst == NULL && s == NULL)
		return (NULL);
	ft_do(dst, s, n);
	return (s);
}
