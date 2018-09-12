/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:32:40 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/12 20:34:55 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_itoc(const unsigned char value, const bool is_uppercase)
{
	if (value < 10)
		return (value + '0');
	return (value - 10 + (is_uppercase ? 'A' : 'a'));
}
