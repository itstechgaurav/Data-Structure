#include<stdio.h>
#include<stdlib.h>

typedef struct _ARR_ {
    int storage[10];
    int size, length;
} Array;

Array createArray() {
    Array ar;
    printf("Enter the size of new array: ");
    scanf("%d", &ar.size);

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

int binarySearch(Array *array, int l, int h, int key) {
    int m;
    while(l <= h) {
        m = (l + h) / 2;

        if(key == array->storage[m])
            return m;
        else if(key < array->storage[m])
            h = m - 1;
        else
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

int array_main() {
    Array array = createArray();

    append(&array, 10);
    append(&array, 20);
    append(&array, 30);
    append(&array, 40);
    append(&array, 50);

    // display
    display(array);

    // search
    int key = 50;
//    printf("Element %d found @ %d\n", key, recursiveBinarySearch(&array, 0, array.length - 1, key));
    printf("Sum = %d\n", sumRecursive(array, 0));
    printf("Min = %d\n", min(array));
    printf("Max = %d\n", max(array));
    printf("Average = %d\n", average(array));
    display(array);
    return 0;
}