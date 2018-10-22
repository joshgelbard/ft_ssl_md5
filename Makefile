CC = gcc
CFLAGS += -Wall -Wextra -pedantic -Werror
CPPFLAGS += -MMD

NAME = ft_ssl

OBJECTS = \
		  algorithm_lookup.o \
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
		  xprint.o \
		  xstrlen.o \
		  xstrcmp.o \
		  xmemcpy.o \
		  zalloc.o \
		  xzero.o \
		  xperror.o \

MODULES = \
		  digest \
		  md5 \
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

.PHONY: all clean fclean re dev redev

DEPENDS = $(OBJECTS:.o=.d)
-include $(DEPENDS)
