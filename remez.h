/**************************************************************************
 * Parks-McClellan algorithm for FIR filter design (C version)
 *-------------------------------------------------
 *  Copyright (c) 1995,1998  Jake Janovetz
 *************************************************************************/
#ifndef __REMEZ_H__
#define __REMEZ_H__

#define BANDPASS       1
#define DIFFERENTIATOR 2
#define HILBERT        3

#define NEGATIVE       0
#define POSITIVE       1

#define Pi             3.1415926535897932
#define Pi2            6.2831853071795865

#define GRIDDENSITY    16
#define MAXITERATIONS  40

/* Function prototype for remez() - the only function that should need be
 * called from external code
 * -> now fixed to match function in remez.c
 */
extern void remez(double h[], int *numtaps,
                  int *numband, const double bands[], 
                  const double des[], const double weight[],
                  int *type, int *griddensity);

/* prototype all other functions, too */

extern void CreateDenseGrid(int r, int numtaps, int numband, 
                            const double bands[],
                            const double des[], const double weight[], 
                            int gridsize,
                            double Grid[], double D[], double W[],
                            int symmetry, int griddensity);

extern void InitialGuess(int r, int Ext[], int gridsize);

extern void CalcParms(int r, int Ext[], double Grid[], double D[], double W[],
                double ad[], double x[], double y[]);

extern double ComputeA(double freq, int r, double ad[], 
                       double x[], double y[]);

extern void CalcError(int r, double ad[], double x[], double y[],
                      int gridsize, double Grid[],
                      double D[], double W[], double E[]);

extern int Search(int r, int Ext[],
                  int gridsize, double E[]);

extern void FreqSample(int N, double A[], double h[], int symm);

extern int isDone(int r, int Ext[], double E[]);

#endif /* __REMEZ_H__ */

