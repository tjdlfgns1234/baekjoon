#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> quene;
    string tmp;
    int n;
    int idx = -1;
    int tmp2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (tmp == "push")
        {
            cin >> tmp2;
            quene.push_back(tmp2);
            idx++;
        }
        else if (tmp == "pop")
        {
            if (idx != -1)
            {
                std::cout << quene[0] << "\n";
                quene.erase(quene.begin());
                idx--;
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
        else if (tmp == "size")
        {
            std::cout << idx + 1 << "\n";
        }
        else if (tmp == "empty")
        {
            if (idx != -1)
            {
                std::cout << 0 << "\n";
            }
            else
            {
                std::cout << 1 << "\n";
            }
        }
        else if (tmp == "front")
        {
            if (idx != -1)
            {
                std::cout << quene[0] << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
        else if (tmp == "back")
        {
            if (idx != -1)
            {
                std::cout << quene[idx] << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
    }
}