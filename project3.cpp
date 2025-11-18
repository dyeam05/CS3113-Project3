//TODO: Finish implementing safetyCheck algorithm and start resourceRequest algorithm

#include <iostream>
#include <vector>
using namespace std;

bool safetyCheck(int processNum, int resourceNum, int available[], vector<vector<int>> max, vector<vector<int>> need) {
    bool safeState = false;
    bool finishedProcesses[processNum];
    for(bool i : finishedProcesses) {
        i = false;
    }
    int work[resourceNum];
    for(int i = 0; i < resourceNum; i++) {
        work[i] = available[i];
    }

    //Checks for processes that could be allocated resources.
    //If there does not exist such a process, the safety check algorithm finishes execution and returns false
    int availableProcess = 0;
    for(int i = 0; i < processNum; i++) {
        bool availableState = true;
        if(!finishedProcesses[i]) {
            for(int j = 0; j < resourceNum; j++) {
                if(need[i][j] > work[j]) {
                    availableState = false;
                }
                
            }
        }
        else availableState = false;
        if(availableState) availableProcess++;
    }
    if(availableProcess == 0){
        safeState = false;
        return safeState;
    }

    //Iterates through all processes to allocate resources.
    //If all processes are able to be allocated resources, the system is in a safe state
    int i = 0;
    while(!safeState) {
        bool availableState = true;
        for(int j = 0; j < resourceNum; j++) {
            if(finishedProcesses[i] || need[i][j] > work[j]) {
                availableState = false;
            }
        }
        if(availableState) {
            cout << "Process Available after Completion of process P" << i << ": ";
            for(int j = 0; j < resourceNum; j++) {
                work[j] += max[i][j];
                cout << work[j] << " ";
            }
            cout << endl;
            finishedProcesses[i] = true;
        }
        else {
            cout << "Process: P" << i << " not available for resource allocation. move to next" << endl; 
        }

        int numFinished = 0;
        for(int j = 0; j < processNum; j++) {
            if(finishedProcesses[j]) numFinished++;
        }
        if(numFinished == processNum) {
            safeState = true;
            return safeState;
        }

        i++;
        if(i > processNum-1) i = 0;
    }

    return safeState;
}

bool resourceRequest() {
    cout << "development still in progress" << endl;
    return true;
}

void banker(int requestNum, int processNum, int resourceNum, int available[], vector<vector<int>> max, vector<vector<int>> alloc) {
    vector<vector<int>> need(processNum, vector<int> (resourceNum, 0));


    for(int i = 0; i < processNum; i++) {
        for(int j = 0; j < resourceNum; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    if(safetyCheck(processNum, resourceNum, available, max, need)) {
        cout << "Before granting the request of P" 
        << requestNum << ", the system is in a safe state." << endl;

        cout << "Simulating granting P" << requestNum << "'s request." << endl;
        
        if(resourceRequest()) {
            cout <<"P" << processNum << "'s request can be granted. The system will be in safe state.";
        }
        else {
            cout <<"P" << processNum <<"s request cannot be granted. The system will be in unsafe state.";
        }
    }

    else {
        cout << "The current system is in unsafe state." << endl;
    }
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

    vector<vector<int>> max(processNum, vector<int> (resourceNum, 0)); //create matrix of max instances needed by each process

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
    vector<vector<int>> alloc(processNum, vector<int> (resourceNum, 0));
    
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

    banker(requestNum, processNum, resourceNum, available, max, alloc);

    return 0;
}