SRC = get_next_line.c\
		get_next_line_utils.c


OBJS := $(SRC:%.c=%.o)

NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = .

HEADERS = -I$(INC_DIR)

RM = rm -f

ARNAME = ar rcs $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re bonus
