#include "hblk_crypto.h"

/**
* sha256 - find hash value (digest) of a sequence of bytes
* @s: byte sequence
* @len: lenght of @s
* @digest: buffer to store the digest
* Return: digest or NULL if failed
*/
uint8_t *sha256(int8_t const *s,
				size_t len,
				uint8_t digest[SHA256_DIGEST_LENGTH])
{
	EVP_MD_CTX *mdctx;
	const EVP_MD *md;

	if (!s || !digest)
		return (NULL);
	md = EVP_sha256();
	if (!md)
		return (NULL);
	mdctx = EVP_MD_CTX_new();
	if (!mdctx)
		return (NULL);
	if (!EVP_DigestInit_ex(mdctx, md, NULL))
		return (NULL);
	if (!EVP_DigestUpdate(mdctx, s, len))
		return (NULL);
	if (!EVP_DigestFinal_ex(mdctx, digest, NULL))
		return (NULL);
	EVP_MD_CTX_free(mdctx);

	return (digest);
}

/**
* ec_sign - sign msg with EC_KEY pair
* @key: key pair
* @msg: message to sign
* @msglen: len of message
* @sig: signature
* Return: buffer to signature
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
				 size_t msglen, sig_t *sig)
{
	uint8_t digest[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (NULL);
	if (!sha256((int8_t *)msg, msglen, digest))
		return (NULL);
	if (!ECDSA_sign(0, digest, SHA256_DIGEST_LENGTH,
					sig->sig, (uint32_t *)&(sig->len), (EC_KEY *)key))
		return (NULL);
	return (sig->sig);
}
