CC = gcc
CFLAGS += -Wall -Wextra -pedantic -Werror
CPPFLAGS += -MMD

NAME = ft_ssl

OBJECTS = \
		  algorithm_lookup.o \
		  debug.o \
		  digest.o \
		  hash_digest_common.o \
		  md5_digest.o \
		  md5_internal.o \
		  memprint.o \
		  reverse_byte_order.o \
		  sha256_digest.o \
		  sha256_internal.o \

MODULES = \
		  digest \
		  md5 \
		  test \
		  util \
		  sha256 \

VPATH = $(MODULES)

CFLAGS += $(addprefix -I, $(MODULES)) -I.

all: $(NAME)

$(NAME): $(NAME).o $(OBJECTS)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
dev: CFLAGS += -include string.h -include assert.h -include stdio.h -Wno-error
dev: all
redev: fclean dev

TEST_MAIN = test-runner
TEST_OBJECTS = \
			   test_md5_digest.o \
			   test_sha256_digest.o \

test: CFLAGS += -include string.h -include assert.h -include stdio.h -Wno-error
test: $(TEST_MAIN)
$(TEST_MAIN): $(TEST_MAIN).o $(TEST_OBJECTS) $(OBJECTS)
retest: fclean test

.PHONY: all clean fclean re dev test redev retest

DEPENDS = $(OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)
-include $(DEPENDS)
