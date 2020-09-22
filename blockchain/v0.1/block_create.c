#include "blockchain.h"

/**
* block_create - creates a new block
* @prev: previous block
* @data: data for a new block
* @data_len: length of @data
* Return: a block or NULL if failed
*/
block_t *block_create(block_t const *prev, int8_t const *data,
					  uint32_t data_len)
{
	block_t *block;
	uint32_t max_len = data_len > BLOCKCHAIN_DATA_MAX ?
		   BLOCKCHAIN_DATA_MAX : data_len;

	block = malloc(sizeof(*block));
	if (!block)
		return (NULL);

	memcpy(block->data.buffer, data, max_len);
	block->data.len = max_len;

	memset(block->hash, 0, 32);

	memcpy(block->info.prev_hash, prev->hash, 32);
	block->info.index = prev->info.index + 1;
	block->info.timestamp = (uint64_t)time(NULL);
	block->info.difficulty = 0;
	block->info.nonce = 0;
	return (block);
}
