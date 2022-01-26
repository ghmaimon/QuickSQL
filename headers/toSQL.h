#ifndef TO_SQL_H_
#define TO_SQL_H_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "data.h"
#include "utils.h"

void generateSQL();
void generateTables();
void generateViews();
void generateTable(Table table);
void generateView(View view);
void generateColumns(Table table);
void generateColumn(char* tableName,Column column,int isLastCol);
void generateConstraints(char* tableName,Column column);
void generateConstraint(char* tableName,char* columnName,ColumnDirective columnDirective);
int hasPrimaryKey(Table table);
int isPrimaryKey(Column column);
int isForeightKey(Column column);

void putString();
void putInt();

FILE* sqlFile;

#endif