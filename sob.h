#ifndef SOB_H
#define SOB_H

#include<stddef.h>
#include<stdbool.h>

static size_t nopos = -1;

typedef struct 
{
    const char * str;
    size_t length;
} sob_t;

sob_t sob_create(const char * str, size_t length);
sob_t sob_create_from_cstr(const char * str);
sob_t sob_triml(sob_t * s);
sob_t sob_trimr(sob_t * s);
sob_t sob_trim(sob_t * s);
void sob_swap(sob_t * s1, sob_t * s2);
void sob_copy(sob_t * s, char * dist, size_t count);
sob_t sob_substr(sob_t * s, size_t pos, size_t count);
bool sob_compare(sob_t * s1, sob_t * s2);
bool sob_contains(sob_t * s, const char * sub, size_t sub_length);
size_t sob_find(sob_t * s, const char * sub, size_t sub_length);
bool sob_starts_with(sob_t * s, const char * sub, size_t sub_len);
bool sob_ends_with(sob_t * s, const char * sub, size_t sub_len);
const char * sob_at(sob_t * s, size_t index);
size_t sob_length(sob_t * s);
bool sob_is_empty(sob_t * s);
void sob_print(sob_t * s);

#endif // SOB_H

/////////////////////////////////////////////////////////////////

#ifdef SOB_IMPLEMENTATION

#include<stdio.h>
#include<string.h>

//TODO: null checking
sob_t sob_create(const char * str, size_t length)
{
    return (sob_t) {
        .str = str,
        .length = length
    };
}

sob_t sob_create_from_cstr(const char * str)
{
    return (sob_t) {
        .str = str,
        .length = strlen(str)
    };
}

sob_t sob_triml(sob_t * s)
{
    size_t offset = 0;
    for (size_t i = 0; i < s->length; ++i) {
        
        if (s->str[i] != ' ')
            break;
        
        offset += 1;
    }
    
    sob_t result = sob_create(s->str + offset, s->length - offset);
    
    return result;
}

sob_t sob_trimr(sob_t * s)
{
    size_t offset = 0;
    for (int i = s->length - 1; i >= 0; --i) {
        if (s->str[i] != ' ')
            break;

        offset += 1;
    }
   
    sob_t result = sob_create(s->str, s->length - offset);
    
    return result;
}

sob_t sob_trim(sob_t * s)
{
    sob_t result = sob_triml(s);
    
    return sob_trimr(&result);
}

void sob_swap(sob_t * s1, sob_t * s2)
{
    sob_t tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void sob_copy(sob_t * s, char * dist, size_t count)
{
    strncpy(dist, s->str, count);
    strncpy(dist + count, "\0", 1);
}

sob_t sob_substr(sob_t * s, size_t pos, size_t count)
{
    size_t index = pos - 1;
    return sob_create(s->str + index, count);
}

bool sob_compare(sob_t * s1, sob_t * s2)
{
    if (s1 == s2) return true;
    
    if (s1->length > s2->length || s2->length > s1->length)
        return false;
    
    for (size_t i = 0; i < s1->length; ++i) {
       if (s1->str[i] != s2->str[i]) {
            return false;
        }
    }

    return true;
}

bool sob_contains(sob_t * s, const char * sub, size_t sub_length)
{
    if (sub_length > s->length) return false;
    
    size_t i = 0;
    size_t j = 0;
    
    while (j < sub_length && i < s->length) {
        if (sub[j] != s->str[i]) {
            j = 0;
            ++i;
            continue;
        }

        ++j;
        ++i;
    }
    
    return j == 0 ? false : true;
}

size_t sob_find(sob_t * s, const char * sub, size_t sub_length)
{
    if (sub_length > s->length) return false;
    
    size_t i = 0;
    size_t j = 0;
    
    while (j < sub_length && i < s->length) {
        if (sub[j] != s->str[i]) {
            j = 0;
            ++i;
            continue;
        }
        
        ++j;
        ++i;
    }
    
    return j == 0 ? nopos : (i - j);
}

bool sob_starts_with(sob_t * s, const char * sub, size_t sub_len)
{
    return sob_find(s, sub, sub_len) == 0;
}

bool sob_ends_with(sob_t * s, const char * sub, size_t sub_len)
{
    return (sob_find(s, sub, sub_len) + sub_len) == s->length;
}

const char * sob_at(sob_t * s, size_t index)
{   
    return s->str[index];
}

size_t sob_length(sob_t * s)
{
    return s->length;
}

bool sob_is_empty(sob_t * s)
{
    return s->length > 0 ? false : true;
}

void sob_print(sob_t * s)
{
    char arr[s->length];
    for (size_t i = 0; i < s->length; ++i)
        arr[i] = s->str[i];

    arr[s->length] = '\0';

    printf("%s\n", arr);
}


#endif // SOB_IMPLEMENTATION
