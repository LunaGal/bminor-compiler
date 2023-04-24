//Typedefs

typedef enum {
	TYPE_VOID,
	TYPE_BOOLEAN,
	TYPE_CHARACTER,
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_FUNCTION
} type_kind_t;

typedef struct param_list {
	char *name;
	struct type *type;
	struct param_list *next;
} param_list_t;

typedef struct type {
	type_kind_t kind;
	struct type *subtype;
	param_list_t *params;
} type_t;

typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_NAME,
	EXPR_INTEGER_LITERAL,
	EXPR_STRING_LITERAL
} expr_kind_t;

typedef struct expr {
	expr_kind_t kind;
	struct expr *left;
	struct expr *right;
	const char *name;
	int integer_value;
	const char *string_literal;
} expr_t;

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_kind_t;

typedef struct stmt {
	stmt_kind_t kind;
	struct decl *decl;
	expr_t *init_expr;
	expr_t *expr;
	expr_t *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
} stmt_t;

typedef struct decl {
	char *name;
	type_t *type;
	expr_t *value;
	stmt_t *code;
	struct decl *next;
} decl_t;

//Constructor Headers

decl_t *decl_create(char *name,
	type_t *type,
	expr_t *value,
	stmt_t *code,
	decl_t *next);

stmt_t *stmt_create(stmt_kind_t kind,
	decl_t *decl,
	expr_t *init_expr,
	expr_t *expr,
	expr_t *next_expr,
	stmt_t *body,
	stmt_t *else_body,
	stmt_t *next);

expr_t *expr_create_binary(expr_kind_t kind, expr_t *left, expr_t);
expr_t *expr_create_name( const char *name );
expr_t *expr_create_integer_literal( int i );
expr_t *expr_create_boolean_literal( int b );
expr_t *expr_create_char_literal( char c );
expr_t *expr_create_string_literal( const char *str );

type_t *type_create(type_kind_t kind, type_t *subtype, param_list_t *params);
param_list_t *param_list_create(char *name, type_t *type, param_list_t *next);

//Printing Headers

void print_decl(decl_t *input, int num_indent);
void print_stmt(stmt_t *input, int num_indent);
void print_expr(expr_t *input, int num_indent);
void print_type(type_t *input, int num_indent);
void print_stmt_kind(stmt_kind_t kind, int num_indent);
void print_type_kind(type_kind_t kind, int num_indent);
void print_expr_kind(expr_kind_t kind, int num_indent);