#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <functional> 
#include <iomanip>

using namespace std;

long long int sum_val(vector<int> numbers) {
    return accumulate(numbers.begin(), numbers.end(), 0LL);
}

long long int sum_ref(const vector<int>& numbers) {
    return accumulate(numbers.begin(), numbers.end(), 0LL);
}

long long int sum_ptr(const int* numbers, size_t size) {
    return accumulate(numbers, numbers + size, 0LL);
}

int main() {

    constexpr int size = 1000;
    vector<int> v(size); // A vector with 1000 elements
    iota(v.begin(), v.end(), 0); // Fill the vector with 0, 1, 2, 3, ...
    cout<<sum_val(v)<<endl;
    cout<<sum_ref(v)<<endl;

    v.clear();
    auto* ptr = v.data();
    
    cout<<sum_val(v)<<endl;
    cout<<sum_ptr(ptr, size)<<endl;

    return 0;
}