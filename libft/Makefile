TARGET = libft.a

SRC = ft_isspace.c\
	ft_sitoa.c\
	ft_isdigit.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_substr.c\
	ft_strncmp.c

OBJS := $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

ARNAME = ar rcs $(TARGET)

RM = rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
