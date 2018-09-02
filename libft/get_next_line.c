/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:37:53 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/19 20:37:55 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			pars(char *inp, char **out, t_files *list)
{
	int		i;
	char	*t[2];

	if (inp == NULL)
		return (0);
	if (list->temp != NULL && list->temp[0] == '\0')
	{
		list->temp = NULL;
		return (0);
	}
	i = -1;
	while (inp[++i])
		if (inp[i] == '\n')
			break ;
	t[0] = ft_strdup(*out);
	t[1] = ft_strsub(inp, 0, i);
	ft_strdel(out);
	*out = ft_strjoin(t[0], t[1]);
	ft_strdel(&t[0]);
	ft_strdel(&t[1]);
	if (i == (int)ft_strlen(inp))
		list->temp = NULL;
	else
		list->temp = ft_strsub(inp, i + 1, ft_strlen(inp) - 1);
	return (1);
}

t_files		*find(int fd, t_files *list, int status)
{
	if (status == 1)
	{
		if (list->fd == fd)
			return (list);
		while (list->next)
		{
			if (list->next->fd == fd)
				return (list->next);
			list = list->next;
		}
		list->next = (t_files*)malloc(sizeof(t_files));
		list->next->fd = fd;
		list->next->temp = NULL;
		list->next->next = NULL;
		return (list->next);
	}
	else
	{
		list = (t_files*)malloc(sizeof(t_files));
		list->fd = fd;
		list->temp = NULL;
		list->next = NULL;
		return (list);
	}
}

int			algo(int fd, char **line, t_files *list)
{
	int		i;
	int		chk;
	char	*buff;

	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = 0;
		if (i < 0)
			return (-1);
		if ((chk = pars(buff, line, list)) >= 0)
			if (ft_strchr(buff, '\n'))
			{
				ft_strdel(&buff);
				return (1);
			}
		ft_bzero(buff, BUFF_SIZE);
	}
	ft_strdel(&buff);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	int				i;
	t_files			*list;
	static t_files	*head;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	if (!head)
		head = find(fd, head, 0);
	list = find(fd, head, 1);
	if ((i = 0) == 0 && list->temp != NULL && ft_strchr(list->temp, '\n'))
		i = 1;
	if ((pars(list->temp, line, list)) == 1 && i != 0)
		return (1);
	i = algo(fd, line, list);
	if (i == -1)
	{
		free(*line);
		return (-1);
	}
	else if ((i == 0 && ft_strcmp(*line, "\0")) || i == 1)
		return (1);
	free(*line);
	return (0);
}
