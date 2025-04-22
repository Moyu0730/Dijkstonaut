#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;

    int resultIndex = -1;
    int minDays = 1e9;
    int maxPeople = -1;

    for (int i = 0; i < K; ++i) {
        int Ni, Mi;
        cin >> Ni >> Mi;

        // 每個國家的完成時間就是 Mi
        // 因為第 Mi 天，Mi 位三角形影子的人會同時喊出答案

        if (Mi < minDays) {
            minDays = Mi;
            resultIndex = i;
            maxPeople = Ni;
        } else if (Mi == minDays) {
            // 比較人數
            if (Ni > maxPeople) {
                resultIndex = i;
                maxPeople = Ni;
            } else if (Ni == maxPeople) {
                // 比較 index
                resultIndex = min(resultIndex, i);
            }
        }
    }

    cout << resultIndex << endl;
    return 0;
}