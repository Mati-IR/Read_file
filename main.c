#include <stdio.h>
int read_file(const char *filename);

int main() {
    char file_name[31];
    printf("Input file name:\t");
    scanf("%30s", file_name);
    int result = read_file(file_name);
    if ( result == -1 || result == 0 )
    {
        printf("Couldn't open file");
        return 4;
    }
    printf("%d", result);
    return 0;
}

int read_file(const char *filename) {
    if (filename == NULL) {//     NULL case
        return -1;
    }
    char buffer[31];
    int counter = 0;
    FILE *f = fopen(filename, "r");
    if ( f == NULL )//      checking if file exists/was opened correctly
        return 0;
    counter++;
    int result;
    FILE *sub_file;//   var for files named in buffer
    while (!feof(f)){
        if (fscanf(f, "%30s", buffer) != 1 ){// incorrect input case
            fclose(f);
            return counter;
        }
        printf("%s\n", buffer);
        sub_file = fopen(buffer, "r");
        if ( sub_file == NULL ){//     checking if file with file name in variable buffer exists
            continue;
        } else{
            result = read_file(buffer);
            fclose(sub_file);
            if ( result > 0 )//
                counter += result;
        }
        if (feof(f)) {//
            fclose(f);
            return counter;
        }
    }
    return counter;
}