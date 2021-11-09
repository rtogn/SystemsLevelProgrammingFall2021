#include <stdio.h>

int main(int arc, char *argv[]) {
        // Set up variables to read file.
        int  buffer_size, *bufferPT;
        FILE *file;
        buffer_size = 255;
        bufferPT = &buffer_size;

        // Read argument 1 (file name of txt file) scan and save into input_text char buffer.
        char input_text[*bufferPT];
        file = fopen(argv[1], "r");
        fscanf(file, "%s", input_text);
        //printf("%s\n", input_text);


        // Loop through each char of string (breaks at \0 if buffer is larger than letters)
        // For each letter run through string and increment count if letter j equals cur_let
        // finally, if the number counted is more than current winner set cur_let as most_frequent letter. 
        // Break second loop if letter has already been counted/is null. 
        char cur_let, most_frequent;
        int count, local_count, i, j;
        count = 0;
        i = 0;
        cur_let = '_';
        most_frequent = '_';
        while (cur_let != '\0') {
                cur_let = input_text[i];
                local_count = 0;
                for (j = 0; j < *bufferPT; j++) {
                        if (input_text[j] == '\0') break;
                        else if (cur_let == most_frequent) break;
                        else if (input_text[j] == cur_let) {
                                local_count++;
                        }
                }
                if (local_count > count) {
                        most_frequent = cur_let;
                        count = local_count;
                }
                i++;
        }
        printf("The most frequent letter is '%c'. It appeard %d times.\n", most_frequent, count);
}
