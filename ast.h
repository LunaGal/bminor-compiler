typedef struct decl {
	char *name;
	type_t *type;
	expr_t *value;
	stmt_t *code;
	decl_t *next;
} decl_t;

typedef enum
{
	BOOL,
	STRING,
	INTEGER,
	CHARACTER,
	VOID	
} type_t;

typedef struct type
{
	type_t type;
	bool function;
	list_t args;
} type_t;



decl_t *decl_create( char *name,
	type_t *type,
	expr_t *value,
	stmt_t *code,
	decl_t *next )

print_decl(decl_t input, int num_indent) {
	
}