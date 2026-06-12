#include <stdio.h>

#define SIZE 10

void bubble_sort(int array[], int size);
void bubble_sort_optimized(int array[], int size);
void bubble_sort_descending(int array[], int size);
void swap(int* number_1, int* number_2);
void print_array(int array[], int size);


int main(void) {
  // int array[SIZE] = {7, 4, 1, 10, 9, 6, 8, 2, 5, 3};
  int array[SIZE] = {'H', 'D', 'E', 'F', 'A', 'B', 'G', 'J', 'I', 'C'};


  // print before sort
  printf("Before: ");
  print_array(array, SIZE);

  // bubble_sort(array, SIZE);
  bubble_sort_optimized(array, SIZE);
  // bubble_sort_descending(array, SIZE);

  // print after sort
  printf("After:  ");
  print_array(array, SIZE);

  return 0;
}

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) {
    // printf("%d ", array[i]);
    printf("%c ", array[i]);
  }
  printf("\n");
}

















/* What is Bubble sort?
 *
 * Bubble sort is one of many sorting algorithms
 *
 * Sorting Algorithms are algorithms that arrange a list of elements into a specific order
 *
 * Lets say that we have an array of integers: 1, 5, 2, 4, 3
 *
 * And we want to sort this array in ascending order: 1, 2, 3, 4, 5
 *
 * Bubble sort can accomplish this task by doing the following:
 *
 * Lets say that first we have a loop that repeats for each element in the array
 * then inside that loop we have a for loop that goes through each element to compare and sort
 *
 *
 * Very basic bubble sort:
 *
 * Repeat n - 1 times
 *   For i from 0 to n - 2
 *     If array[i] > array[i+1]
 *       Swap positions of array[i] and array[i+1]
 *
 * where: n is the size of the array.
 * */

void bubble_sort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

/* First iteration of outside loop
 *
 * index = 0
 *
 * [1], 5, 2, 4, 3
 * 
 * if 1 > 5: swap their positions
 *
 *
 * index = 1
 *
 * 1, [5], 2, 4, 3
 *
 * if 5 > 2: swap their positions
 *
 *
 * index = 2
 *
 * 1, 2, [5], 4, 3
 *
 * if 5 > 4: swap
 *
 * 
 * index = 3
 *
 * 1, 2, 4, [5], 3
 *
 * if 5 > 3: swap
 *
 *
 * 1, 2, 4, 3, [5]
 *
 *
 * First iteration of outside loop done!
 *
 *
 * Since we have 5 integers it will take 4 iterations to be confident that we fully sorted the array
 * Though there are some extra things that we can do to optimize even further
 *
 *
 * for i where i loops n - 1 times
 *   For j from 0 to n - 1 - i
 *     If numbers[j] > numbers[j+1]
 *       Swap numbers[j] and numbers[j+1]
 *   If none are swapped
 *     Stop
 * */

void bubble_sort_optimized(int array[], int size) {
  int swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = 0;
    for (int j = 0; j < size - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
        swapped = 1;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void bubble_sort_2(int array[], int size) {
  int swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = 0;
    for (int j = 0; j < size - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void swap(int* number_1, int* number_2) {
  int tmp = *number_1;
  *number_1 = *number_2;
  *number_2 = tmp;
}

void bubble_sort_descending(int array[], int size) {
  int swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = 0;
    for (int j = 0; j < size - 1 - i; j++) {
      if (array[j] < array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        swapped = 1;
      }
    }

    if (!swapped) {
      break;
    }
  }
}
