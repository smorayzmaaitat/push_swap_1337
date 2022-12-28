/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <imaaitat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:27:25 by imaaitat          #+#    #+#             */
/*   Updated: 2022/10/20 21:59:56 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	**ft_free(char **rtn)
{
	size_t	i;

	i = 0;
	while (rtn[i])
	{
		free(rtn[i]);
		rtn[i] = NULL;
		i++;
	}
	free(rtn);
	rtn = NULL;
	return (NULL);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word || !str)
	{
		ft_free(&word);
		return (NULL);
	}
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static size_t	count_c(char const *s, char c)
{
	size_t	i;
	size_t	numberof_c;
	size_t	y;

	y = 0;
	if (!s)
		return (0);
	if (s[y] == '\0')
		return (0);
	while (s[y] != c && s[y])
		y++;
	if (s[y] == '\0')
		return (1);
	i = 0;
	numberof_c = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			numberof_c ++;
		while (s[i] != c && s[i])
			i++;
	}
	return (numberof_c);
}

static void	v_z(size_t *start, size_t *end, size_t *i)
{
	*start = 0;
	*end = 0;
	*i = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (0);
	v_z(&start, &end, &i);
	split = (char **) malloc((count_c(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < count_c(s, c))
	{
		while (s[start++] == c)
			end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = word_dup(s, start -1, end);
		if (!split[i++])
			return (ft_free(split));
		start = end;
	}
	split[i] = 0;
	return (split);
}
