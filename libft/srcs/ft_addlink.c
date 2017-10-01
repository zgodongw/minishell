/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:42:08 by zgodongw          #+#    #+#             */
/*   Updated: 2017/09/30 13:36:28 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addlink(t_list **head, char *str)
{
	t_list *newnode;
	t_list *temp;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->content = str;
	newnode->next = NULL;
	temp = *head;
	if (*head == NULL)
		*head = newnode;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}
