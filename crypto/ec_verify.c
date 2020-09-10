#include "hblk_crypto.h"

/**
* ec_verify - verify msg with EC_KEY pair
* @key: key pair
* @msg: message to sign
* @msglen: len of message
* @sig: signature
* Return: 1 if signature is valid, 0 otherwise
*/
int ec_verify(EC_KEY const *key, uint8_t const *msg,
				 size_t msglen, sig_t const *sig)
{
	uint8_t digest[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (0);
	if (!sha256((int8_t *)msg, msglen, digest))
		return (0);
	if (ECDSA_verify(0, digest, SHA256_DIGEST_LENGTH,
					  sig->sig, sig->len, (EC_KEY *)key) < 1)
		return (0);
	return (1);
}
