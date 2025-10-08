#include <algorithm>
#include <iostream>
#include <vector>

// 比較函式：整數由大到小排序
bool cmpInt(int a, int b) {
    return a > b;
}

// 定義學生結構
struct student {
    int number; // 學號
    int score;  // 成績
};

// 學號升冪排序
bool cmpStucdentnumberUp(student a, student b) {
    return a.number < b.number;
}

// 學號降冪排序
bool cmpStucdentnumberDown(student a, student b) {
    return a.number > b.number;
}

// 成績升冪排序
bool cmpStucdentScoreUp(student a, student b) {
    return a.score < b.score;
}

// 成績降冪排序
bool cmpStucdentScoreDown(student a, student b) {
    return a.score > b.score;
}

int main() {
    // ----------- int 排序範例 -----------

    // 建立一個整數 vector
    std::vector<int> nums = {10, 14, 6, 7, 8, 15, 1, 9, 12, 11, 3, 4, 5, 13, 2};

    // 升冪排序 (小到大) - 預設比較器
    std::sort(nums.begin(), nums.end());
    for (auto num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // 降冪排序 (大到小) - 使用自定義比較函式 cmpInt
    std::sort(nums.begin(), nums.end(), cmpInt);
    for (auto num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // ----------- struct student 排序範例 -----------

    // 建立一個學生 vector
    std::vector<student> students;
    students.push_back(student{2, 60});
    students.push_back(student{1, 100});
    students.push_back(student{4, 70});
    students.push_back(student{5, 80});
    students.push_back(student{3, 90});

    // 用 number (學號) 升冪排序
    std::sort(students.begin(), students.end(), cmpStucdentnumberUp);
    for (auto student : students) {
        std::cout << '(' << student.number << ',' << student.score << ") ";
    }
    std::cout << std::endl;

    // 用 number (學號) 降冪排序
    std::sort(students.begin(), students.end(), cmpStucdentnumberDown);
    for (auto student : students) {
        std::cout << '(' << student.number << ',' << student.score << ") ";
    }
    std::cout << std::endl;

    // 用 score (成績) 升冪排序
    std::sort(students.begin(), students.end(), cmpStucdentScoreUp);
    for (auto student : students) {
        std::cout << '(' << student.number << ',' << student.score << ") ";
    }
    std::cout << std::endl;

    // 用 score (成績) 降冪排序
    std::sort(students.begin(), students.end(), cmpStucdentScoreDown);
    for (auto student : students) {
        std::cout << '(' << student.number << ',' << student.score << ") ";
    }
    std::cout << std::endl;

    return 0;
}
