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

t_garbage	*new_node(void *addr)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
	{
		perror("Error: Garbage node allocation failed");
		exit(1);
	}
	node->address = addr;
	node->next = NULL;
	return (node);
}

t_garbage	**append_addr(t_garbage **root, void *addr)
{
	t_garbage	*node;

	if (!root)
		root = malloc(sizeof(t_garbage *));
	if (!root)
	{
		perror("Error: Garbage root allocation failed");
		exit(1);
	}
	*root = NULL;
	node = new_node(addr);
	node->next = *root;
	*root = node;
	return (root);
}

void	collect_node(t_garbage **root, t_garbage *node)
{
	t_garbage	*current;
	t_garbage	*prev;

	if (!root || !*root)
		return ;
	current = *root;
	prev = NULL;
	while (current && current != node)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev)
		prev->next = current->next;
	else
		*root = current->next;
	free(current);
}

void	free_memory(t_garbage **root)
{
	t_garbage	*current;
	t_garbage	*next;

	if (!root || !*root)
		return ;
	current = *root;
	while (current)
	{
		next = current->next;
		if (current->address)
			free(current->address);
		free(current);
		current = next;
	}
	*root = NULL;
}
