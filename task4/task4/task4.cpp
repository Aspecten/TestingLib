#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Укажите путь к файлу 
    string filePath = "C:\\Users\\fanto\\Desktop\\testing\\Testing\\task4\\task4\\input.txt";

    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Fall: cant open file" << endl;
        return 1;
    }

    vector<int> nums;
    int num;

    while (inputFile >> num) {
        nums.push_back(num);
    }

    inputFile.close();

    if (nums.empty()) {
        cerr << "Fall: masive pust" << endl;
        return 1;
    }

    sort(nums.begin(), nums.end());

    int median = nums[nums.size() / 2];

    int moves = 0;
    for (int n : nums) {
        moves += abs(n - median);
    }

    cout << "Min kol-vo xodov: " << moves << endl;

    return 0;
}
