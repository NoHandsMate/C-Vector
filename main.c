
#include <stddef.h>
#include "Vector.h"




int main() {
    
    vector* vec = init_vector(); 

    add_element(vec, 5.f);
    
    float a = *get_element(vec, 0);

    printf("%f", a);

    free_vec(vec);

    return -1;
}