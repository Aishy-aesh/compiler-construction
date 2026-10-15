# Lab 02 token inventory

Replace STUDENT_ID and SECTION below.

Student ID: 232-115-080
Section: B

## Token sequence for public.c

Replace the contents of the following single text block. List every emitted
lexeme and token in source order, including repeated occurrences. Omit comments
and whitespace. Do not add a header row inside the block.

```text
int,KEYWORD main,IDENTIFIER (,LPAREN ),RPAREN {,LBRACE int,KEYWORD count,IDENTIFIER =,ASSIGN 3,INTEGER ;,SEMICOLON int,KEYWORD total,IDENTIFIER =,ASSIGN 0,INTEGER ;,SEMICOLON while,KEYWORD (,LPAREN count,IDENTIFIER

,GT 0,INTEGER ),RPAREN {,LBRACE total,IDENTIFIER =,ASSIGN total,IDENTIFIER +,PLUS count,IDENTIFIER ;,SEMICOLON count,IDENTIFIER =,ASSIGN count,IDENTIFIER -,MINUS 1,INTEGER ;,SEMICOLON },RBRACE if,KEYWORD (,LPAREN total,IDENTIFIER =,GTE 6,INTEGER &&,AND count,IDENTIFIER ==,EQ 0,INTEGER ),RPAREN {,LBRACE return,KEYWORD total,IDENTIFIER ;,SEMICOLON },RBRACE else,KEYWORD {,LBRACE return,KEYWORD 0,INTEGER ;,SEMICOLON },RBRACE },RBRACE
```
