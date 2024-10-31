#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
vector <int> arr;
vector <int> key;

int solve(vector<int> v)
{
    
    if(v.size() == m)
    {
        //이론상 해싱 처리
        int temp_key=0;
        
        for(int i=0; i<v.size(); i++)
        {
            int temp = arr[v[i]];
            temp = temp*pow(31,i);
            temp_key += temp;
        }
        
        temp_key = temp_key%1234567891;
        
        
        if(find(key.begin(), key.end(), temp_key) == key.end())
        {
            key.push_back(temp_key);
            for(int i=0; i<v.size(); i++)
            {
                cout << arr[v[i]] << " ";
            }
             cout << "\n";
        }
            
            
            
        
        return 0;
    }
    
    for(int i=0; i<n; i++)
    {
        

        if(find(v.begin(), v.end(), i) == v.end())
        {
            vector<int> temp = v;
            temp.push_back(i);
            solve(temp);
        }
        
    }

    
    
    
    
    
    return 0;
}

int main()
{
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        solve(temp);
    }
    
    
    
    
    
    return 0;
}