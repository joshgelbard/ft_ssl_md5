CC = gcc
CFLAGS += -MMD -Wall -Wextra -pedantic #-Werror

NAME = ft_ssl
OBJECTS = $(NAME).o \
		  md5.o \
		  md5_value_tables.o \
		  md5_basic_transforms.o \

all: $(NAME)

$(NAME): $(OBJECTS)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

DEPENDS = $(OBJECTS:.o=.d)
-include $(DEPENDS)
