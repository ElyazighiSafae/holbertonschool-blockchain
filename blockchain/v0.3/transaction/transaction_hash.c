#include "transaction.h"

/**
* tin_to_buffer - copies transaction outputs into buffer
* @tr: transaction node
* @idx: index of @tr
* @buffer: buffer to copy transaction
* Return: 0 on success
*/
int tin_to_buffer(llist_node_t tr, unsigned int idx, void *buffer)
{
	memcpy(buffer + idx * TR_IN_HASH_LEN, tr, TR_IN_HASH_LEN);
	return (0);
}

/**
* tout_to_buffer - copies transaction inputs into buffer
* @tr: transaction node
* @idx: index of @tr
* @buffer: buffer to copy transaction
* Return: 0 on success
*/
int tout_to_buffer(llist_node_t tr, unsigned int idx, void *buffer)
{
	memcpy(buffer + idx * TR_OUT_HASH_LEN, tr, TR_OUT_HASH_LEN);
	return (0);
}

/**
* unspent_tx_out_create - creates a unspent transaction output
* @unspent: points to the unspent transaction output to be converted
* to a transaction input
* Return: an unspent transaction output
*/
uint8_t *transaction_hash(transaction_t const *transaction,
						  uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t tin_size, tout_size;
	int8_t *buffer;

	if (!transaction)
	{
		return (NULL);
	}
	tin_size = llist_size(transaction->inputs) * TR_IN_HASH_LEN;
	tout_size = llist_size(transaction->outputs) * TR_OUT_HASH_LEN;
	buffer = malloc(tin_size + tout_size);
	if (!buffer)
	{
		return (NULL);
	}
	llist_for_each(transaction->inputs, tin_to_buffer, buffer);
	llist_for_each(transaction->outputs, tout_to_buffer, buffer + tin_size);
	return (sha256(buffer, tin_size + tout_size, hash_buf));
}
