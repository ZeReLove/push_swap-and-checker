/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:41:45 by mrolfe            #+#    #+#             */
/*   Updated: 2019/06/21 17:29:57 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stack_has_n(char **stack, char **line)
{
	char	*ptr;

	ptr = ft_strchr(*stack, '\n');
	if (ptr)
	{
		*ptr = '\0';
		*line = ft_strdup(*stack);
		if (!line)
			return (-1);
		ptr = ft_strdup(ptr + 1);
		if (!ptr)
			return (-1);
		free(*stack);
		*stack = ptr;
		return (1);
	}
	return (0);
}

static int	read_line(const int fd, char **stack, char **line, char *buf)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*stack)
		{
			tmp = ft_strjoin(*stack, buf);
			if (!tmp)
				return (-1);
			free(*stack);
			*stack = tmp;
		}
		else
			*stack = ft_strdup(buf);
		if (stack_has_n(stack, line))
			break ;
	}
	if (ret > 0)
		return (1);
	else
		return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD];
	char		*buf;
	int			ret;

	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	if (stack[fd])
	{
		ret = stack_has_n(&stack[fd], line);
		if (ret)
			return (ret);
	}
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = read_line(fd, &stack[fd], line, buf);
	free(buf);
	if (ret || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
