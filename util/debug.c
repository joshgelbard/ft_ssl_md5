#include "hash_ctx.h"
#include "hash_algorithm.h"
#include <stdio.h>
#include <stdlib.h>

// fixme: don't turn in this file
void print_ctx(struct s_hash_ctx *this, int everything)
{
	printf("CONTEXT-->\n");
	printf("\tmessage_bitsize: %lu\n", this->message_bitsize);
	printf("\tblock_offset: %lu\n", this->block_offset);
	printf("\tblocks processed: %lu\n", this->processed_blocks);
	if (everything == 1)
	{
		printf("\ndigest: ");
		for (size_t i = 0; i < this->class->digest_size; i++)
			printf("%02x", ((unsigned char *)(this->digest))[i]);
		printf("\n");
		printf("block: ");
		for (size_t i = 0; i < this->class->block_size; i++)
			printf("%02x", ((unsigned char *)(this->block))[i]);
		printf("\n");
	}
	printf("<--END\n");
}

