#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALLOWED 8

/*
 * str is either NULL or contains valid chars.
 * calc_strlen is a modified version of strlen.
 */
unsigned int calc_strlen(char *str)
{
	int count = 0;
	if(str != NULL) {
		while ((str[count] != '\0') && (count < MAX_ALLOWED))
			count++;
		if(count > MAX_ALLOWED)
			count = -1;
	}
	else {
		count = -1;
	}
	return count;
}

/*
 * This function swaps q and r
 */
int swap_qr(int p, int q, int r)
{
	int *p1 = &p;
	printf("Before: q: %d, r: %d", q, r);
	int temp = q;
	*(int *)(p1-1) = r;
	*(int *)(p1-2) = temp;
	printf("After: q: %d, r: %d", q, r);
	return 0;
}

/*
 * When a string input is accepted from the user, we are forced to conservatively allocate more space than needed. 
 * Part 1 of this program reallocates the appropriate space for the input string at runtime.
 */
int main()
{
	/* Part 1 */
	char str[MAX_ALLOWED + 1];
	char *compact_str;

	unsigned int count = 0;
	memset(str, '\0', sizeof(str));

	printf("Enter string: ");
	scanf("%8s", str);

	count = calc_strlen(str);
	compact_str = (char *) malloc (count + 1);
	strncpy(compact_str, str, count);
	printf("Length of new string %s= %u\n", str,calc_strlen(compact_str));

	/* Part 2 */
	swap_qr(4, 5, 6);
	return 0;
}
