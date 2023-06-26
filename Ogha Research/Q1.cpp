#include<bits/stdc++.h>
using namespace std;
 
pair<int , int> findnearestpair(vector<int>& numbers, int target) {
    int minDiff = INT_MAX;
    pair<int, int> nearestpair;

    nearestpair.first = numbers[0];
    nearestpair.second = numbers[1];


    for(size_t i = 0; i < numbers.size() - 1; i++) {
        for(size_t j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            int diff = abs(sum - target);

            if(diff < minDiff || (diff == minDiff && j - i < nearestpair.second - nearestpair.first))  {
                minDiff =diff;
                nearestpair= make_pair(numbers[i], numbers[j]);
            }
        }
    }
    return nearestpair;
}

int main()
{
    vector<int> numbers = {1, 5, 3, 6, 4, 2};
    int target = 7;

    pair<int, int> nearestpair = findnearestpair(numbers, target);

    cout<<"Nearest Pair: (" << nearestpair.first <<"," << nearestpair.second << ")" << endl;
 
return 0;
}
