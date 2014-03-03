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

double goldenRatio( double iA, double iB, double iEps )
{
    double width, x1, x2, fX1, fX2;

    width = iB - iA;

    x1 = iA + 0.381966011 * width;
    x2 = iB - 0.381966011 * width;

    fX1 = function( x1 );
    fX2 = function( x2 );

    while( width > iEps )
    {
        if( fX1 > fX2 )
        {
            iA = x1;
            x1 = x2;
            width = iB - iA;
            x2 = iB - 0.381966011 * width;
            fX1 = fX2;
            fX2 = function( x2 );
        }
        else
        {
            iB = x2;
            x2 = x1;
            width = iB - iA;
            x1 = iA + 0.381966011 * width;
            fX2 = fX1;
            fX1 = function( x1 );
        }
    }

    return x1;
}

int main()
{
    double a, b, eps;

    a = -10;
    b = 20;
    eps = 1E-10;

    std::cout << dichotomy( a, b, eps ) << std::endl;
    std::cout << goldenRatio( a, b, eps ) << std::endl;

    return 0;
}
