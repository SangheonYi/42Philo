# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <sayi@student.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 19:45:38 by hmin              #+#    #+#              #
#    Updated: 2021/02/26 13:14:38 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =	philo_one

CC              =	gcc

VPATH 			=	./srcs/:./srcs/utils/

SRCS			=	take_and_drop_forks.c \
					ft_putnbr_light.c \
					thread_start.c \
					wrap_writing.c \
					print_log.c \
					clear_space.c \
					dead_status.c \
					spend_time.c \
					wrap_chngs.c \
					life_check.c \
					philo_life.c \
					print_dead.c \
					cur_time.c \
					main_philo.c \
					philo_pars.c \
					life_cycle.c \
					is_absent.c \
					ft_atoi.c

HEADERS_DIR		=	./srcs/includes/

HEAD		=	$(addprefix $(HEADERS_DIR), philo_one.h)

INCLUDES        =   -I$(HEADERS_DIR)

FLAGS           =   $(INCLUDES) -Wall -Wextra -pthread -O2

OBJ_DIR         =   ./obj/

O_FILE          =   $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

.PHONY: all

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

$(O_FILE): $(OBJ_DIR)%.o: %.c $(HEAD)
	$(CC) -c $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@rm -f $(O_FILE)
	@rm -f $(D_FILE)
	@rm -rf $(OBJ_DIR)

PHONY: fclean

fclean: clean
	@rm -f $(NAME)

.PHONY: re

re:     fclean all
