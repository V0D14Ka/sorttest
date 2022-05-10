#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>

using namespace std::chrono;

void swap(int &x, int &y) { //функция смены двух элементов местами//
    int t = x;
    x = y;
    y = t;
}

void Bubble_Sort1(
        std::vector<int> &a) { //пузырьковая сортировка(самая медленная из всех сортировок) 1 вариант(while) немного быстрее//
    bool changed = true;
    while (changed) {
        changed = false;
        for (int j = 0; j < a.size() - 1; j++) {
            if (a[j + 1] < a[j]) {
                changed = true;
                swap(a[j + 1], a[j]);
            }
        }
    }
}// алгоритмическая сложность O(N^2)//

//Сортировка подсчетом
void couting_sort(std::vector<int> &array) {
    if (array.size() == 0) return;
    auto p = std::minmax_element(array.begin(), array.end());
    int min = *p.first;
    int dist = *p.second - min + 1;
    std::vector<int> t(dist, 0);

    for (auto i: array) t[i - min]++;

    for (int i = 0, idx = 0; i < t.size(); ++i)
        for (int j = 0; j < t[i]; ++j)
            array[idx++] = i + min;

}; // O(n)

void mix(std::vector<int> &a, int value) { // рандомно заполняем массив
    for (int i = 0; i < value; i++) {
        a.push_back(rand() % 1000);
    }
}

void printArr(const std::vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::ofstream fout("Counting_Sort.txt");
    high_resolution_clock::time_point t1, t2;
    std::vector<int> v;
    std::vector<int> out;
    std::vector<long long int> times;
    for (int i = 1; i <= 9; i++) {
        for (int n = 0; n < pow(10, i); n++) {
            v.emplace_back(rand());
        }
        t1 = high_resolution_clock::now();
        couting_sort(v);
        t2 = high_resolution_clock::now();
        long long duration = duration_cast<microseconds>(t2 - t1).count();
        times.emplace_back(duration);

        v.clear();
        std::cout << i << "...";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        std::cout << pow(10, i + 1) << " : " << times[i] << "us" << std::endl;
        fout << pow(10, i + 1) << " : " << times[i] << "us" << std::endl;
    }
    return 0;
}