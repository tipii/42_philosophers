/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:42:35 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/25 16:57:56 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		free_all(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		pthread_mutex_destroy(&all->philosophers[i]->right_fork->mutex);
		free(all->philosophers[i]->right_fork);
		free(all->philosophers[i]);
		i++;
	}
	free(all->philosophers);
	pthread_mutex_destroy(&all->mic);
	free(all->args);
	free(all);
}

void		join_threads(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		pthread_join(all->philosophers[i]->thread, NULL);
		i++;
	}
}
