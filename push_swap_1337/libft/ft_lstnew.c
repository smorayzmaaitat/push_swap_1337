/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:27:13 by imaaitat          #+#    #+#             */
/*   Updated: 2022/10/17 20:53:53 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_t;

	n_t = (t_list *)malloc (sizeof (*n_t));
	if (n_t == 0)
		return (NULL);
	n_t[0].content = content;
	n_t[0].next = NULL;
	return (n_t);
}
