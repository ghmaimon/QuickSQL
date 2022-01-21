#include "../headers/parser.h"

char* erreurs[] = {
    // column directives
    "ERROR_PK", "ERROR_FK", "ERROR_CHECK", "ERROR_NN", "ERROR_BETWEEN",
    "ERROR_INDEX", "ERROR_DEFAULT", "ERROR_UNIQUE",
    // data types
    "ERROR_NUM", "ERROR_INT", "ERROR_D", "ERROR_TS",
    "ERROR_VC", "ERROR_VCNNN", "ERROR_CLOB", "ERROR_BLOB", "ERROR_JSON",
    // table directives
    "ERROR_TD_COLPREFIX", "ERROR_TD_SELECT",
    // comments
    "ERROR_DOUBLE_HYPHEN", "ERROR_OPN_BRCKT", "ERROR_CLS_BRCKT", "ERROR_COMMENT",
    // other
    "ERROR_ID", "ERROR_VIEW", "ERROR_NL", "ERROR_VALUE", "ERROR_COMMA",
    "ERROR_EOF", "ERROR_ERR", "ERROR_WHITESPACE", "ERROR_NUMBER", "ERROR_STRING"
};

void test_symbole(Token token) {
    if (token != current_token) error((Error)token);
    else next_token();
}

void error(Error err) {
    printf("erreur de type :%s", erreurs[err]);
    exit(-1);
}

void program() {
    if (current_token == TOKEN_ID) {
        table();
        program();
    }
    if (current_token == TOKEN_VIEW) {
        view ();
        program();
    }
}

void view() {
  test_symbole(TOKEN_VIEW);
  test_symbole(TOKEN_ID);
  test_symbole(TOKEN_ID);
  while(current_token != '\n') {
    test_symbole(TOKEN_ID);
  }
}

void table() {
    test_symbole(TOKEN_ID);
    while (current_token == TOKEN_TD_COLPREFIX
          || current_token == TOKEN_TD_SELECT)
    {
        table_directives();
    }
    test_symbole(TOKEN_NL);
    column();
    while (current_token == TOKEN_WHITESPACE)
    {
        column();
    }
}

