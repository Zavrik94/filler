/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:55:00 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/15 21:37:50 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countalf(char *s, char ch, int i)
{
	int c;

	c = 0;
	if (!s)
		return (0);
	while (s[i] != ch)
	{
		c++;
		i++;
	}
	return (c);
}

static int		*ft_long(char *s, char ch)
{
	int	i;
	int cword;
	int	c;
	int	*res;

	i = -1;
	cword = 0;
	c = 1;
	if (!s)
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] != ch && i == 0)
			cword++;
		else if ((s[i] != ch && s[i - 1] == ch))
			cword++;
	if (!(res = (int*)malloc(sizeof(int) * (cword + 1))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == ch && s[i + 1] != ch)
			res[c++] = countalf(s, ch, i + 1);
		else if (i == 0 && s[i] != ch)
			res[c++] = countalf(s, ch, 0);
	res[0] = cword;
	return (res);
}

static char		*ft_write(char *s, int i, int c)
{
	char	*res;
	int		j;

	j = 0;
	if (!(res = (char *)malloc(c * sizeof(char) + 1)) || !s)
		return (NULL);
	while (j <= c - 1)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

char			**ft_strsplit(const char *s, char ch)
{
	int		i;
	int		c;
	int		c1;
	int		*res;
	char	**rch;

	c = 0;
	res = ft_long((char*)s, ch);
	if (!res || !(rch = (char **)malloc(sizeof(char *) * (res[0] + 1))))
		return (NULL);
	i = -1;
	i = -1;
	while (s[++i])
	{
		c1 = c + 1;
		if (s[i] != ch && i == 0)
			rch[c++] = ft_write((char *)s, i, res[c1]);
		else if ((s[i] != ch && s[i - 1] == ch))
			rch[c++] = ft_write((char *)s, i, res[c1]);
	}
	rch[c] = 0;
	return (rch);
}
