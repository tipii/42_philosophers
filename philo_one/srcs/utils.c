/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:05:37 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/27 15:33:06 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_atoi(const char *str)
{
	long	atoi;
	int		i;

	i = 0;
	atoi = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			atoi = (atoi * 10) + str[i] - 48;
			i++;
		}
		else
			return (-1);
	}
	return (atoi);
}

void		print_state(t_philosopher *philo, char *str)
{
	if (!philo->all->someone_dead)
	{
		pthread_mutex_lock(philo->mic);
		ft_putnbr_fd(get_time_since_start(philo->all->start), 1);
		write(1, " ", 1);
		ft_putnbr_fd(philo->pos + 1, 1);
		write(1, " ", 1);
		ft_putstr_fd(str, 1);
		write(1, "\n", 1);
		pthread_mutex_unlock(philo->mic);
	}
}

t_all		*init_all(t_all *all)
{
	if (!(all = malloc(sizeof(t_all))))
		return (NULL);
	if (!(all->args = malloc(sizeof(t_args))))
		return (NULL);
	return (all);
}
