#include <iostream>
#include <stdint.h>

typedef struct  t_Data{
}  Data;


uintptr_t   serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*   deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}


int main(){
    Data test;
    std::cout << "Before :\t" << &test << std::endl;
    uintptr_t test_ser = serialize(&test);
    Data *res = deserialize(test_ser);
    std::cout << "After :\t\t" << res << std::endl;
    if (&test == res)
        std::cout << "Pointer value is the same" << std::endl;
    else
        std::cout << "Pointer value is not the same" << std::endl;
    return 0;
}
