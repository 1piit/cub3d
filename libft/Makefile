# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 12:07:23 by ptricaud          #+#    #+#              #
#    Updated: 2026/02/23 15:09:11 by ptricaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_P1	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
    ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
    ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
    ft_strrchr.c ft_tolower.c ft_toupper.c

SRCS_P2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
    ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

GC		= gc_strdup.c \

SRCS_O = $(SRCS_P1) $(SRCS_P2) $(GC)

SRCS_OB = $(SRCS_P1) $(SRCS_P2) $(BONUS) $(GC)

OBJS	= $(SRCS_O:.c=.o)

OBJS_OB = $(SRCS_OB:.c=.o)

CC		= cc

ARFLAGS	= rcs

AR 		= ar

CFLAGS	= -Werror -Wextra -Wall

RM		= rm -f

NAME 	= libft.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) -o $(NAME) $^

bonus:		$(OBJS_OB)
			$(AR) $(ARFLAGS) -o $(NAME) $^
			

clean:		
			$(RM) $(OBJS_OB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean
			make
			

.PHONY:		all clean fclean re bonus