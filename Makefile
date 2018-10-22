CC = gcc
CFLAGS += -Wall -Wextra -pedantic -Werror
CPPFLAGS += -MMD

NAME = ft_ssl

OBJECTS = \
		  algorithm_lookup.o \
		  debug.o \
		  hash_digest_common.o \
		  md5_digest.o \
		  md5_internal.o \
		  memprint.o \
		  reverse_byte_order.o \
		  sha256_digest.o \
		  sha256_internal.o \
		  ft_ssl_module_interface.o \
		  md_module.o \
		  md_module_internal.o \
		  md_digesters.o \
		  md_module_output.o \
		  xputs.o \
		  xprint.o \
		  xstrlen.o \
		  xstrcmp.o \
		  xmemcpy.o \
		  zalloc.o \
		  xzero.o \

MODULES = \
		  digest \
		  md5 \
		  test \
		  util \
		  sha256 \
		  md_module \
		  module_type \

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
