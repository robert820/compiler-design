#ifndef AST_H
#define AST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SymbolTable.h>
typedef enum ast_node_type_e
{
    program,
    func_def,
    func_arg,
    func_arg,
    func_body,
    const_dec,
    var_dec,
    arr_dec,
    id,
    assign,
    func_invo,
    func_invo_args,
    arr_assign,
    ast_print,
    ast_println,
    ast_read,
    ast_return,
    operation,
    condition,
    for_loop,
    block,
    integer_literal,
    real_literal,
    string_literal,
    null,
    things,
    thing
} ast_node_type_t;
typedef enum ast_operatr_value_e
{
    OPERATR_VALUE,
    operatr_unary,
    operatr_not,
    operatr_exponent,
    operatr_multiply,
    operatr_divide,
    operatr_remainder,
    operatr_add,
    operatr_subtract,
    operatr_equal_to,
    operatr_not_equal_to,
    operatr_greater_than,
    operatr_less_than,
    operatr_greater_than_or_equal_to,
    operatr_less_than_or_equal_to,
    operatr_binary_and,
    operatr_binary_or,
    operatr_logical_and,
    operatr_logical_or
} ast_operatr_value_t;
typedef enum ast_node_value_type_e
{
    identifier, /* for ids */
    operatr,    /* for operations */
    integer,    /* for interger literals */
    string      /* for real or string literals */
} ast_node_value_type_t;
typedef union ast_node_value_u
{
    LinkedList *identifier;
    ast_operatr_value_t operatr;
    int integer;
    const char *string;
} ast_node_value_t;
typedef struct ast_node_s
{
    /* Node type */
    ast_node_type_t type;
    /* Child and sibling */
    struct ast_node_s *child, *sibling;
    /* Const value, variable name or operation */
    bool has_value;
    ast_node_value_type_t value_type;
    ast_node_value_t value;
    /* Source map */
    int source_line_num;
    int source_column_num;
} ast_node_t;

#endif