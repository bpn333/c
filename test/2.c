#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: extract_integers file_name\n");
    return 1;
  }

  // Open the file for reading
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error: Could not open file for reading\n");
    return 1;
  }

  // Read the file character by character
  int c;
  while ((c = fgetc(file)) != EOF) {
    // If the character is a digit, print it
    if (isdigit(c)) {
      printf("%c", c);
    }
  }

  // Close the file
  fclose(file);

  return 0;
}
