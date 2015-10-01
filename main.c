/*
 * main.c
 *
 * Copyright 2015 El David Cordero Chavarría <dacoch215@estudiantec.cr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

/*
 * this program can be compiled with gcc like this:
 * gcc main.c -o pointers
 * it can be run like this:
 * ./pointers
 * it can be checked for memory leaks with valgrind like this:
 * valgrind --leak-check=full ./pointers
 */
#include <stdio.h> // for printf, scanf, puts, NULL
#include <pthread.h> // for pthread types
#include <unistd.h> // for sleep()
#include <sys/types.h> // for pthread types
#include <stdbool.h> // for bool type
#include <regex.h> // for regular expressions POSIX
#include <stdlib.h> // for malloc() & free()
#include <string.h> // for strlen(), memcpy() & memset()
#include <stdlib.h> // for srand, rand
#include <time.h> // for time()

void arraySyntax(void);
void pointerSyntax(void);
void msg(void);

int main()
{
	msg();
	// both versions execute the same thing
	// results may differ because of the use of random numbers in the execution
	arraySyntax();
	pointerSyntax();
	return 0;
}

void msg(void)
{
	printf("this program is meant to be a reference on pointer usage,\n");
	printf("two versions of the same execution code are written\n");
	printf("and both work in exactly the same way\n");
	printf("one that uses the array-name[element-index] syntax\n");
	printf("and another that uses the * dereference operator\n");
}

void pointerSyntax(void)
{
	int arraysizes = 2;
	printf("\nthis is the function with the pointer syntax\n\n");

	// first a test with a simple array

	printf("The size of the arrays is: %d\n", arraysizes);

	printf("Test 1 - a single array\n");

	int * test1 = (int*)malloc(arraysizes * sizeof(int));
	memset(test1,0,arraysizes);

	int visitor = 0;
	srand (time(NULL));

	while (visitor < arraysizes)
	{
		printf("element %d in the array: %d\n", visitor, *(test1 + visitor));
		visitor++;
	}

	visitor = 0;
	while (visitor < arraysizes)
	{
		*(test1 + visitor) = rand() % 10000;
		visitor++;
	}

	visitor = 0;
	while (visitor < arraysizes)
	{
		printf("element %d in the array: %d\n", visitor, *(test1 + visitor));
		visitor++;
	}
	/* remember to free memory after it isn't needed
	 * only done once because there is only one allocation
	 */
	free(test1);

	printf("End of Test 1 - a single array\n");

	// now a test with an array of arrays

	printf("Test 2 - an array of arrays\n");

	int ** test2 = (int**)malloc(arraysizes * sizeof(int*));
	memset(test2,0,arraysizes);

	visitor = 0;
	while (visitor < arraysizes)
	{
		*(test2 + visitor) = (int*)malloc(arraysizes * sizeof(int));
		memset(*(test2 + visitor),0,arraysizes);
		visitor++;
	}

	visitor = 0;
	int tmp = 0;

	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			printf("element %d in the array %d is %d\n", tmp, visitor,
			    *(*(test2 + visitor) + tmp));
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	visitor = 0;
	tmp = 0;
	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			*(*(test2 + visitor) + tmp) = rand() % 10000;
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	visitor = 0;
	tmp = 0;
	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			printf("element %d in the array %d is %d\n", tmp, visitor,
			    *(*(test2 + visitor) + tmp));
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	/* remember to free memory after it isn't needed
	 * done once per allocation
	 */
	visitor = 0;
	while (visitor < arraysizes)
	{
		free(*(test2 + visitor));
		visitor++;
	}
	free(test2);

	printf("End of Test 2 - an array of arrays\n");
}

void arraySyntax(void)
{
	int arraysizes = 2;
	printf("\nthis is the function with the array syntax\n\n");

	// first a test with a simple array

	printf("The size of the arrays is: %d\n", arraysizes);

	printf("Test 1 - a single array\n");

	int * test1 = (int*)malloc(arraysizes * sizeof(int));
	memset(test1,0,arraysizes);

	int visitor = 0;
	srand (time(NULL));

	while (visitor < arraysizes)
	{
		printf("element %d in the array: %d\n", visitor, test1[visitor]);
		visitor++;
	}

	visitor = 0;
	while (visitor < arraysizes)
	{
		test1[visitor] = rand() % 10000;
		visitor++;
	}

	visitor = 0;
	while (visitor < arraysizes)
	{
		printf("element %d in the array: %d\n", visitor, test1[visitor]);
		visitor++;
	}
	/* remember to free memory after it isn't needed
	 * only done once because there is only one allocation
	 */
	free(test1);

	printf("End of Test 1 - a single array\n");

	// now a test with an array of arrays

	printf("Test 2 - an array of arrays\n");

	int ** test2 = (int**)malloc(arraysizes * sizeof(int*));
	memset(test2,0,arraysizes);

	visitor = 0;
	while (visitor < arraysizes)
	{
		test2[visitor] = (int*)malloc(arraysizes * sizeof(int));
		memset(test2[visitor],0,arraysizes);
		visitor++;
	}

	visitor = 0;
	int tmp = 0;

	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			printf("element %d in the array %d is %d\n", tmp, visitor,
			    test2[visitor][tmp]);
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	visitor = 0;
	tmp = 0;
	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			test2[visitor][tmp] = rand() % 10000;
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	visitor = 0;
	tmp = 0;
	while (visitor < arraysizes)
	{
		while (tmp < arraysizes)
		{
			printf("element %d in the array %d is %d\n", tmp, visitor,
			    test2[visitor][tmp]);
			tmp++;
		}
		tmp = 0;
		visitor++;
	}

	/* remember to free memory after it isn't needed
	 * done once per allocation
	 */
	visitor = 0;
	while (visitor < arraysizes)
	{
		free(test2[visitor]);
		visitor++;
	}
	free(test2);

	printf("End of Test 2 - an array of arrays\n");
}
