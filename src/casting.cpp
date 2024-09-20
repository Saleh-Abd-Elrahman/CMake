#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <functional> 
#include <iomanip>

using namespace std;

int main() {

    int number = 2;
    
    cout << fixed << setprecision(2);

    float c_style_cast = (float)number;
    cout << "C-style cast: " << c_style_cast << endl;

    float static_cast_val = static_cast<float>(number);
    cout << "static_cast: " << static_cast_val << endl;

    float reinterpret_cast_val = *reinterpret_cast<float*>(&number);
    cout << "reinterpret_cast: " << reinterpret_cast_val << endl;

    auto ptr_2 = 6;
    int reinterpret_cast_ptr = *reinterpret_cast<int*>(&ptr_2);
    double reinterpret_cast_ptr_2 = *reinterpret_cast<double*>(&reinterpret_cast_ptr);
    cout << "reinterpret_cast_twice: " << reinterpret_cast_ptr_2 << endl;

    return 0;
}