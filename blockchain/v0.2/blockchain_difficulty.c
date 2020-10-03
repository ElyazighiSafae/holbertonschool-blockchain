#include "blockchain.h"

/**
* blockchain_difficulty - get new blockchain difficulty
* @blockchain - blockchain
* Return: return new difficulty
*/
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
	block_t *last, *prev;
	uint64_t diff;
	uint32_t new_difficulty;

	if (!blockchain)
		return (0);
	last = llist_get_tail(blockchain->chain);
	if (!last)
		return (0);
	if (last->info.index == 0 ||
		last->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL != 0)
	{
		return (last->info.index);
	}
	prev = llist_get_node_at(blockchain->chain,
							 last->info.index - DIFFICULTY_ADJUSTMENT_INTERVAL);
	if (!prev)
		return (0);
	diff = last->info.timestamp - prev->info.timestamp;
	new_difficulty = last->info.difficulty;
	if (diff < DIFFICULTY_ADJUSTMENT_INTERVAL * BLOCK_GENERATION_INTERVAL / 2)
		++new_difficulty;
	else if (diff >
			 DIFFICULTY_ADJUSTMENT_INTERVAL * BLOCK_GENERATION_INTERVAL * 2)
		--new_difficulty;
	return (new_difficulty);
}
