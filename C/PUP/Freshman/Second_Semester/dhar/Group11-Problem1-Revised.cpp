#include <stdio.h>
#include <ctype.h>

#define SIZE 5 //Since it is a prerequisite that 5 is the size of array

// Function to check for duplicates in both arrays and to check if each array have duplicate values
int duplicate_checker(int arr1[], int size1, int arr2[], int size2, int num) {
    for (int i = 0; i < size1; i++) {
        if (arr1[i] == num) {
            return 1; // Duplicate found in arr1
        }
    }
    for (int i = 0; i < size2; i++) {
        if (arr2[i] == num) {
            return 1; // Duplicate found in arr2
        }
    }
    return 0; // No duplicate
}

void PrintArray(int MERGE_ARRAY[], int index){
    // Print merged array
    printf("MERGE_ARRAY\n");
    for (int i = 0; i < index; i++) {
        printf("%5d  ", MERGE_ARRAY[i]);
    }
    printf("\n");
}

void bubble_sortA(int MERGE_ARRAY[], int index) {
  for (int i = 0; i < index - 1; i++) {
    for (int j = 0; j < index - 1; j++) {
      if (MERGE_ARRAY[j] > MERGE_ARRAY[j + 1]) {
        int tmp = MERGE_ARRAY[j];
        MERGE_ARRAY[j] = MERGE_ARRAY[j + 1];
        MERGE_ARRAY[j + 1] = tmp;
      }
    }
  }
  PrintArray(MERGE_ARRAY, index);
}

void bubble_sortD(int MERGE_ARRAY[], int index) {
  for (int i = 0; i < index - 1; i++) {
    for (int j = 0; j < index - 1; j++) {
      if (MERGE_ARRAY[j] < MERGE_ARRAY[j + 1]) {
        int tmp = MERGE_ARRAY[j];
        MERGE_ARRAY[j] = MERGE_ARRAY[j + 1];
        MERGE_ARRAY[j + 1] = tmp;
      }
    }
  }
  PrintArray(MERGE_ARRAY, index);
}

void MERGE(int ArrayN[], int ArrayB[]) {
    int MERGE_ARRAY[SIZE * 2] = {};
    int index = 0;

    // Copy ArrayN into MERGE_ARRAY
    for (int i = 0; i < SIZE; i++) {
        MERGE_ARRAY[index++] = ArrayN[i];
    }

    // Add elements from ArrayB if they are not duplicates
    for (int i = 0; i < SIZE; i++) {
        if (!duplicate_checker(MERGE_ARRAY, index, ArrayB, 0, ArrayB[i])) { 
			// This part has negation since if No duplicate is found, meaning 0, it will need to be 1 for boolean value so it is negated so the if statement executes if there is no duplicates
            MERGE_ARRAY[index++] = ArrayB[i];
        }
    }
	
	PrintArray(MERGE_ARRAY, index);
	
	while(1){
		char choice;
		
		printf("\nDo you want to sort the array Ascending (A) or Descending (D): ");
		scanf("%s", &choice);
		
		choice = toupper(choice);
		
		if (choice == 'A'){
			bubble_sortA(MERGE_ARRAY, index);
			break;
		}else if (choice == 'D'){
			bubble_sortD(MERGE_ARRAY, index);
			break;
		}else{
			while(getchar()!='\n');
			printf("\nInvalid Input");
		}
	}	
}

int main() {
    int ArrayN[SIZE] = {}, ArrayB[SIZE] = {}, num = 0;

    printf("Enter 5 Integers for ArrayN\n");
    for (int i = 0; i < SIZE; ) {
    	while(1){
	    	printf("N(%d): ", i);
	        if(scanf("%d", &num) == 1){
	        	if (duplicate_checker(ArrayN, i, ArrayB, 0, num)) {
					// In this part if the duplicate checker return 1, the if would read it is a integer value 1 meaning true hence it would execute the if code
					// The size of 0 is passed to the funstion in size 2 in order to not exucute the code for array2 or ArrayB
	            
					printf("You can't enter the same integer.\n");
	        	} else { // In this part if the duplicate checker return 0, the if would read it is a boolean value of 0 or false hence it would execute the else code and skip the if code
	           	 	ArrayN[i] = num;
	            	i++;
	        	}
	        	break;
			}else{
				while(getchar()!= '\n');
				printf("Only integers are allowed\n");
			}	
		}
    }

    printf("\nEnter 5 Integers for ArrayB\n");
    for (int i = 0; i < SIZE; ) {
        while(1){
        	printf("N(%d): ", i);
        	if(scanf("%d", &num) == 1){
	        	if (duplicate_checker(ArrayN, 0, ArrayB, i, num)) {
	            	printf("You can't enter the same integer.\n");
	        	}else{
	            	ArrayB[i] = num;
	            	i++;
	        	}
	    	    break;
			}else{
				while(getchar()!= '\n');
				printf("Only integers are allowed\n");
			} 
		}   
    }

    // Print arrays
    printf("\nArrayN\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%5d  ", ArrayN[i]);
    }
    printf("\n");

    printf("\nArrayB\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%5d  ", ArrayB[i]);
    }
    printf("\n\n");

    // Merge and print result
    MERGE(ArrayN, ArrayB);
    
    return 0;
}
