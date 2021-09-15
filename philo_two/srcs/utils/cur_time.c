/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:47:56 by sayi              #+#    #+#             */
/*   Updated: 2021/02/27 12:47:58 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

ssize_t				cur_time(void)
{
	ssize_t			s_time;
	struct timeval	t_start;

	gettimeofday(&t_start, NULL);
	s_time = (t_start.tv_sec * 1000 + t_start.tv_usec / 1000);
	return (s_time);
}
