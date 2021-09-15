/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:31:39 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 10:56:09 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_life(t_philo *phi)
{
	take_forks(phi);
	pthread_mutex_lock(&phi->info->last_eat);
	phi->last_eat = cur_time();
	pthread_mutex_unlock(&phi->info->last_eat);
	mutex_wrap_writing(phi, EAT, 10, print_log);
	phi->must_eat--;
	spend_time(phi->info->rules[T_EAT]);
	drop_forks(phi);
	if (!phi->must_eat)
		return ;
	mutex_wrap_writing(phi, SLEEP, 12, print_log);
	spend_time(phi->info->rules[T_SLEEP]);
	mutex_wrap_writing(phi, THINK, 12, print_log);
}
