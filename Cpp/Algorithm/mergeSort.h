#ifndef MERGESORT_H
#define MERGESORT_H
#include "main.h"
/*
 * Divide: Breaking up the array into smaller and smaller pieces
 * until one such sub-array only consists off one element
 *
 * Conquer: Mergers the small pieces of the array back together
 * by putting the lowest values first, resulting in a sorted array.
 * */
void incLeft(int& left);
void decRight(int& right);
int getMid(int left, int right);
void divide(int* mang, int size);
#endif

