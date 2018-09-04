
#include <stddef.h>
#include <string.h>

int strcmp(const char *s1, const char *s2) {
  int i = 0;
 	while (s1[i]) {
        	if (s1[i] > s2[i]) return s1[i] - s2[i];
        	if (s1[i] < s2[i]) return s1[i] - s2[i];
        	i++;
    	}
    	return 0;
}

size_t strlen(const char *s) {
  size_t n = 0;
    	while (s[n] != '\0') {
        	n++;
    	}
    	return n;
}

char *strchr(const char *s, int c) {
  	while (1) {
        	if (*s == c) return (char*)s;
        	if (*s == '\0') return NULL;
        	s++;
	}
}

size_t strspn(const char *str, const char *accept) {
  	size_t n;
    	const char* p;
    	for (n = 0; *str; str++, n++) {
        	for (p = accept; *p && *p != *str; p++){};
        	if (!*p) break;
    	}
    	return n;
}

size_t strcspn(const char *str, const char *reject) {
  	size_t n;
    	const char* p;
    	for (n = 0; *str; str++, n++) {
        	for (p = reject; *p && *p != *str; p++){};
        	if (*p) break;
    	}
    	return n;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
  	char *res;
  	char *oldptr;
  	if (!str) {
    		str = *saveptr;
    		if (!str) {
      			return NULL;
    		}
  	}
  	while (!strcspn(str, delim) && *str) {
    		str++;
  	}
  	if (!*str) {
    		return NULL;
  	}
  	res = str;
  	oldptr = str + strcspn(str, delim);
  	if (*oldptr) {
    		*oldptr = '\0';
    		*saveptr = oldptr + 1;
  	} else {
    		*saveptr = oldptr;
  	}
  	return res;
}
