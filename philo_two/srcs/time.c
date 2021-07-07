/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:41:30 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/25 14:37:29 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

time_t		get_time_since_start(t_timeval start)
{
	t_timeval	now;
	time_t		diff;
	time_t		time_since;

	gettimeofday(&now, NULL);
	diff = now.tv_sec - start.tv_sec;
	time_since = now.tv_usec - start.tv_usec + (1000000 * diff);
	return (time_since / 1000);
}

int			diff_ms(t_timeval t1, t_timeval t2)
{
	return (((t1.tv_sec - t2.tv_sec) * 1000000) +
		(t1.tv_usec - t2.tv_usec)) / 1000;
}

void		msleep(int u_seconds)
{
	usleep(u_seconds * 1000);
}
