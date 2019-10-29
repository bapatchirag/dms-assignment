#include <stdio.h>

int num_union(int*, int*, int*, int);
int sum_over_array(int*, int);

int main()
{
	int nA, nB, nC, nD; // Number of elements in A, B, C and D, respectively
	int nAB, nBC, nCD, nDA, nBD, nAC; // Number of elements in the intesrections of AB, BC, CD, DA, BD and AC, respectively
	int nABC, nBCD, nCDA, nDAB; // Number of elements in the intesections of ABC, BCD, CDA and DAB, respectively
	int nABCD; // Number of elements in the intersection of ABCD
	
	printf("Enter number of elements of set A, set B, set C, set D: \n");
	scanf("%d %d %d %d", &nA, &nB, &nC, &nD);
	
	printf("Enter number of elements in intersections of each pair of sets: \n");
	scanf("%d %d %d %d %d %d", &nAB, &nBC, &nCD, &nDA, &nAC, &nBD);
	
	printf("Enter number of elements in intersections of each triplet of sets: \n");
	scanf("%d %d %d %d", &nABC, &nBCD, &nCDA, &nDAB);
		
	printf("Enter number of elements in intersections of all sets: \n");
	scanf("%d", &nABCD);
	
	int i0[] = {nA, nB, nC, nD};
	int i1[] = {nAB, nBC, nCD, nDA, nBD, nAC};
	int i2[] = {nABC, nBCD, nCDA, nDAB};
			
	int num_in_union = num_union(i0, i1, i2, nABCD);
	
	if(num_in_union > 0)
		printf("Number of elements in the union of sets A, B, C and D are: %d\n", num_in_union);
	else
		printf("Inputs were wrong\n");
	
	return 0;
}

/*
PARAMS:
	1. Integer array of number of elements of sets
	2. Size of above array
RETURN VALUE:
	Sum of all elements of array
DESCRIPTION:
	Function sums over all elements of array
*/
int sum_over_array(int* arr, int size)
{
	int index = 0, sum = 0;
	
	label:
		sum += arr[index++];
		
		if(index < size)
			goto label;
			
	return sum;
}

/*
PARAMS:
	1. Integer array of number of elements of lone sets
	2. Integer array of number of elements of intersections of pairs of sets
	3. Integer array of number of elements of intersections of triplets of sets
	4. Integer number which represents the number of elements in the intersection of all sets
RETURN VALUE:
	Number of elements of the union of all 4 sets (>= 0), or -1 (in case of any wrong inputs)
DESCRIPTION:
	Function uses principle of inclusion-exclusion to calculate the number of elements in the union set
*/
int num_union(int* i0, int* i1, int* i2, int i3)
{
	int nA = i0[0], nB = i0[1], nC = i0[2], nD = i0[3]; 
	int nAB = i1[0], nBC = i1[1], nCD = i1[2], nDA = i1[3], nBD = i1[4], nAC = i1[5]; 
	int nABC = i2[0], nBCD = i2[1], nCDA = i2[2], nDAB = i2[3];
	int nABCD = i3;
	
	//Checks to see whether the number of elements in every intersection of more sets is lesser than than the number of elements in the intersection of lesser number of sets
	
	if((nA > nAB && nA > nDA && nA > nAC) && (nB > nAB && nB > nBC && nB > nBD) && (nC > nAC && nC > nBC && nC > nCD) && (nD > nDA && nD > nCD && nD > nBD))
	{
		if((nAB > nABC && nAB > nDAB) && (nBC > nABC && nBC > nBCD) && (nCD > nBCD && nCD > nCDA) && (nDA > nDAB && nDA > nCDA))
		{
			if(nABCD <= nABC && nABCD <= nBCD && nABCD <= nCDA && nABCD <= nDAB)
				return sum_over_array(i0, 4) - sum_over_array(i1, 6) + sum_over_array(i2, 4) - i3;
		}
	}
	else
		return -1;
}
