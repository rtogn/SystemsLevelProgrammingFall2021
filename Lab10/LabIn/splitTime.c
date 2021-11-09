#include <stdio.h>

void split_time(long total_sec, int* hr, int* min, int* sec);

int main(){
        int n,hr,min,sec;
        printf("Enter seconds: ");
        scanf("%d", &n);

        split_time(total_sec, &hr, &min, &sec);

        printf("Converted format: %d hour %d mins %d secs\n", hr, min, sec);

}

void split_time(long total_sec, int* hr, int* min, int* sec){
        *hr = (int)(total_sec / (60 * 60));
        *min = (int)(total_sec / 60 % 60);
        *sec = (int)(total_sec % 60);
}
