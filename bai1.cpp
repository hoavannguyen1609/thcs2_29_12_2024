#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int readFromFile(const char *filename, int numbers[], int *n) {
	FILE *file = fopen(filename, "r");
	
	if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        exit(1);
    }
    
    fscanf(file, "%d", n);
    
    int i = 0;
    
    while(i < *n) {
    	fscanf(file, "%d", &numbers[i]);
    	
    	i++;
	}
   
    fclose(file);
}

int writeToFile(const char *filename) {
	FILE *file;
	
	file = fopen(filename, "w");
		
	if (file == NULL) {
        printf("Khong the tao tep %s\n", filename);
        return 1;
    } else {
        int n;
        printf("Nhap do dai cua mang: ");
        scanf("%d", &n);
        	
        fprintf(file, "%d\n", n);
        	
        int arr[n];
        	
        printf("Nhap cac phan tu cua mang: ");
        	
        int i = 0;
        while(i < n) {
        	scanf("%d", &arr[i]);
        	fprintf(file, "%d ", arr[i]);
        		
        	i++;
		}
			
        fprintf(file, "\n");
        	
        fclose(file);
        	
        printf("Tep %s da duoc tao thanh cong.\n", filename);

    }
}

void printArray(int numbers[], int n) {
    printf("Mang ban dau: ");
    
    int i = 0;
    
    while(i < n) {
    	printf("%d ", numbers[i]);
    	
    	i++;
	}
    
    printf("\n");
}

void swapSxChon(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}

void xuatSxChon(int arr[], int n, int i) {
	printf("Buoc %d:", i);
	
	i =0;
	
	while(i < n) {
		printf(" %d", arr[i]);
		
		i++;
	}
}

void sxChon(int arr[], int n) {
	int i = 0;
	int j, min;
	
	while(i < n - 1) {
		min = i;
		
		j = i + 1;
		
		while(j < n) {
			if(arr[j] < arr[min]) {
				min = j;
			}
			
			j++;
		}
		
		if(i!= min) {
			swapSxChon(arr[min], arr[i]);
		}
		
		xuatSxChon(arr, n, i + 1);
		printf("\n");
		
		i++;
	}
}


void xuatSxChen(int arr[], int n, int i) {
	int j = 0;
	printf("Buoc %d:", i);
	
	while(j<=i) {
		printf("%3d", arr[j]);
		
		j++;
	}
}

void sxChen(int arr[], int n) {
	int i = 1;
	int j, x;
	
	printf("Buoc 0:%3d\n", arr[0]);
	
	while(i < n) {
		x = arr[i];
		j = i - 1;
		
		while(x < arr[j] && j >= 0) {
			arr[j+1] = arr[j];
			
			j--;
		}
		
		arr[j+1] = x;
		
		xuatSxChen(arr, n, i);
		printf("\n");
		i++;
	}
}

int main() {
	const char *fileName = "input.txt";
	
	FILE *file = fopen(fileName, "r");
	int numbers[MAX_SIZE];
	int n;
	
	if (file != NULL) {
        fclose(file);
        readFromFile(fileName, numbers, &n);
    } else {
        printf("File \"%s\" chua ton tai. Tao file moi va ghi noi dung vao.\n", fileName);
        writeToFile(fileName);
        readFromFile(fileName, numbers, &n);
    }
    
    printArray(numbers, n);
    
    printf("Sap xep chon:\n");
    sxChon(numbers, n);
    
    readFromFile(fileName, numbers, &n);
    printf("Sap xep chen:\n");
	sxChen(numbers, n);
	
	return 0;
}
