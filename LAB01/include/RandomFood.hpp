#ifndef RANDOM_FOOD_HPP
#define RANDOM_FOOD_HPP

#include "Ingredient.hpp"
#include <random>

class RandomFood {
private:
    static std::mt19937& rng() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }

    // 用來抽一個 enum 內的隨機 index
    template <typename T>
    static T randomOne(int enumCount) {
        std::uniform_int_distribution<> idx(0, enumCount - 1);
        return static_cast<T>(idx(rng()));
    }

    // 用來抽 1~enumCount 個 enum 內容
    template <typename T>
    static std::vector<T> randomOneToMany(int enumCount) {
        std::uniform_int_distribution<> countDist(1, enumCount);
        int count = countDist(rng());

        std::vector<T> result;
        result.reserve(count);

        std::uniform_int_distribution<> idx(0, enumCount - 1);
        for (int i = 0; i < count; i++) {
            result.push_back(static_cast<T>(idx(rng())));
        }

        return result;
    }

public:

    RandomFood();
    static Ingredient Generate();
};

#endif
