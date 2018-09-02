/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:40:37 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:40:39 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	int				res;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (d1[i] || d2[i])
	{
		if (d1[i] > d2[i] || d1[i] < d2[i])
		{
			res = d1[i] - d2[i];
			return (res);
		}
		else
			i++;
	}
	return (0);
}
