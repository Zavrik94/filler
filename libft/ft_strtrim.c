/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:38:35 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/13 14:43:02 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_front(char const *s)
{
	int		i;
	int		front;
	int		count;

	front = 0;
	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			count++;
		else if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && count == 0)
			front++;
	return (front);
}

static int		ft_back(char const *s)
{
	int		i;
	int		count;
	int		back;

	i = ft_strlen(s);
	count = 0;
	back = 0;
	while (s[--i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			count++;
		else if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && count == 0)
			back++;
	return (back);
}

char			*ft_strtrim(char const *s)
{
	int		front;
	int		back;
	int		len;
	char	*tmp1;

	if (!s)
		return (NULL);
	front = ft_front(s);
	back = ft_back(s);
	len = ft_strlen(s) - back - front;
	if (len < 0)
		return (ft_strdup(""));
	if (!(tmp1 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp1 = ft_strsub(s, front, len);
	return (tmp1);
}
