#include <iostream>

double function( double iX )
{
    return iX * iX + 2 * iX - 4;
}

double dichotomy( double a, double b, double eps )
{
    double width, delta, x1, x2;

    width = b - a;

    delta = eps / 10;

    while( width > eps )
    {
        x1 = ( a + b - delta ) / 2;
        x2 = ( a + b + delta ) / 2;

        if( function( x1 ) > function( x2 ) )
            a = x1;
        else
            b = x2;

        width = b - a;
    }

    return x1;
}

int main()
{
    double a, b, eps;

    a = -10;
    b = 20;
    eps = 1E-10;

    std::cout << dichotomy( a, b, eps );

    return 0;
}
