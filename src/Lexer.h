#pragma once

/* Represents the type of a token */
enum TokenType {
    NULL_TOKEN
};

/*
* The structure of a token wich is very similar to a word.
* @param word The string representation of the word.
* @param type The type of the token 
*/
typedef struct Token {
    char          *word;
    enum TokenType type;
} Token;

/*
* Tokenize a string as a list of tokens.
* @param str The string to tokenize.
* @returns The list of token.
*/
Token *Tokenize(char str[]);