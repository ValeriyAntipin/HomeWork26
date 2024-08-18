#include <iostream>
#include <thread>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <random>
#include <future>
#include <chrono>

int getSum(std::vector<int> vec, int x, int y){
    int sum = 0;
    for(int i = x; i < y; ++i){
        sum += vec[i];
    }
    return sum;
}

int main(){

    const int size = 200;

    int lower = 100;
    int upper = 1000000;

    std::vector<int> random_num(size); 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(lower, upper);

    for(int& number : random_num){
        number = distrib(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();

    int result = 0;
    //int altresult = getSum(random_num, 0, 200);
    
   
    std::future<int> future1 = std::async(getSum, random_num, 0, 50);
    result += future1.get();
    std::future<int> future2 = std::async(getSum, random_num, 51, 100);
    result += future2.get();
    std::future<int> future3 = std::async(getSum, random_num, 101, 150);
    result += future3.get();
    std::future<int> future4 = std::async(getSum, random_num, 151, 200);
    result += future4.get();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    //std::cout << altresult << std::endl;
    std::cout << result << std::endl;
    std::cout << "Time: " << duration.count() << std::endl;
    return 0;
}