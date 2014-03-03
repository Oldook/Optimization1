#include <iostream>

double function( double iX )
{
    return iX * iX + 2 * iX - 4;
}

double dichotomy( double iA, double iB, double iEps )
{
    double width, delta, x1, x2;

    width = iB - iA;

    delta = iEps / 10;

    while( width > iEps )
    {
        x1 = ( iA + iB - delta ) / 2;
        x2 = ( iA + iB + delta ) / 2;

        if( function( x1 ) > function( x2 ) )
            iA = x1;
        else
            iB = x2;

        width = iB - iA;
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
