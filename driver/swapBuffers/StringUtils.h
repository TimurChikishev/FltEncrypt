#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* mystrchr(const char* s, const char c) {
    while (*s && *s != c)
        ++s;
    return (*s) ? (char*)s : NULL;
}

char* mystrtok(char* str, const char* delim) {
    static char* next;

    if (str) {
        next = str;
        while (*next && mystrchr(delim, *next))
            *next++ = '\0';
    }

    if (!*next)
        return NULL;

    str = next;

    while (*next && !mystrchr(delim, *next))
        ++next;
    while (*next && mystrchr(delim, *next))
        *next++ = '\0';

    return str;
}

char* replaceWord(const char* s, const char* oldW, const char* newW)
{

    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char*)ExAllocatePoolWithTag(NonPagedPool, i + cnt * (newWlen - oldWlen) + 1, RESULT_REPLACE_WORD_TAG);

    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}


char* subString(const char* input, int offset, int len)
{
    static char buf[1025];
    int input_len = strlen(input);
    if (offset + len > input_len)
    {
        return NULL;
    }

    strncpy(buf, input + offset, len);
    return buf;
}

//int checkInSettings(char* buf, UNICODE_STRING checker) {
//    char DELIM[10] = " ";
//    char * p;
//    for (p = mystrtok(buf, DELIM); p; p = mystrtok(NULL, DELIM)) {
//     
//        UNICODE_STRING required_ext = RTL_CONSTANT_STRING(buf);
//  
//        if (RtlEqualUnicodeString(
//            &required_ext,
//            &checker,
//            FALSE)) { 
//            DbgPrint("[FltEncrypt] checkInSettings = %s\n", p);
//            return 1;
//        }
//    } 
//    DbgPrint("[FltEncrypt] ERROR checkInSettings");
//    return 0;
//}