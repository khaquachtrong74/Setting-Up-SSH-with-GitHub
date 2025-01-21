/*
 * Filename: prat.cpp
 * Author: Quach Trong Kha
 * Date: October 8, 2024
 * Description: Use effective I/O console
 */

#ifndef PRAT_H
#define PRAT_H
#include "prat_figs.h"
#include "prat_figs.cpp"
#include "prat.cpp"
istream & operator >> (istream &inDev, Obj &Cr);
ostream & operator << (ostream *outDev, Obj &Cr);
#endif
