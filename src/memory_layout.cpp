#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <functional> 
#include <iomanip>

using namespace std;

int main() {

    vector<int> v(1000); 
    cout<<sizeof(v)<<endl;

    int arr[1000]; 
    cout<<sizeof(arr)<<endl;

    return 0;
}