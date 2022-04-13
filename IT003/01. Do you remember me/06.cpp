#include <iostream>

using namespace std;

int hitCal(int x, int y, int n, int m)
{
    int hit = 0, heal;
    do {
        heal = 0;
        do {
            hit++;
            heal = heal + x;
            // cout << hit << '|';
        } while (heal < m);
        x = x + y;
        n--;
        // cout << n << '|';
    } while(n != 0);
    return hit;
}

int main()
{
    int x, y, n, m;
    cin >> x >> y >> n >> m;
    cout << hitCal(x, y, n, m);
    return 0;
}