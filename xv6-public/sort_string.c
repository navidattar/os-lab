#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void swap(char* xp, char* yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void selectionSort(char arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
	arr[n]='\n';
}

int main(int argc, char *argv[]) 
{
    if(argc<=1 || argc>2){
        printf(1, "argument count invalid\n");
        exit();
    }
	
	int length = strlen(argv[1]);
    char string[length+1];
	strcpy (string, argv[1]);
	int file;
	

	
	if(open("sort_string.txt", O_RDONLY) != -1){
    	unlink("sort_string.txt");
    }
    file = open("sort_string.txt", O_CREATE | O_WRONLY );
    if(file == -1){
        printf(1, "failed in creat and open file!\n");
        exit();
    }


    selectionSort(string, length);
	write(file, string, length+1);
    close(file);

    exit();
}