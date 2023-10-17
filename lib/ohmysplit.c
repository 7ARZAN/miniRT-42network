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

static int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (j);
}

static int	wrds_count(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*wrd_malloc(const char *str, char sep)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

static char	**remove_leaks(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	return (NULL);
}

char	**ohmysplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**buff;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	buff = (char **)malloc(sizeof(char *) * (wrds_count(s, c) + 1));
	if (!buff)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			buff[j] = wrd_malloc(s + i, c);
			if (!buff[j])
				return (remove_leaks(buff));
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	buff[j] = NULL;
	return (buff);
}
