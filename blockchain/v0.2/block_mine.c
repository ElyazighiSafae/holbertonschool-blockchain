#include "blockchain.h"

/**
* block_mine - mine block
* @block: block to be mined
*/
void block_mine(block_t *block)
{
	if (!block)
		return;
	srandom((uint32_t)time(NULL));
	do {
		block->info.nonce = (uint64_t)random();
		if (!block_hash(block, block->hash))
			return;
	} while (hash_matches_difficulty(block->hash, block->info.difficulty) == 0);
}
