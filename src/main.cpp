#include <iostream>
#include <thread>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <random>
#include <future>

int getSum(std::vector<int> vec, int x, int y){
    int sum = 0;
    for(int i = x; i < y; ++i){
        sum += vec[i];
    }
    return sum;
}

int main(){

    const int size = 20;

    int lower = 1;
    int upper = 100;

    std::vector<int> random_num(size); 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(lower, upper);

    for(int& number : random_num){
        number = distrib(gen);
    }
    int result = 0;
    std::future<int> future1 = std::async(getSum, random_num, 0, 5);
    result += future1.get();
    std::future<int> future2 = std::async(getSum, random_num, 6, 10);
    result += future2.get();
    std::future<int> future3 = std::async(getSum, random_num, 11, 15);
    result += future3.get();
    std::future<int> future4 = std::async(getSum, random_num, 16, 20);
    result += future4.get();
    std::cout << result << std::endl;
    return 0;
}