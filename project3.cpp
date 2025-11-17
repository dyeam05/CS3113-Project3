#include <iostream>
#include <vector>
using namespace std;


int main() {
    char dummy;
    int temp;
    string dummyString;
    int resourceNum;
    int processNum;
    vector<int> resources;
    vector<int> processes;
    vector<vector<int>> max;
    vector<vector<int>> allocation;


    cin >> dummy;
    cin >> resourceNum;

    cin >> dummy;
    cin >> processNum;

    //REALLY FUCKING BAD. DON'T DO THIS EVER
    for(int i = 0; i < 9; i++) {
        cin >> dummy;
    }

    for(int i = 0; i < resourceNum; i++) {
        cin >> temp;
        resources.push_back(temp);
    }

    cout << resourceNum << endl;
    cout << processNum << endl;
    cout << dummy << endl;

    for(int i : resources) {
        cout << i << " ";
    }


    return 0;
}