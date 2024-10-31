#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> arr;

int solve(vector<int> v)
{
    
    if(v.size() == m)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << arr[v[i]] << " ";
        }
        cout << "\n";
        
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