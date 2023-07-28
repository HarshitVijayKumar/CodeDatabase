#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_CONSTANT,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER
} token_type_t;

typedef struct {
    token_type_t type;
    char value[MAX_TOKEN_LENGTH];
} token_t;

token_t get_next_token(FILE *fp) {
    token_t token;
    int i = 0;
    char c = fgetc(fp);
    while (isspace(c)) {
        c = fgetc(fp);
    }
    if (c == '/') {
        int next = fgetc(fp);
        if (next == '/') {
            while (c != EOF && c != '\n') {
                c = fgetc(fp);
            }
        } else {
            ungetc(next, fp);
        }
    }
    
    if (isalpha(c) || c == '_') {
        token.type = TOKEN_IDENTIFIER;
        while (isalnum(c) || c == '_') {
            token.value[i++] = c;
            c = fgetc(fp);
        }
        ungetc(c, fp);
    } else if (isdigit(c)) {
        token.type = TOKEN_CONSTANT;
        while (isdigit(c)) {
            token.value[i++] = c;
            c = fgetc(fp);
        }
        ungetc(c, fp);
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
               c == '=' || c == '>' || c == '<' || c == '!' ||
               c == '&' || c == '|' || c == '^') {
        token.type = TOKEN_OPERATOR;
        token.value[i++] = c;
        if (c == '+' || c == '-' || c == '&' || c == '|') {
            if ((c = fgetc(fp)) == token.value[0]) {
                token.value[i++] = c;
            } else {
                ungetc(c, fp);
            }
        } else if (c == '=') {
            if ((c = fgetc(fp)) == '=') {
                token.value[i++] = c;
            } else {
                ungetc(c, fp);
            }
        } else if (c == '>') {
            if ((c = fgetc(fp)) == '=') {
                token.value[i++] = c;
            } else {
                ungetc(c, fp);
            }
        } else if (c == '<') {
            if ((c = fgetc(fp)) == '=') {
                token.value[i++] = c;
            } else {
                ungetc(c, fp);
            }
        }
    } else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']'
               || c == ';' || c == ',' || c == '.') {
        token.type = TOKEN_DELIMITER;
        token.value[i++] = c;
    } else {
        token.type = TOKEN_DELIMITER;
        token.value[i++] = c;
    }
    token.value[i] = '\0';
    
    if (token.type == TOKEN_IDENTIFIER) {
        char *keywords[] = {"auto", "break", "case", "char", "const", "continue",
                            "default", "do", "double", "else", "enum", "extern",
                            "float", "for", "goto", "if", "int", "long","register", "return", "short", "signed", "sizeof", "static",
                            "struct", "switch", "typedef", "union", "unsigned", "void",
                            "volatile", "while"};
    int num_keywords = sizeof(keywords) / sizeof(char*);
    for (int j = 0; j < num_keywords; j++) {
        if (strcmp(token.value, keywords[j]) == 0) {
            token.type = TOKEN_KEYWORD;
            break;
        }
    }
}
return token;
}
int main(int argc, char *argv[])
{
char *filename = "input.txt";
FILE *fp = fopen(filename, "r");

token_t token;
while (!feof(fp)) {
    token = get_next_token(fp);
    switch (token.type) {
        case TOKEN_KEYWORD:
            printf("keyword, %s\n", token.value);
            break;
        case TOKEN_IDENTIFIER:
            printf("identifier, %s\n", token.value);
            break;
        case TOKEN_CONSTANT:
            printf("constant, %s\n", token.value);
            break;
        case TOKEN_OPERATOR:
            printf("operator, %s\n", token.value);
            break;
        case TOKEN_DELIMITER:
            printf("delimiter, %s\n", token.value);
            break;
    }
}
fclose(fp);
return 0;
}
