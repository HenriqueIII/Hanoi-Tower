#ifndef COMMON_H
#define COMMON_H
namespace Common{
    const char * itoa(int n);
    void memset(char * s, char c, int b);
    char * strcpy(char * dest, const char * src);
    int strlen(const char * str);
};
#endif