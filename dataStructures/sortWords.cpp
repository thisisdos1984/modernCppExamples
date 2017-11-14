#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> wordCountEngine( const string& document ) 
{
  string word;
  unordered_map<string, int> words; 
  for (auto alpha : document)
  {
    if (isalpha(alpha))
      word += alpha;
    else if (alpha == ' ')
    {
      if (words.find(word) != words.end())
        words[word] += 1;
      else
        words[word] = 1;
      word = "";
    }
    
  }
  
  vector <vector <string>> ordered (100);
  
  for (auto x : words)
  {
    ordered[x.second].push_back(x.first);
    ordered[x.second].push_back(std::to_string(x.second));
  }
 
  vector <vector <string>> result;
  
  for (auto i = ordered.size()-1 ; i > 0; i--)
  {
    if (ordered[i].empty())
      continue;
    
  	result.push_back(ordered[i]);
  }
  
  return result;
 
}

int main() {
  
  string document = "practice makes perfect. you'll only get perfect by practice. just practice !";
  auto result =  wordCountEngine(document);
  
  for (auto x : result)
    for (auto y : x)
      cout << y << ":" << endl; 
  
  return 0;
}


