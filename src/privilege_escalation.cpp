#include <iostream>
#include <string>
#include <cstdlib>
#include <numeric>



void root_privileged_print(std::string message, int user){
    if (user==0xbada55){
    std::cout<<"Root: "<<message<<std::endl;
    }

    if(user == 0xdeadbeef){
        std::cout<<"Users do not have the rights to print"<<std::endl;
    }
}

void injection(){
    volatile unsigned int a = 0;
    volatile unsigned int* p = &a;
    for (int i = -500; i < 500; i++){
        if (p[i] == 0xdeadbeef){
            p[i] = 0xbada55;
            break;
        }
    }
}

int main(){
    auto user = 0xdeadbeef;
    injection();
    root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
    return 0;
}