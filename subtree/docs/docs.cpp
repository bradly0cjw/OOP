#include <stdexcept> // 為 invalid_argument() 所用
#include <vector>    // 為 vector 所用
#include <iostream>

int interval(int x){
    if (x < 100){
        return x;
    }
    throw std::invalid_argument("Out Of Range!");
}

int main(){
    std::vector<int> a; // 宣告一個型別為 int 的 vector
    a.push_back(1); // 自 a 的尾巴放入一個元素
    a.push_back(2); // 自 a 的尾巴放入一個元素
    a.push_back(3); // 自 a 的尾巴放入一個元素

    for (int i=0;i<a.size();i++){
        std::cout << a[i] << "\n"; // 用迴圈歷遍 a 的方法
    }

    std::cout<< interval(50) << "\n";  // 輸出 50
    std::cout<< interval(105) << "\n"; // 拋出 例外

    return 0;
}