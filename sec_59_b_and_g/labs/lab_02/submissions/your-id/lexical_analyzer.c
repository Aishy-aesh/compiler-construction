/* Lab 02: implement the section manual's lexical contract.
   Read argv[1] with fopen/fgetc. Do not hard-code public.c or its token list.
   You may add helper functions. This starter is deliberately unfinished. */
#include <stdio.h>
#include<string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: lexical_analyzer input.c\n");
        return 2;
    }
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("input");
        return 2;
    }
     int c;

    while ((c = fgetc(input)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            continue;
        }

        if (c == '/') {
            int next = fgetc(input);

            if (next == '/') {
                while ((c = fgetc(input)) != EOF && c != '\n') {
                }
                continue;
            }

            if (next == '*') {
                int previous = 0;

                while ((c = fgetc(input)) != EOF) {
                    if (previous == '*' && c == '/') {
                        break;
                    }
                    previous = c;
                }
                continue;
            }

            if (next != EOF) {
                ungetc(next, input);
            }
            printf("/,OPERATOR\n");
            continue;
        }

        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') || c == '_') {
            char word[256];
            int i = 0;

            do {
                if (i < 255) {
                    word[i++] = (char)c;
                }
                c = fgetc(input);
            } while ((c >= 'a' && c <= 'z') ||
                     (c >= 'A' && c <= 'Z') ||
                     (c >= '0' && c <= '9') || c == '_');

            word[i] = '\0';

            if (c != EOF) {
                ungetc(c, input);
            }

            const char *keywords[] = {
                "int", "char", "float", "double", "void",
                "if", "else", "while", "for", "return",
                "break", "continue", "long", "short",
                "const", "struct", "sizeof"
            };

            int is_keyword = 0;

            for (int k = 0; k < 17; k++) {
                if (strcmp(word, keywords[k]) == 0) {
                    is_keyword = 1;
                    break;
                }
            }

            printf("%s,%s\n", word,
                   is_keyword ? "KEYWORD" : "IDENTIFIER");
            continue;
        }

        if (c >= '0' && c <= '9') {
            char number[256];
            int i = 0;

            do {
                if (i < 255) {
                    number[i++] = (char)c;
                }
                c = fgetc(input);
            } while (c >= '0' && c <= '9');

            number[i] = '\0';

            if (c != EOF) {
                ungetc(c, input);
            }

            printf("%s,INTEGER\n", number);
            continue;
        }

        if (c == '=' || c == '!' || c == '<' || c == '>') {
            int next = fgetc(input);

            if (next == '=') {
                printf("%c=,OPERATOR\n", c);
            } else {
                if (next != EOF) {
                    ungetc(next, input);
                }
                printf("%c,OPERATOR\n", c);
            }
            continue;
        }

        if (c == '+' || c == '-' || c == '*' ||
            c == '%' || c == '&' || c == '|') {
            printf("%c,OPERATOR\n", c);
            continue;
        }

        if (c == ';' || c == ',' || c == '(' || c == ')' ||
            c == '{' || c == '}' || c == '[' || c == ']') {
            printf("%c,PUNCTUATION\n", c);
        }
    }

    return 0;
}
