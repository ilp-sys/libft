# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 13:34:35 by jiwahn            #+#    #+#              #
#    Updated: 2022/07/18 18:57:49 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

RM = rm
RMFLAGS = -f

SRC_DIR_P1 = ./part1/
SRC_DIR_P2 = ./part2/
SRC_DIR_OTHERS = ./others/
SRC_DIR_BONUS = ./bonus/

SRCS_NAME_P1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c

SRCS_NAME_P2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c, ft_putstr_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c

SRCS_NAME_OTHERS = ft_strcpy.c ft_strncat.c ft_strncpy.c ft_strnlen.c

SRCS_NAME_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC = $(addprefix $(SRC_DIR_P1), $(SRC_NAME_P1)) $(addprefix $(SRC_DIR_P2), $(SRC_NAME_P2)) $(addprefix $(SRC_DIR_OTHERS), $(SRC_NAME_OTHERS)) 
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRC_NAME_BONUS))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRCS_NAME_P1:.c=.o) $(SRCS_NAME_P2:.c=.o) $(SRCS_NAME_OTHERS:.c=.o)
OBJ_NAME_BONUS = $(SRCS_NAME_BONUS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
OBJS_B = $(addprefix $(OBJ_DIR), $(OBJ_NAME_BONUS))

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

bonus :
	make WITH_BONUS=1

$(NAME): $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR_P1)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)%.o : $(SRC_DIR_P2)%.c
	@$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)%.o : $(SRC_DIR_OTHERS)%.c
	@$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)%.o : $(SRC_DIR_BONUS)%.c
	@$(CC) $(CFLAGS) $< -c -o $@

.PHONY: all clean fclean re bonus
