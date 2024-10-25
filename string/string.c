// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int size;
	size = strlen(source);

	for (int i = 0; i < size; i++)
		destination[i] = source[i];

	destination[size] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	int i = 0;

	while (len) {
		destination[i] = source[i];
		i++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i = 0;
	int j = 0;
	while (destination[i] != '\0')
		i++;

	while(source[j] != '\0') {
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	int i = 0;
	int j = 0;
	while (destination[i] != '\0')
		i++;

	while(len) {
		destination[i] = source[j];
		i++;
		j++;
		len--;
	}

	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	size_t size1 = strlen(str1);
	size_t size2 = strlen(str2);
	int i = 0;
	int j = 0;

	if (size1 < size2)
		return -1;

	if (size1 > size2)
		return 1;

	if (size1 == size2) {
		int size = size1;
		while (size) {
		if (str1[i] < str2[j])
			return -1;

		if (str1[i] > str2[j])
			return 1;

		i++;
		j++;
		size--;
		}
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	int i = 0;
	int j = 0;
	while (len) {
		if (str1[i] < str2[j])
			return -1;

		if (str1[i] > str2[j])
			return 1;

		i++;
		j++;
		len--;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *str2;
	int i = 0;

	int size = strlen(str);

	if (size == 0)
		return NULL;

	if (c == '\0')
		return (char *)str;

	while (size) {
		if (str[i] == c) {
			str2 = (char *) str + i;
			return str2;
		}
		i++;
		size--;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	int size;
	size = strlen(str);

	if (size == 0)
		return NULL;

	while (size--) {
		if (str[size - 1] == c)
			return (char *)str + size - 1;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	for (int i = 0; i < (int)strlen(haystack); i++)
		if (haystack[i] == needle[0])
			if (strncmp(haystack + i, needle, strlen(needle)) == 0)
				return (char *)haystack + i;

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int len1 = strlen(haystack);
	int len2 = strlen(needle);

	for (int i = len1- 1; i >= 0; i--)

		if (haystack[i] == needle[len2 - 1])

			if (strncmp(haystack + i - len2 + 1, needle, len2) == 0)
				return (char *)haystack + i - len2 + 1;

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *str1 = (char *)destination;
	const char *str2 = (char *)source;

	int j = 0;
	int i = 0;
	while (num) {
		str1[j] = str2[i];
		i++;
		j++;
		num--;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *str1 = (char *)destination;
	const char *str2 = (char *)source;
	int j = 0;
	int i = 0;
	while (num) {
		str1[j] = str2[i];
		i++;
		j++;
		num--;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *str1 = (const char *)ptr1;
	const char *str2 = (const char *)ptr2;
	int i = 0;
	while (num) {
		if (str1[i] < str2[i])
			return -1;

		if (str1[i] > str2[i])
			return 1;

		i++;
		num--;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *str1 = (char *)source;
	int i = 0;
	while (num) {
		str1[i] = (char)value;
		i++;
		num--;
	}
	return source;
}
