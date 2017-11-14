#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &copy, int s) 
{
  vector <int> result ;
  vector <int> arr = copy;
  
  sort(arr.begin(), arr.end());

  if (arr.size() < 4)
    return result;
  
  for ( decltype(arr.size()) i = 0 ; i < (arr.size() - 5); i++)
  {
    for ( decltype (arr.size()) j = i+1; j < (arr.size() - 4); j++)
    {
      // i and j are fixed, i need to find 2 numbers in j+1 to n such that sum is 
      
      auto r = s - (arr[i] + arr[j]);
      auto start = j + 1;
      auto end = arr.size() - 1;
      while (start < end)
        if (arr[start] + arr[end] < r)
          start++;
        else if (arr[start] + arr[end] > r)
          end --;
        else
        {
          result.push_back(arr[i]);
          result.push_back(arr[j]);
          result.push_back(arr[start]);
          result.push_back(arr[end]);
          return result;
        }
    }
  }
  
  return result;
 
}

int main() {
  vector <int> arr {2, 7, 4, 0, 9, 5, 1, 3};
  vector <int> result = findArrayQuadruplet(arr, 18);
  for (auto i : result)
    cout << i << ", ";

  cout << endl;
  return 0;
}


