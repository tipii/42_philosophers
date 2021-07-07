/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:41:29 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/25 16:52:12 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			error_malloc(void)
{
	ft_putstr_fd("Error malloc", 1);
	return (1);
}

int			init_first(t_all *all)
{
	if (!(all->philosophers = malloc(sizeof(t_philosopher *) *
		all->args->nbr_of_philos)))
		return (error_malloc());
	if (!(all->philosophers[0] = malloc(sizeof(t_philosopher))))
		return (error_malloc());
	all->philosophers[0]->pos = 0;
	if (!(all->philosophers[0]->left_fork = malloc(sizeof(t_fork))))
		return (error_malloc());
	return (0);
}

int			init_last(t_all *all, int i)
{
	if (!(all->philosophers[i] = malloc(sizeof(t_philosopher))))
		return (error_malloc());
	all->philosophers[i]->pos = all->args->nbr_of_philos - 1;
	if (!(all->philosophers[i]->left_fork = malloc(sizeof(t_fork))))
		return (error_malloc());
	all->philosophers[i]->right_fork = all->philosophers[i - 1]->left_fork;
	all->philosophers[0]->right_fork = all->philosophers[i]->left_fork;
	return (0);
}

int			init_table(t_all *all)
{
	int i;

	i = 1;
	all->someone_dead = 0;
	if (init_first(all))
		return (1);
	while (i < all->args->nbr_of_philos - 1)
	{
		if (!(all->philosophers[i] = malloc(sizeof(t_philosopher))))
			return (error_malloc());
		all->philosophers[i]->pos = i;
		if (!(all->philosophers[i]->left_fork = malloc(sizeof(t_fork))))
			return (error_malloc());
		all->philosophers[i]->right_fork = all->philosophers[i - 1]->left_fork;
		i++;
	}
	if (init_last(all, i))
		return (1);
	return (0);
}

void		init_mutexes(t_all *all)
{
	int i;

	pthread_mutex_init(&all->mic, NULL);
	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		gettimeofday(&all->philosophers[i]->last_meal, NULL);
		all->philosophers[i]->all = all;
		all->philosophers[i]->quit = 0;
		all->philosophers[i]->count_eat = 0;
		all->philosophers[i]->mic = &all->mic;
		all->philosophers[i]->args = all->args;
		pthread_mutex_init(&all->philosophers[i]->eating_state, NULL);
		pthread_mutex_init(&all->philosophers[i]->left_fork->mutex, NULL);
		i++;
	}
}
