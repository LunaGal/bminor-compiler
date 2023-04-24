#include <stddef.h>
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

decl_t *decl_create( char *name, type_t *type, expr_t *value, stmt_t *code, decl_t *next) {
	decl_t *d = malloc(sizeof(*d));
	d->name = name;
	d->type = type;
	d->value = value;
	d->code = code;
	d->next = next;
	return d;
}

stmt_t *stmt_create(stmt_kind_t kind,
	decl_t *decl,
	expr_t *init_expr,
	expr_t *expr,
	expr_t *next_expr,
	stmt_t *body,
	stmt_t *else_body,
	stmt_t *next) {
	stmt_t *s = malloc(sizeof(*s));
	s->kind = kind;
	s->decl = decl;
	s->init_expr = init_expr;
	s->expr = expr;
	s->next_expr = next_expr;
	s->body = body;
	s->else_body = else_body;
	s->next = next;
	return s;
}

expr_t *expr_create_integer_literal( int i ) {
	expr_t *e = malloc(sizeof(*e));
	e->integer_value = i;
	e->kind = EXPR_INTEGER_LITERAL;
	return e;
}

type_t *type_create(type_kind_t kind, type_t *subtype, param_list_t *params) {
	type_t *t = malloc(sizeof(*t));
	t->kind = kind;
	t->subtype = subtype;
	t->params = params;
	return t;
}

param_list_t *param_list_create(char *name, type_t *type, param_list_t *next) {
	param_list_t *p = malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	p->next = next;
}

void printn(const char* input, int times) {
	for (int i = 0; i < times; i++) {
		printf("%s", input);
	}
}

void print_decl(decl_t *input, int num_indent) {
	if (input != NULL)  {
		printn("\t", num_indent);
		printf("Declaration\n", input);
		printn("\t", num_indent);
		printf("\tName: %s\n", input->name);
		print_type(input->type, num_indent + 1);
		print_expr(input->value, num_indent + 1);
		print_stmt(input->code, num_indent + 1);
		print_decl(input->next, num_indent);
	}
}

void print_stmt(stmt_t *input, int num_indent) {
	if (input != NULL) {
		printn("\t", num_indent);
		printf("Statement\n");
		print_stmt_kind(input->kind, num_indent + 1);
		print_decl(input->decl, num_indent + 1);
		print_expr(input->init_expr, num_indent + 1);
		print_expr(input->expr, num_indent + 1);
		print_expr(input->next_expr, num_indent + 1);
		print_stmt(input->body, num_indent + 1);
		print_stmt(input->else_body, num_indent + 1);
		print_stmt(input->next, num_indent);
	}
}

void print_type(type_t *input, int num_indent) {
	if (input != NULL) {
		printn("\t", num_indent);
		printf("Type\n");
		print_type_kind(input->kind, num_indent + 1);
		print_type(input->subtype, num_indent + 1);
	}
}

void print_expr(expr_t *input, int num_indent) {
	if (input != NULL) {
		printn("\t", num_indent);
		printf("Expression\n");
		print_expr_kind(input->kind, num_indent + 1);
		print_expr(input->left, num_indent + 1);
		print_expr(input->right, num_indent + 1);
		if (input->name != NULL) {
			printn("\t", num_indent + 1);
			printf("%s\n", input->name);
		}
		printn("\t", num_indent + 1);
		printf("%d\n", input->integer_value);
		if (input->string_literal != NULL) {
			printn("\t", num_indent + 1);
			printf("%s\n", input->string_literal);
		}
	}
}

void print_stmt_kind(stmt_kind_t kind, int num_indent) {
	printn("\t", num_indent);
	switch (kind) {
		case STMT_DECL: printf("stmt_declaration\n"); return;
		case STMT_EXPR: printf("stmt_expression\n"); return;
		case STMT_IF_ELSE: printf("stmt_if_else\n"); return;
		case STMT_FOR: printf("stmt_for\n"); return;
		case STMT_PRINT: printf("stmnt_print\n"); return;
		case STMT_RETURN: printf("stmnt_return\n"); return;
		case STMT_BLOCK: printf("stmnt_code_block\n"); return;
	}
}

void print_type_kind(type_kind_t kind, int num_indent) {
	printn("\t", num_indent);
	switch (kind) {
		case TYPE_VOID: printf("void\n"); return;
		case TYPE_BOOLEAN: printf("boolean\n"); return;
		case TYPE_CHARACTER: printf("character\n"); return;
		case TYPE_INTEGER: printf("integer\n"); return;
		case TYPE_STRING: printf("string\n"); return;
		case TYPE_ARRAY: printf("array\n"); return;
		case TYPE_FUNCTION: printf("function\n"); return;
	}
}

void print_expr_kind(expr_kind_t kind, int num_indent) {
	printn("\t", num_indent);
	switch (kind) {
		case EXPR_NAME: printf("name\n"); return;
		case EXPR_ADD: printf("addition\n"); return;
		case EXPR_SUB: printf("subtraction\n"); return;
		case EXPR_MUL: printf("multiplication\n"); return;
		case EXPR_DIV: printf("division\n"); return;
		case EXPR_INTEGER_LITERAL: printf("integer literal\n"); return;
		case EXPR_STRING_LITERAL: printf("string literal\n"); return;
	}
}