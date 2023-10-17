/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_collector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:50 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 18:56:34 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_collector	*new_node(void *addr)
{
	t_collector	*node;

	node = (t_collector *)malloc(sizeof(t_collector));
	if (!node)
		return (NULL);
	node->adr = addr;
	node->next = NULL;
	return (node);
}

t_collector	**append_addr(t_collector **g_root, void *addr)
{
	t_collector	*node;

	node = new_node(addr);
	if (!node)
		return (NULL);
	if (!*g_root)
		*g_root = node;
	else
	{
		node->next = *g_root;
		*g_root = node;
	}
	return (g_root);
}

void	free_memory(t_collector **g_root)
{
	t_collector	*tmp;

	while (*g_root)
	{
		tmp = *g_root;
		*g_root = (*g_root)->next;
		free(tmp->adr);
		free(tmp);
	}
}

void	ft_malloc(t_collector **g_root, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_memory(g_root);
		exit(1);
	}
	append_addr(g_root, ptr);
}

void	ft_collect(t_collector **g_root, t_collector *node)
{
	if(!node)
		return ;
	ft_collect(g_root, node->next);
	free(node->adr);
	free(node);
}
