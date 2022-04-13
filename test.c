#define SOB_IMPLEMENTATION
#include "sob.h"

int main()
{
    const char * str = "Hey,What'scracking.Done.";
    const char * str2 = "Boi,ohBoi!";

    sob_t s1 = sob_create_from_cstr(str);
    sob_t s2 = sob_create_from_cstr(str2);

    //s = sob_triml(&s);

    // s1 = sob_trim(&s1);

    //sob_swap(&s1, &s2);

    //char arr[100];
    //sob_copy(&s1, arr, 5);
    
    sob_t s3 = sob_create_from_cstr(str);
    const char * sub = "ne";
    size_t len = strlen(sub);

    printf("%d\n", sob_ends_with(&s1, sub, len));
    
    /*
    size_t x;
    if ((x = sob_find(&s1, sub, len)) != nopos) {

        printf("%lu\n", x);
    } else {
        printf("Not found!\n");
    }
    */
    
    sob_print(&s3);
    
    return 0;
}
