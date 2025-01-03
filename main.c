#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *name) {
    printf("Usage: %s <file>\n", name);
}

int main(int argc, char *argv[]) {
    FILE *infile, *outfile;
    char *filename;
    int c;
    const long skip_bytes = 292;

    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    filename = argv[1];

    if ((infile = fopen(filename, "rb")) == NULL) {
        perror("Error opening input file");
        return 2;
    }

    if ((outfile = fopen("temp.bin", "wb")) == NULL) {
        perror("Error creating temp file");
        fclose(infile);
        return 3;
    }

    if (fseek(infile, skip_bytes, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(infile);
        fclose(outfile);
        return 4;
    }

    while ((c = fgetc(infile)) != EOF) {
        fputc(c, outfile);
    }

    fclose(infile);
    fclose(outfile);

    char new_filename[256];
    strcpy(new_filename, filename);
    strcat(new_filename, ".jpeg");

    remove(filename);
    rename("temp.bin", filename);

    return 0;
}