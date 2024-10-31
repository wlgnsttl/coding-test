#include <iostream>
#include <vector>

using namespace std;

int n,m;

int solve(vector<int> v)
{
    
    if(v.size() == m)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        
        return 0;
    }
    
    for(int i=v.back()+1; i<=n; i++)
    {
        vector<int> temp = v;
        temp.push_back(i);
        solve(temp);
    }
    
    return 0;
}

int main()
{
    cin >> n >> m;
    
    //1~n까지 자연수에서 중복없이 m개를 선택
    //수열은 오름차순이며 중복은 존재하지 않는다

    
    for(int i=1; i<=n; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        solve(temp);
    }
    
    
    
    
    return 0;
}