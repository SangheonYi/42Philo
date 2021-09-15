/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:25:42 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	life_cycle(t_philo *phi)
{
	int	i;

	i = phi->info->rules[SUM_PH];
	init_philo(phi);
	if (pthread_create(&phi->th, NULL, (void *)life_check, phi))
	{
		sem_wait(phi->info->write);
		write(1, "Threads error\n", 10);
		sem_post(phi->info->end);
	}
	pthread_detach(phi->th);
	if (phi->must_eat != 0)
		while (!philo_life(phi))
			;
	sem_wait(phi->info->first);
	while (i--)
		sem_wait(phi->info->must_eat);
	sem_post(phi->info->end);
	exit(0);
}
