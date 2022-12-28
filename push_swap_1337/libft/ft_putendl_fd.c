/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 04:57:46 by imaaitat          #+#    #+#             */
/*   Updated: 2022/10/18 18:15:44 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char	*s, int fd)
{
	char	new;

	if (!s)
		return ;
	new = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &new, 1);
}
