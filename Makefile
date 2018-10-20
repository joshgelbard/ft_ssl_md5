CC = gcc
CFLAGS += -Wall -Wextra -pedantic
CPPFLAGS += -MMD

NAME = ft_ssl

OBJECTS = \
		  algorithm_lookup.o \
		  debug.o \
		  digest.o \
		  hash_digest_common.o \
		  md5_basic_transforms.o \
		  md5_digest.o \
		  md5_value_tables.o \
		  memprint.o \
		  reverse_byte_order.o \

MODULES = \
		  digest \
		  md5 \
		  test \
		  util \

VPATH = $(MODULES)

CFLAGS += $(addprefix -I, $(MODULES)) -I.

all: CFLAGS += -Werror
all: $(NAME)

$(NAME): $(NAME).o $(OBJECTS)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
dev: CFLAGS += -include assert.h -include stdio.h
dev: all
redev: fclean dev

TEST_MAIN = test-runner
TEST_OBJECTS = test_md5_digest.o \

test: CFLAGS += -include assert.h -include stdio.h
test: $(TEST_MAIN)
$(TEST_MAIN): $(TEST_MAIN).o $(TEST_OBJECTS) $(OBJECTS)
retest: fclean test

.PHONY: all clean fclean re dev test redev retest

DEPENDS = $(OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)
-include $(DEPENDS)
