#include "balancedGroups.h"
// your includes here
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int vecSum(vector<int> vec){
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}

Assignment balancedGroups(std::vector<int> const &birthdays) {

    vector<int> sortedBirthdays = birthdays;
    sort(sortedBirthdays.begin(), sortedBirthdays.end());

    vector<int> va;
    vector<int> vb;

    for(int i = sortedBirthdays.size() - 1; i >= 0; i--){
        if(vecSum(va) < vecSum(vb)){
            va.push_back(sortedBirthdays[i]);
        }
        else{
            vb.push_back(sortedBirthdays[i]);
        }
    } 

    int diff = abs(vecSum(va) - vecSum(vb));

    cout << "Difference: " << diff << endl;
	return Assignment(diff, va, vb); // Don't forget to change this
}

/* your helper function here if you have any */




int main(){

    vector<int> myBirthdays = {2,7,12,16,18,20,22,25,28,30};
    Assignment myAss = balancedGroups(myBirthdays);
    myAss.printAssignment();
}

