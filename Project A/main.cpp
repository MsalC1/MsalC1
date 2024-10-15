#include <iostream>
#include <string>
#include "ArrayList.h"

int main(){
    int const size = 10;
    ArrayList<int> nums;
    for (int i = 0; i < 50; i++){
        nums.append(i);
    }
    std::cout << nums << std::endl;
    return 0;
}