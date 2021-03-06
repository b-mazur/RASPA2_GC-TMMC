/*************************************************************************************************************
 The MIT License

 Copyright (C) 2006-2019 David Dubbeldam, Sofia Calero, Thijs Vlugt, Donald E. Ellis, and Randall Q. Snurr.

     D.Dubbeldam@uva.nl            http://www.uva.nl/profiel/d/u/d.dubbeldam/d.dubbeldam.html
     scaldia@upo.es                http://www.upo.es/raspa/
     t.j.h.vlugt@tudelft.nl        http://homepage.tudelft.nl/v9k6y
     don-ellis@northwestern.edu    http://dvworld.northwestern.edu/
     snurr@northwestern.edu        http://zeolites.cqe.northwestern.edu/

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
**************************************************************************************************************/

#ifndef MOVIES_H
#define MOVIES_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

enum{PDB,CSSR,MOL,XYZ,VASP};
enum{VTK_UNIT_CELL,VTK_FULL_BOX};

extern REAL MovieScale;

extern int WriteVTKGrids;

extern VECTOR VTKFractionalFrameworkAtomsMin;
extern VECTOR VTKFractionalFrameworkAtomsMax;
extern VECTOR VTKFractionalFrameworkBondsMin;
extern VECTOR VTKFractionalFrameworkBondsMax;
extern VECTOR VTKFractionalAdsorbateComMin;
extern VECTOR VTKFractionalAdsorbateComMax;
extern VECTOR VTKFractionalCationComMin;
extern VECTOR VTKFractionalCationComMax;

extern int FreeEnergyAveragingTypeVTK;
extern int DensityAveragingTypeVTK;
extern int AverageDensityOverUnitCellsVTK;

extern int *Movies;
extern int *WriteMoviesEvery;

VECTOR ConvertPositionToVTKPosition(VECTOR pos);

int SamplePDBMovies(int Choice,int Subdir);

void WriteVTK(int system);

void WriteMolecule(int mol);
void WriteIonCssr(void);

void WriteSnapshotIonsCssr(void);
void WriteSnapshotIonsCssrUsingSymmetry(void);

void WriteAsymetricPositions(void);
void WriteDlpolyInputFiles(void);

void FreeEnergyProfile3D(void);

void AllocateMovieMemory(void);

void WriteRestartMovies(FILE *FilePtr);
void ReadRestartMovies(FILE *FilePtr);

void WriteSnapshotTinker(char *string);


#endif
