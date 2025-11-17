#include <iostream>
#include <vector>
using namespace std;

void banker() {
    
}

bool safetyCheck() {

}

bool resourceRequest() {

}



int main() {
    char dummy; //dummy value for unnecessary chars
    int resourceNum; //number of total resources
    int processNum; // number of total proceses
    int requestNum; // index of process requesting additional resources


    cin >> dummy;   //read dummy value R
    cin >> resourceNum; //read # of resources
    int available[resourceNum]; // create array of available instances of resources

    cin >> dummy;   // read dummy value P
    cin >> processNum;  // read # of proceses

    //Skip unnecessary char values for "available"
    //REALLY FUCKING BAD. FIX HARDCODED NUMBERS LATER
    for(int i = 0; i < 9; i++) {
        cin >> dummy;
    }

    //read available instances for each resource
    for(int i = 0; i < resourceNum; i++) {
        cin >> available[i];
    }

    //skip unnecessary char values for "max"
    //STILL PRETTY BAD BUT ITS WHATEVER I GUESS    
    for(int i = 0; i < 3; i++) {
        cin >> dummy;
    }

    int max[processNum][resourceNum]; //create matrix of max instances needed by each process

    //read max # of instances for each process
    for(int i = 0; i < processNum; i++) {
        for(int j = 0; j < resourceNum; j++) {
            cin >> max[i][j];
        }
    }

    //skip unnecessary char values for "allocation"
    //OKAY LAST TIME I PROMISE
    for(int i = 0; i < 10; i++) {
        cin >> dummy;
    }

    //create matrix of resource instances allocated to processes at program start
    int alloc[processNum][resourceNum];

    //read # of allocated instances for each process
    for(int i = 0; i < processNum; i++) {
        for(int j = 0; j < resourceNum; j++) {
            cin >> alloc[i][j];
        }
    }

    cin >> dummy; //skip unnecessary value P

    cin >> requestNum; //read index of process requesting additional resources

    int request[resourceNum]; //create array for resource request

    //read requested # of instances of resources
    for(int i = 0; i < resourceNum; i++) { 
        cin >> request[i];
    }

    return 0;
}