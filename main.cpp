#include <iostream>

const double GOLDEN_CUT = 0.381966011;

double Function( double iX )
{
    return iX * iX * iX - iX;
}

double Dichotomy( double iA, double iB, double iEps )
{
    double width, delta, x1, x2;

    width = iB - iA;

    delta = iEps / 10;

    while( width > iEps )
    {
        x1 = ( iA + iB - delta ) / 2;
        x2 = ( iA + iB + delta ) / 2;

        if( Function( x1 ) > Function( x2 ) )
            iA = x1;
        else
            iB = x2;

        width = iB - iA;
    }

    return ( x1 + x2 ) / 2;
}

double GoldenRatio( double iA, double iB, double iEps )
{
    double width, x1, x2, fX1, fX2;

    width = iB - iA;

    x1 = iA + GOLDEN_CUT * width;
    x2 = iB - GOLDEN_CUT * width;

    fX1 = Function( x1 );
    fX2 = Function( x2 );

    while( width > iEps )
    {
        if( fX1 > fX2 )
        {
            iA = x1;

            width = iB - iA;

            x1 = x2;
            x2 = iB - GOLDEN_CUT * width;

            fX1 = fX2;
            fX2 = Function( x2 );
        }
        else
        {
            iB = x2;

            width = iB - iA;

            x2 = x1;
            x1 = iA + GOLDEN_CUT * width;

            fX2 = fX1;
            fX1 = Function( x1 );
        }
    }

    return ( x1 + x2 ) / 2;
}

double Fibonacci( double iA, double iB, double iEps )
{
    double width, x1, x2;
    double F1, F2, F3;
    int n = 1;

    F1 = 1;
    F2 = 1;
    F3 = 2;
    width = iB - iA;

    while( width / iEps > F3 )
    {
        F1 = F2;
        F2 = F3;
        F3 = F1 + F2;
        ++n;
    }

    x1 = iA + width * F1 / F3;
    x2 = iA + width * F2 / F3;

    double fx1, fx2;
    fx1 = Function( x1 );
    fx2 = Function( x2 );

    while( --n )
    {
        F3 = F2;
        F2 = F1;
        F1 = F3 - F2;

        if( fx1 > fx2 )
        {
            iA = x1;

            width = iB - iA;

            x1 = x2;
            x2 = iA + F2 / F3 * width;

            fx1 = fx2;
            fx2 = Function( x2 );
        }
        else
        {
            iB = x2;

            width = iB - iA;

            x2 = x1;
            x1 = iA + F1 / F3 * width;

            fx2 = fx1;
            fx1 = Function( x1 );
        }
    }

    return ( x1 + x2 ) / 2;
}

void Search( double iEps, double iStart, double & oA, double & oB )
{
    double step, currentPosition;


    if( Function( iStart ) > Function( iStart + iEps ) ){
        iStart += iEps;
        step = iEps;
    }
    else{
        iStart -= iEps;
        step = -iEps;
    }

    currentPosition = iStart;

    double fx1, fx2;
    fx1 = Function( iStart );
    fx2 = Function( iStart + step );

    while( fx1 > fx2 )
    {
        step *= 2;
        currentPosition += step;

        fx1 = fx2;
        fx2 = Function( currentPosition );
    }

    oA = currentPosition - 2 * step;
    oB = currentPosition;

}

int main()
{
    double a, b, eps;

    a = 0;
    b = 1;
    eps = 1E-10;

    std::cout << Dichotomy( a, b, eps ) << std::endl;
    std::cout << GoldenRatio( a, b, eps ) << std::endl;
    std::cout << Fibonacci( a, b, eps ) << std::endl;



    double A, B;
    Search( 1e-2, 0, A, B );
    std::cout << A << std::endl << B;
    return 0;
}
