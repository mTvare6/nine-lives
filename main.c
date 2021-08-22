#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFFER 32


#define LIVES 9
#define CUSTOMFILE 1

void update_clue(char gletter, char *s, char *clue, size_t w_len, size_t *not_found);
char *readString();

int main(int argc, char **argv) {

  srand(time(0));


  bool guessed = false;
#if(CUSTOMFILE==0)
  char *words[] = {"word", "c", "clang", "nice", "github"};
  char *s = words[rand() % (sizeof(words)/sizeof(*(words)))];
  size_t w_len = strlen(s);
#else
  if (argc<2){
    fputs("No file provided\n", stderr);
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  char *s = malloc(sizeof(char)*128);

  if(fp != NULL) {
    size_t i=0;
    while(!feof(fp)){
      fscanf(fp, "%s", s);
      i++;
    }
    fseek(fp, rand() % (i + 1), SEEK_SET);
    fscanf(fp, "%s", s);
    fclose(fp);
  }
  else{
    fputs("Unable to open file provided\n", stderr);
    exit(2);
  }

  size_t w_len = strlen(s);

#endif


  size_t not_found = w_len;
  uint16_t lives = LIVES;

  char *clue = malloc(w_len * sizeof(char));
  memset(clue, '?', w_len);

  while (lives > 0) {
    puts(clue);
    printf("Lives left: %d\n", lives);
    char *gletter = readString();

    /* if(strncmp(gletter, clue, w_len)==0) */
    if (strncmp(gletter, s, w_len) == 0) {
      guessed = true;
      break;
    }

    if (strstr(s, gletter)) {
      update_clue(gletter[0], s, clue, w_len, &not_found);
      if(not_found==0){
        puts(s);
        guessed = true;
        break;
      }
    } else {
      puts("Incorrect choice");
      lives--;
    }
  }

  if(guessed) printf("You won, with %d lives", lives);
  else        printf("You lost, the word was %s", s);

  free(clue);
#if(CUSTOMFILE==0)
  free(s);
#endif
  return 0;
}

char *readString() {
  char *str = malloc(sizeof(char) * BUFFER), *err;
  unsigned long pos;
  for (pos = 0; str != NULL && (str[pos] = (char)getchar()) != '\n'; pos++) {
    if (pos % BUFFER == BUFFER - 1) {
      if ((err = realloc(str, sizeof(char) * (BUFFER + pos + 1))) == NULL)
        free(str);
      str = err;
    }
  }
  if (str != NULL)
    str[pos] = '\0';
  return str;
}

void update_clue(char gletter, char *s, char *clue, size_t w_len, size_t *not_found) {
  size_t i = 0;
  while (i < w_len) {
    if (*(s+i) == gletter) {
      *(clue+i) = gletter;
      *not_found-=1;
    }
    i++;
  }
}
