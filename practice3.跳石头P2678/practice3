#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

long long L, N, M, qidianjuli[500010];
static bool check(long long x)
{
    int yichushu = 0;
    int qidian = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        if (x > qidianjuli[i] - qidian) yichushu++;
        else
        {
            qidian = qidianjuli[i];
        }
    }
    return yichushu <= M;
}

int main()
{
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> qidianjuli[i];
    }
    qidianjuli[0] = 0;
    qidianjuli[N + 1] = L;
    long long mid;
    long long low = 0, high = L;
    long long ans = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (check(mid))
        {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
