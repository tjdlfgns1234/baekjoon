#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> lcs_lens(const string& src, const  string& dest);
string lcs(const string& src, const  string& dest);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string src, dest;

    cin >> src >> dest;

    string ans = lcs(src, dest);

    cout << ans.size() << "\n" << ans;

    return 0;
}
string lcs(const string& src, const  string& dest)
{
    int ssize = src.size(), dsize = dest.size();
    if (ssize == 0)
        return "";  // 빈문자 리턴
    else if (ssize == 1) {
        for (auto d : dest) {
            if (src[0] == d)
                return string(1, src[0]);
        }
        return "";  // 1개인 dest와 같지 않다면 역시 빈문자 리턴
    }
    else {
        // 문자열 나누기
        int size = ssize / 2;
        string z = src.substr(0, size);
        string w = src.substr(size, ssize - size);
        vector<int> lcsl = lcs_lens(z, dest);   // 분할정복

        string za = w; reverse(za.begin(), za.end());
        string wa = dest;  reverse(wa.begin(), wa.end());
        vector<int> lcsr = lcs_lens(za, wa);    // 분할정복

        // 중간 노드 구하기
        int k = -1;
        int Max = -1;
        for (int i = 0; i < dsize + 1; i++) 
        {
            int now = lcsl[i] + lcsr[dsize - i];
            if (Max < now)
            {
                Max = now;
                k = i;
            }
        }
        // 분할 정복
        string sw = dest.substr(0, k);
        string se = dest.substr(k, dsize - k);

        return lcs(z, sw) + lcs(w, se);
    }

}
vector<int> lcs_lens(const string& src, const  string& dest)
{
    // O(max(m,n)+1)의 공간복잡도로 계산하기
    // 여기서는 그냥 dest 길이로 고정
    vector <int> curr(dest.size() + 1, 0);
    for (auto s : src)
    {
        vector <int>prev = curr;
        for (int i = 0; i < dest.size(); i++)
        {
            auto d = dest[i];
            if (s == d)
            {
                curr[i + 1] = prev[i] + 1;
            }
            else
            {
                curr[i + 1] = max(curr[i], prev[i + 1]);
            }
        }
    }
    return curr;
}