/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by hmin              #+#    #+#             */
/*   Updated: 2021/02/23 09:17:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	life_cycle(t_philo *phi)
{
	sem_wait(phi->info->last_eat);
	phi->t_start = cur_time();
	phi->last_eat = phi->t_start;
	sem_post(phi->info->last_eat);
	while (is_absent(phi))
		usleep(10);
	while (!phi->info->dead_phi && phi->must_eat)
		philo_life(phi);
}
