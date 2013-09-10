
char * strcpy(char *dest, const char* src) {
    char * r = dest;
    while ((*dest++ = *src++))
        ;
    return r;
}

char * strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

int strcmp(const char* src, const char* dest) {
    int ret = 0;
    while (!(ret = *(unsigned char *) src - *(unsigned char *) dest) && *dest)
        ++src, ++dest;
    if (ret < 0)
        ret = -1;
    else if (ret > 0)
        ret = 1;

    return (ret);
}

int strncmp(const char* src, const char* dest, size_t n) {
    int ret = 0;
    size_t i = 0;
    while (i < n && !(ret = *(unsigned char *) src - *(unsigned char *) dest)
            && *dest)
        ++src, ++dest, ++i;
    if (ret < 0)
        ret = -1;
    else if (ret > 0)
        ret = 1;

    return (ret);
}

char *strcat(char *dest, char *src) {
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}

char* strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
