#include<stdio.h>
#include<stdlib.h>

#define true 1;
#define false 0;
#define boolean int;

typedef struct ARRAY_ {
    int storage[20];
    int size, length;
} Array;

Array createArray() {
    Array ar;
//    printf("Enter the size of new array: ");
//    scanf("%d", &ar.size);
    ar.size = 20;

//    ar.storage = (int *) malloc(sizeof(int) * ar.size);
    ar.length = 0;

    return ar;
}

void display(Array arr) {
    int i = 0;

    for(; i < arr.length; i++)
        printf("%d ", arr.storage[i]);

    printf("\n");
}

void insert(Array *arr, int index, int data) {
    int i = arr->length;
    if(arr->length < arr->size) {
        for(; i > index; i++) {
            arr->storage[i] = arr->storage[i - 1];
        }
        arr->storage[index] = data;
        arr->length = arr->length + 1;
    } else {
        printf("Not enough space to insert %d\n", data);
    }
}

void append(Array *arr, int data) {
    insert(arr, arr->length, data);
}

void delete(Array *arr, int index) {
    int i = index;
    int data;

    if(index < arr->length) {
        data = arr->storage[index];
        for(; i < arr->length; i++) {
            arr->storage[i] = arr->storage[i + 1];
        }
        printf("%d is deleted\n", data);
        arr->length--;
    } else {
        printf("Unable to delete\n");
    }
}

int get(Array arr, int index) {
    if(index >= 0 && index < arr.length)
        return arr.storage[index];
    return 0;
}

void set(Array arr, int index, int data) {
    if(index >= 0 && index < arr.length)
        arr.storage[index] = data;
}

int sum(Array arr) {
    int total = 0;
    while(arr.length > 0) {
        total += arr.storage[arr.length - 1];
        arr.length--;
    }
    return total;
}

int sumRecursive(Array arr, int index) {
    if(index >= arr.length || index < 0) {
        return 0;
    }
    return arr.storage[index] + sumRecursive(arr, index + 1);
}

void swap(Array *arr, int index, int swapIndex) {
    int tmp = arr->storage[index];
    arr->storage[index] = arr->storage[swapIndex];
    arr->storage[swapIndex] = tmp;
}

int min(Array arr) {
    int no = arr.storage[0], i = 0;
    for(; i < arr.length; i++) {
        if(arr.storage[i] < no)
            no = arr.storage[i];
    }
    return no;
}

int max(Array arr) {
    int no = arr.storage[0], i = 0;
    for(; i < arr.length; i++) {
        if(arr.storage[i] > no)
            no = arr.storage[i];
    }
    return no;
}

int average(Array arr) {
    return sum(arr) / arr.length;
}

// searching

// # linear Search

int linearSearch(Array *arr, int key) {
    int i;

    for(i = 0; i < arr->length; i++) {
        if(key == arr->storage[i]) {
            return i;
        }
    }
    return -1;
}

int transpositionLinearSearch(Array *arr, int key) {
    int i;
    for(i = 0; i < arr->length; i++) {
        if(key == arr->storage[i]) {
            // swap with just previous
           if(i != 0) {
               swap(arr, i, i - 1);
               return i - 1;
           }
           return i;
        }
    }
    return -1;
}

int moveToHeadLinearSearch(Array *arr, int key) {
    int i;
    for(i = 0; i < arr->length; i++) {
        if(key == arr->storage[i]) {
            if(i != 0) {
                swap(arr, i, 0);
            }
            return 0;
        }
    }
}

// # Binary Search

int binarySearch(Array *array, int key) {
    int m, l = 0, h = array->length;
    while(l <= h) {
        m = (l + h) / 2;

        if(key == array->storage[m])
            return m;
        else if(key < array->storage[m])
            h = m - 1;
        else if(key > array->storage[m])
            l = m + 1;
    }

    return -1;
}

// # Recursive Binary Search

int recursiveBinarySearch(Array *array, int l, int h, int key) {
    if(l <= h) {
        int m = (l + h) / 2;

        if(key == array->storage[m])
            return m;
        else if(key < array->storage[m])
            return recursiveBinarySearch(array, l, m - 1, key);
        else
            return recursiveBinarySearch(array, m + 1, h, key);
    }
    return -1;
}

void reverseArray(Array *array) {
    int aux_array[array->length];
    int i = 0;
    for(; i < array->length; i++) {
        aux_array[i] = array->storage[array->length - 1 - i]; // copy into auxilary array in reverse order
    }

    for(i = 0; i < array->length; i++) {
        array->storage[i] = aux_array[i];
    }
}

void reverseArraySwapMethod(Array *array) {
    int i, j, tmp;
    //  i - Start
    //  j - End
    for(i = 0, j = array->length - 1; i < j; i++, j--) {
        tmp = array->storage[i];
        array->storage[i] = array->storage[j];
        array->storage[j] = tmp;
    }
}

void leftShift(Array *array) {
   int i = 0;
   for(; i < array->length; i++) {
       array->storage[i] = array->storage[i + 1];
   }
   array->storage[array->length - 1] = 0;
}

void leftRotate(Array *array) {
    int first = array->storage[0];
    leftShift(array);
    array->storage[array->length - 1] = first;
}

void rightShift(Array *array) {
    int i = array->length - 1;
    for(; i >= 0; i--) {
        array->storage[i] = array->storage[i - 1];
    }
    array->storage[0] = 0;
}

void rightRotate(Array *array) {
    int last = array->storage[array->length - 1];
    rightShift(array);
    array->storage[0] = last;
}

void insertIntoSortedArray(Array *array, int x) {
    int i = array->length - 1;
    while(array->length > 0 && array->storage[i] > x) {
        array->storage[i + 1] = array->storage[i];
        i--;
    }
    array->storage[i + 1] = x;
    array->length++;
}



boolean isSorted(Array array) {
    // A = [ 4, 8, 13, 26, 25, 28, 33 ], Length = 7
    // then length - 1 = index(6) = 33
    // then length - 2 = index(5) = 28
    //
    while(array.length - 1 > 0) { // it will stop at index(0) because it is already checked at(1) condition
        // checking if at(length - 2) > at(length - 1)
        // comparing last one with its previous and if last is not greater the previous the return false
        if(array.storage[array.length - 2] > array.storage[array.length - 1]) {
            return  false;
        }
        array.length--;
    }
    return true; // [ Zero Element exists | 1 element exists | list is sorted ]
}

void shiftNegativeToLeft(Array *array) {
    int i = 0, j = array->length - 1;

    while(i < j) {
        while(array->storage[i] < 0) i++;
        while(array->storage[j] >= 0) j--;

        if(i < j) {
            swap(array, i, j);
        }
    }
}

void shiftNegativeToLeft_(Array *array) {
    int i = 0, j = array->length - 1;

    while(i < j) {
        if(array->storage[i] >= 0 && array->storage[j] < 0) { // LOOK FOR WHERE A[I] +VE AND A[J] -VE THEN SWAP
            swap(array, i, j); // SWAP THEM
            i++, j--; // AND INCREMENT AND DECREMENT I AND J
        } else { // IF NOT FOUND THEN INCREMENT OR DECREMENT I AND J
            if(i < 0) i++;
            else j--;
        }
    }
}

Array mergeSortedArray(Array *A, Array *B) {
    int i = 0, j = 0;
    Array C = createArray();

    while(i < A->length && j < B->length) {
        if(A->storage[i] <= B->storage[j]) { // compare both and smaller one will be inserted int C@length
            C.storage[C.length++] = A->storage[i++]; // if A[i] is smaller
        } else {
            C.storage[C.length++] = B->storage[j++]; // if B[j] is smaller
        }
    }

    for(; i < A->length; i++) // if A's elements remaining to insert
        C.storage[C.length++] = A->storage[i++]; // insert A's elements at length

    for(; j < B->length; j++) // if B's elements remaining to insert
        C.storage[C.length++] = B->storage[j++]; // insert A's elements at length

    return C;
}


Array mergeSortedArray_(Array *A, Array *B) {
    int i = 0, j = 0;
    Array C = createArray();

    while(i < A->length || j < B->length) { // loop until every element is loop over
        if((i < A->length && j < B->length)) { // if we have both index then
            if(A->storage[i] <= B->storage[j]) { // compare both and smaller one will be inserted int C@length
                C.storage[C.length++] = A->storage[i++]; // if A[i] is smaller
            } else {
                C.storage[C.length++] = B->storage[j++]; // if B[j] is smaller
            }
        } else if(i < A->length) { // if A have remaining elements
            C.storage[C.length++] = A->storage[i++]; // insert A's elements at length
        } else {
            C.storage[C.length++] = B->storage[j++]; // else insert B's elements at length
        }
    }
    return C;
}

Array arrayUnion(Array *first, Array *second) {
    Array united = createArray();
    int i = 0;
    for(; i < first->length; i++) { // first copy the first array into united
        united.storage[united.length++] = first->storage[i];
    }
    i = 0;

    for(; i < second->length; i++) {
        // compare elements of second and if they don't exists in united then push into united
        if(linearSearch(&united, second->storage[i]) == -1) { // if element not found
            united.storage[united.length++] = second->storage[i];
        }
    }
    return united;
}

Array arrayUnionMergingMethod(Array *first, Array *second) {
    int i, j = i = 0;
    Array united = createArray();
    while(i < first->length && j < second->length) {
        if(first->storage[i] == second->storage[j]) {
            united.storage[united.length++] = first->storage[i];
            i++, j++;
        } else if(first->storage[i] < second->storage[j]) {
            united.storage[united.length++] = first->storage[i++];
        } else {
            united.storage[united.length++] = second->storage[j++];
        }
    }

    while(i < first->length) united.storage[united.length++] = first->storage[i++];
    while(j < second->length) united.storage[united.length++] = second->storage[j++];

    return united;
}

Array arrayIntersection(Array *first, Array *second) {
    Array intersection = createArray();

    for(int i = 0; i < first->length; i++) {
        if(linearSearch(second, first->storage[i]) != -1) {
            intersection.storage[intersection.length++] = first->storage[i];
        }
    }

    return intersection;
}

Array arrayIntersectionMergeMethod(Array *first, Array *second) {
    int i, j = i = 0;
    Array intersection = createArray();

    while(i < first->length && j < second->length) {
        if(first->storage[i] == second->storage[j]) {
            intersection.storage[intersection.length++] = first->storage[i];
            i++, j++;
        } else if(first->storage[i] < second->storage[j]) {
            i++;
        } else j++;
    }

    return intersection;
}

Array arrayDifference(Array *first, Array *second) {
    Array difference = createArray();

    for(int i = 0; i < first->length; i++) {
        if(linearSearch(second, first->storage[i]) == -1) {
            difference.storage[difference.length++] = first->storage[i];
        }
    }

    return difference;
}

Array arrayDifferenceMergeMethod(Array *first, Array *second) {
    Array difference = createArray();
    int i, j = i = 0;

    while(i < first->length && j < second->length) {
        if(first->storage[i] == second->storage[j]) {
            i++, j++;
        } else if(first->storage[i] < second->storage[j]) {
            difference.storage[difference.length++] = first->storage[i];
            i++;
        } else j++;
    }

    while(i < first->length) difference.storage[difference.length++] = first->storage[i++];
    return difference;
}

int array_main() {
    Array first = createArray();
    Array second = createArray();
    Array united, intersection, difference;

//    append(&first, 3);
//    append(&first, 5);
//    append(&first, 10);
//    append(&first, 4);
//    append(&first, 6);
//
//    append(&second, 12);
//    append(&second, 4);
//    append(&second, 7);
//    append(&second, 5);
//    append(&second, 2);

//    united = arrayUnion(&first, &second);
//    intersection = arrayIntersection(&first, &second);
//    difference = arrayDifference(&first, &second);

    append(&first, 3);
    append(&first, 4);
    append(&first, 5);
    append(&first, 6);
    append(&first, 14);


    append(&second, 2);
    append(&second, 4);
    append(&second, 5);
    append(&second, 7);
    append(&second, 12);

//    united = arrayUnionMergingMethod(&first, &second);
//    intersection = arrayIntersectionMergeMethod(&first, &second);
    difference = arrayDifferenceMergeMethod(&first, &second);

    display(first);
    display(second);
//    display(united);
//    display(intersection);
    display(difference);

    return 0;
}