/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * This program reads in the dimensions of a tray and a slab, and computes the maximum possible number of slabs that could be packed onto the tray.
 * Samuel Paul Christopher
 * C08
 */

#include <stdio.h>

int computeMaxSlabs();

int main(void) {
	int max_slabs, trayX, trayY, slabX, slabY;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayX, &trayY);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabX, &slabY);
	
	max_slabs = computeMaxSlabs(trayX, trayY, slabX, slabY);
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

// computeMaxSlabs() takes in the dimensions of the tray and slab, then returns the max_slabs
int computeMaxSlabs(int trayX, int trayY, int slabX, int slabY) {
	// consider case where slabX is vertical
	int numberOfColumnsOne, numberOfRowsOne, maxSlabsOne;
	numberOfColumnsOne = trayX / slabY;
	numberOfRowsOne = trayY / slabX;
	maxSlabsOne = numberOfColumnsOne * numberOfRowsOne;

	// consider case where slabY is vertical
	int numberOfColumnsTwo, numberOfRowsTwo, maxSlabsTwo;
	numberOfColumnsTwo = trayX / slabX;
	numberOfRowsTwo = trayY / slabY;
	maxSlabsTwo = numberOfColumnsTwo * numberOfRowsTwo;

	// see in which case, the maximum number of slabs that can be packed on the tray is greater
	if (maxSlabsOne > maxSlabsTwo) {
		return maxSlabsOne; 
	}

	return maxSlabsTwo;
}
	
