// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0)
		return NULL;

	void *item;
	item = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (item == MAP_FAILED)
		return NULL;

	mem_list_add(item, size);

	return item;
}

void *calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0)
		return NULL;

	if (size == 0)
		return NULL;

	size_t *item;
	size_t prod = nmemb * size;
	item = (size_t *) malloc(prod);

	if (item == MAP_FAILED)
		return NULL;

	memset(item, 0, prod);
	return item;
}

void free(void *ptr)
{
	struct mem_list *item;
	item = mem_list_find(ptr);

	size_t len = item->len;

	munmap(ptr, len);
	mem_list_del(item->start);
}

void *realloc(void *ptr, size_t size)
{
	void *aux = malloc(size);
	if (aux == MAP_FAILED)
		return NULL;

	memcpy(aux, ptr, size);
	return aux;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *aux;
	aux = realloc(ptr, nmemb * size);

	if (aux)
		return aux;
	else
		return NULL;
}
