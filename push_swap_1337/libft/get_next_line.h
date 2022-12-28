/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <imaaitat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:21:41 by imaaitat          #+#    #+#             */
/*   Updated: 2022/12/24 14:35:14 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t			ft_srlen(char *str);
int				new_line(char *s, int c);
char			*ft_srjoin(char *s1, char *s2);
char			*get_next_line(int fd);
char			*get_line(char *save);
char			*ft_save(char *save);
char			*ft_read_and_save(int fd, char *save);

#endif
