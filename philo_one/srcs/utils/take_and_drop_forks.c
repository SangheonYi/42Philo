/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:29:51 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:28:45 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_forks(t_philo *phi)
{
	if (phi->name % 2)
		pthread_mutex_lock(&phi->info->forks[phi->waf[LEFT]]);
	pthread_mutex_lock(&phi->info->forks[phi->waf[RIGHT]]);
	mutex_wrap_writing(phi, TAKE_F, 17, print_log);
	if (!(phi->name % 2))
		pthread_mutex_lock(&phi->info->forks[phi->waf[LEFT]]);
	mutex_wrap_writing(phi, TAKE_F, 17, print_log);
}

void	drop_forks(t_philo *phi)
{
	pthread_mutex_unlock(&phi->info->forks[phi->waf[RIGHT]]);
	pthread_mutex_unlock(&phi->info->forks[phi->waf[LEFT]]);
}
