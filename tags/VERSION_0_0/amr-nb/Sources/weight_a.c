/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : weight_a.c
*      Purpose          : Spectral expansion of LP coefficients.  (order==10)
*      Description      : a_exp[i] = a[i] * fac[i-1]    ,i=1,10
*
********************************************************************************
*/
/*
********************************************************************************
*                         MODULE INCLUDE FILE AND VERSION ID
********************************************************************************
*/
#include "weight_a.h"
const char weight_a_id[] = "@(#)$Id $" weight_a_h;

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include "typedef.h"
#include "basic_op.h"
#include "count.h"
#include "cnst.h"

/*
********************************************************************************
*                         LOCAL VARIABLES AND TABLES
********************************************************************************
*/
/*
*--------------------------------------*
* Constants (defined in cnst.h         *
*--------------------------------------*
*  M         : LPC order               *
*--------------------------------------*
*/

/*
********************************************************************************
*                         PUBLIC PROGRAM CODE
********************************************************************************
*/
void Weight_Ai (
    Word16 a[],         /* (i)     : a[M+1]  LPC coefficients   (M=10)    */
    const Word16 fac[], /* (i)     : Spectral expansion factors.          */
    Word16 a_exp[]      /* (o)     : Spectral expanded LPC coefficients   */
)
{
    Word16 i;

    a_exp[0] = a[0];                                    move16 (); 
    for (i = 1; i <= M; i++)
    {
        a_exp[i] = round (L_mult (a[i], fac[i - 1]));   move16 (); 
    }

    return;
}
