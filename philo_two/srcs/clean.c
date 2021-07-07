/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:42:35 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/26 15:09:43 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		free_all(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		sem_unlink(all->philosophers[i]->name);
		sem_close(all->philosophers[i]->eating_state);
		free(all->philosophers[i]->name);
		free(all->philosophers[i]);
		i++;
	}
	free(all->philosophers);
	sem_unlink("/mic");
	sem_close(all->mic);
	sem_unlink("/forks");
	sem_close(all->forks);
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
