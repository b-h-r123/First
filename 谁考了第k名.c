#include <stdio.h>
int main( void )
{
    int n, k;
    scanf( "%d%d", &n, &k );
    double    xuehao[n];
    double    cj[n];
    int    i;
    printf( "\n" );
    for ( i = 0; i < n; i++ )
    {
        scanf( "%lf", &xuehao[i] );
        printf( " " );
        scanf( "%lf", &cj[i] );
        printf( "\n" );
    }

    double    temp1, temp2;
    int    j;
    for ( j = 1; j < n; j++ )
    {
        for ( i = 0; i < n - j; i++ )
        {
            if ( cj[i] < cj[i + 1] ) 
            {
                temp1        = cj[i + 1];
                cj[i + 1]    = cj[i];
                cj[i]        = temp1;
                temp2        = xuehao[i + 1];
                xuehao[i + 1]    = xuehao[i];
                xuehao[i]    = temp2;
            }
        }
    }

    printf( "%.0f %.1f", xuehao[k - 1], cj[k - 1] );
    return(0);
}
