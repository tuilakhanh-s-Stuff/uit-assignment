/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    double bankinh;
    std::cin >> bankinh;

    double dientich, thetich;
    dientich = 4 * M_PI * bankinh * bankinh;
    thetich = (bankinh * dientich)/3;
    std::cout << std::setprecision(15) << dientich << '\n' << thetich;

    return 0;
}
