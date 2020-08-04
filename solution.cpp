// you can use includes, for example:
// #include <algorithm>
#include <set> 
#include <vector> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
set<int> convertToSet(vector<int>& v)
{
    // Declaring the set 
    // using range of vector 
    set<int> s(v.begin(), v.end());
    // Return the resultant Set 
    return s;
}
void printSet(set<int>& s)
{

    cout << "Set: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
}
int solution(vector<int>& A)
{
    // write your code in C++14 (g++ 6.2.0)
    int largestInSet = 0;
    int smallestPositiveInteger = 0;

    set<int> sortedSet = convertToSet(A);

    largestInSet = *sortedSet.rbegin();
    if (largestInSet < 0)
    {
        smallestPositiveInteger = 1;
    }
    else
    {
        bool conditionMet = false;
        int nextValue = largestInSet - 1;
            while (conditionMet != true)
            {

                if (sortedSet.count(nextValue) == 0)
                {
                    smallestPositiveInteger = nextValue;
                    if (smallestPositiveInteger == 0)
                    {
                        smallestPositiveInteger = largestInSet + 1;
                    }
                    break;
                }

                nextValue = nextValue - 1;

            }
    }
    //cout << "largest:" << largestInSet << endl; 
    //printSet(sortedSet);

    return smallestPositiveInteger;
}
