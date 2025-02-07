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

    int target = vecSum(sortedBirthdays) / 2;
    int smallest = sortedBirthdays[0];
    //cout << "Target: " << target << endl;

    for(int i = sortedBirthdays.size() - 1; i >= 0; i--){
        if(vecSum(va) + sortedBirthdays[i] <= target){
            va.push_back(sortedBirthdays[i]);
            sortedBirthdays[i] = 0;
        }
    }

    for(int i = 0; i < sortedBirthdays.size(); i++){
        if(sortedBirthdays[i] != 0){
            vb.push_back(sortedBirthdays[i]);
        }
    }


    int diff = abs(vecSum(va) - vecSum(vb));

    //cout << "Difference: " << diff << endl;
	Assignment assignment1 = Assignment(diff, va, vb);

    va = {};
    vb = {};

    for(int i = sortedBirthdays.size() - 1; i >= 0; i--){
        if(vecSum(va) < vecSum(vb)){
            va.push_back(sortedBirthdays[i]);
        }
        else{
            vb.push_back(sortedBirthdays[i]);
        }
    }

    diff = abs(vecSum(va) - vecSum(vb));
    Assignment assignment2 = Assignment(diff,va,vb);

    if(assignment1.diff < assignment2.diff){
        return assignment1;
    }
    return assignment2;

    
}

/* your helper function here if you have any */




int main(){

    vector<int> myBirthdays = {3, 27, 4, 5, 20};
    Assignment myAss = balancedGroups(myBirthdays);
    myAss.printAssignment();

    myBirthdays = {12, 2, 7, 30, 22, 20, 18, 16, 25, 28};
    myAss = balancedGroups(myBirthdays);
    myAss.printAssignment();
}



