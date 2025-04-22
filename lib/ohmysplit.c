/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ohmysplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:43:05 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 17:47:45 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**split_string(const char *s, char c)
{
	char	**result;
	int		i;
	int		start;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc_safe(NULL, (words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s == c)
			s++;
		start = 0;
		while (s[start] && s[start] != c)
			start++;
		result[i] = malloc_safe(NULL, start + 1);
		strncpy(result[i], s, start);
		result[i][start] = '\0';
		s += start;
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
