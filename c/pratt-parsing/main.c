#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dbg.h"

#define TOKEN_LITERAL_LEN 256

typedef enum TokenType {
    TOKEN_EOF,
    TOKEN_ILLEGAL,
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH
} TokenType;

typedef struct Token {
    TokenType type;
    char literal[TOKEN_LITERAL_LEN];
} Token;

typedef struct Lexer {
    const char* input;
    const char* position;
} Lexer;

typedef struct Parser {
    Lexer lexer;
    Token curr_token;
    Token next_token;
} Parser;

typedef enum Precedence {
    LOWEST,
    ADD_SUBTRACT,
    MULTIPLY_DIVIDE
} Precedence;

static void next_token(Lexer* l, Token* t);
static Parser* new_parser(const char* const input);
static void advance_tokens(Parser* p);

static int64_t calculate(Parser* p, Precedence precedence);

static Precedence token_type_to_precedence(TokenType type);

int main(int argc, char* argv[]) {
    const char* input = "14 - 2 * 2 * 2 * 2 * 2 + 1";

    Parser* p = new_parser(input);
    int64_t result = calculate(p, LOWEST);

    printf("%s = %ld\n", input, result);

    exit(EXIT_SUCCESS);
}

static int64_t calculate(Parser* p, Precedence precedence) {
    int64_t left = 0;
    int64_t right = 0;
    char* endptr = NULL;

    switch (p->curr_token.type) {
        case TOKEN_INT:
            left = strtoll(p->curr_token.literal, &endptr, 10);
            break;
        default:
            break;
    }

    advance_tokens(p);
    while (p->curr_token.type != TOKEN_EOF && precedence < token_type_to_precedence(p->curr_token.type)) {
        TokenType type = p->curr_token.type;
        advance_tokens(p);

        switch (type) {
            case TOKEN_PLUS:
                left = left + calculate(p, token_type_to_precedence(type));
                break;
            case TOKEN_MINUS:
                left = left - calculate(p, token_type_to_precedence(type));
                break;
            case TOKEN_ASTERISK:
                left = left * calculate(p, token_type_to_precedence(type));
                break;
            case TOKEN_SLASH:
                left = left / calculate(p, token_type_to_precedence(type));
                break;
            default:
                break;
        }
    }

    return left;
}

static Precedence token_type_to_precedence(TokenType type) {
    switch(type) {
        case TOKEN_PLUS:
        case TOKEN_MINUS:
            return ADD_SUBTRACT;
        case TOKEN_ASTERISK:
        case TOKEN_SLASH:
            return MULTIPLY_DIVIDE;
        default:
            return LOWEST;
    }
}

static Parser* new_parser(const char* const input) {
    Parser* p = (Parser*) malloc(sizeof(Parser));
    check_mem(p);

    p->lexer.input = input;
    p->lexer.position = input;

    next_token(&p->lexer, &p->curr_token);
    check(p->curr_token.type != TOKEN_EOF, "invalid input");
    next_token(&p->lexer, &p->next_token);

    return p;
error:
    exit(EXIT_FAILURE);
}

static void advance_tokens(Parser* p) {
    p->curr_token = p->next_token;
    next_token(&p->lexer, &p->next_token);
}

static void next_token(Lexer* l, Token* t) {
    // skip whitespaces
    while (isspace(*(l->position)))
        l->position++;

    const char curr_ch = *(l->position);

    switch (curr_ch) {
        case '+':
            t->type = TOKEN_PLUS;
            strncpy(t->literal, "+", TOKEN_LITERAL_LEN);
            break;
        case '-':
            t->type = TOKEN_MINUS;
            strncpy(t->literal, "-", TOKEN_LITERAL_LEN);
            break;
        case '*':
            t->type = TOKEN_ASTERISK;
            strncpy(t->literal, "*", TOKEN_LITERAL_LEN);
            break;
        case '/':
            t->type = TOKEN_SLASH;
            strncpy(t->literal, "/", TOKEN_LITERAL_LEN);
            break;
        case '\0':
            t->type = TOKEN_EOF;
            t->literal[0] = '\0';
            break;
        default:
            if (isdigit(curr_ch)) {
                size_t i = 0;
                while (isdigit(*(l->position)) && i < TOKEN_LITERAL_LEN - 1)
                    t->literal[i++] = *(l->position++);

                t->literal[i] = '\0';
                l->position--;
                t->type = TOKEN_INT;
            } else {
                t->type = TOKEN_ILLEGAL;
                t->literal[0] = '\0';
            }
            break;
    }

    l->position++;
}
