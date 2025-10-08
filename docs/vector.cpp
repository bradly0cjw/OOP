#include <iostream>
#include <vector>

struct student {
    int number; // 學號
    int score;  // 成績
};

int main(){
    std::vector<student> students;
    students.push_back(student{1, 100});
    students.push_back(student{2, 90});
    students.push_back(student{3, 80});
    students.push_back(student{4, 70});
    students.push_back(student{5, 60});

    // ----------- 掃過 vector 中每一個值 範例 -----------

    // 會改變原本的值
    std::cout << "method 1:" << std::endl;
    std::vector<student> s1 = students;     //從 students 複製一個一模一樣的vector
    for (int i = 0; i < s1.size(); i++) {
        s1[i].number = 1;
        std::cout << '(' << s1[i].number << ',' << s1[i].score << ") ";
    }
    std::cout << std::endl;
    std::cout << "original vector:" << std::endl;
    for (auto s: s1) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    // 不會改變原本的值
    std::cout << "method 2:" << std::endl;
    std::vector<student> s2 = students;
    for (auto s: s2) {              // auto也可以寫成 student
        s.number = 2;
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl;
    std::cout << "original vector:" << std::endl;
    for (auto s: s2) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    // 會改變原本的值
    std::cout << "method 3:" << std::endl;
    std::vector<student> s3 = students;
    for (auto& s: s3) {             // auto也可以寫成 student
        s.number = 3;
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl;
    std::cout << "original vector:" << std::endl;
    for (auto& s: s3) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;
    // 結論：
    // 只要在資料型態後面加上 & (reference) 就可以改變原本的資料
    // auto 可以自動偵測資料型態

    // ----------- 取得 vector 最前面的值 範例 -----------
    std::cout << "number: " << students.front().number << std::endl;
    std::cout << "score: " << students.front().score << std::endl;

    // ----------- 取得 vector 最後面的值 範例 -----------
    std::cout << "number: " << students.back().number << std::endl;
    std::cout << "score: " << students.back().score << std::endl;

    // ----------- 取得 vector 最前面的指標 範例 -----------
    std::cout << "number: " << (*students.begin()).number << std::endl;
    std::cout << "score: " << (*students.begin()).score << std::endl;

    // ----------- 取得 vector 最後面的指標 範例 -----------
    std::cout << "number: " << (*(students.end()-1)).number << std::endl;
    std::cout << "score: " << (*(students.end()-1)).score << std::endl;

    std::cout << std::endl;

    // ----------- 刪除 vector 最前面的值 範例 -----------
    std::vector<student> s4 = students;
    std::cout << "original vector:" << std::endl;
    for (auto& s: s4) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl;

    s4.erase(s4.begin());

    std::cout << "after erase vector:" << std::endl;
    for (auto& s: s4) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    // ----------- 刪除 vector 第i個的值 範例 -----------
    std::vector<student> s5 = students;
    std::cout << "original vector:" << std::endl;
    for (auto& s: s5) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    s5.erase(s5.begin() + 1);

    std::cout << "after erase vector:" << std::endl;
    for (auto& s: s5) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    // ----------- 刪除 vector 最後面的值 範例 -----------
    std::vector<student> s6 = students;
    std::cout << "original vector:" << std::endl;
    for (auto& s: s6) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    s6.erase(s6.end());

    std::cout << "after erase vector:" << std::endl;
    for (auto& s: s6) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;


    // ----------- 清空 vector 範例 -----------
    std::vector<student> s7 = students;
    std::cout << "original vector:" << std::endl;
    for (auto& s: s7) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;

    s7.clear();

    std::cout << "after clear vector:" << std::endl;
    for (auto& s: s7) {             // auto也可以寫成 student
        std::cout << '(' << s.number << ',' << s.score << ") ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}