#include <list>
#include <set>
#include <cstdint>
#include <unordered_map>

using namespace std;

class Stock
{
private:
    struct WeightNumber
    {
        int w;
        size_t i;

        bool operator<(const WeightNumber &other) const
        {
            if (w == other.w)
            {
                return i > other.i;
            }
            return w < other.w;
        }
    };

    struct VolumeNumber
    {
        int v;
        size_t i;

        bool operator<(const VolumeNumber &other) const
        {
            if (v == other.v)
            {
                return i > other.i;
            }
            return v < other.v;
        }
    };

    struct Iterators
    {
        set<WeightNumber>::iterator byW;
        set<VolumeNumber>::iterator byV;
    };
    list<Iterators> boxes;
    set<WeightNumber> sortedByW;
    set<VolumeNumber> sortedByV;
    unordered_map<size_t, list<Iterators>::iterator> indexes;
    size_t current_index{0};

public:
    void Add(int w, int v)
    {
        boxes.push_front({sortedByW.insert({w, current_index}).first,
                          sortedByV.insert({v, current_index}).first});
        indexes.insert({current_index, boxes.begin()});
        ++current_index;
    }

    int GetByW(int min_w) {
        const auto it = sortedByW.lower_bound({min_w, current_index});
        if (it == sortedByW.end()) {
            return -1;
        }

        size_t res = it->i;
        sortedByW.erase(it);
        sortedByV.erase(indexes[res]->byV);
        boxes.erase(indexes[res]);
        indexes.erase(res);
        return res;
    }

    int GetByV(int min_v) {
        const auto it = sortedByV.lower_bound({min_v, current_index});
        if(it == sortedByV.end()) {
            return -1;
        }

        size_t res = it->i;
        sortedByV.erase(it);
        sortedByW.erase(indexes[res]->byW);
        boxes.erase(indexes[res]);
        indexes.erase(res);
        return res;
    }
};

#include <iostream>

int main() {
    Stock stock;

    // Добавляем элементы
    stock.Add(10, 100);
    stock.Add(20, 200);
    stock.Add(15, 150);
    stock.Add(25, 250);
    stock.Add(10, 50);

    // Получаем элемент по весу
    std::cout << "GetByW(15): " << stock.GetByW(15) << std::endl; // Ожидается индекс элемента с весом >= 15
    std::cout << "GetByW(10): " << stock.GetByW(10) << std::endl; // Ожидается индекс элемента с весом >= 10
    std::cout << "GetByW(30): " << stock.GetByW(30) << std::endl; // Ожидается -1 (нет подходящих элементов)

    // Получаем элемент по объему
    std::cout << "GetByV(150): " << stock.GetByV(150) << std::endl; // Ожидается индекс элемента с объемом >= 150
    std::cout << "GetByV(100): " << stock.GetByV(100) << std::endl; // Ожидается индекс элемента с объемом >= 100
    std::cout << "GetByV(300): " << stock.GetByV(300) << std::endl; // Ожидается -1 (нет подходящих элементов)

    return 0;
}

