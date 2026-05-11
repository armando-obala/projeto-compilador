#pragma once
#include <string>
#include <map>
#include <iostream>

enum class DataType {
    INT,
    FLOAT,
    BOOL,
    STRING,
    UNKNOWN
};

std::string typeToString(DataType type);

class SymbolTable {
private:
    std::map<std::string, DataType> table;

public:
    SymbolTable() = default;

    // Retorna true se a variável foi inserida com sucesso, false se já existir
    bool declare(const std::string& name, DataType type);

    // Retorna o tipo da variável ou UNKNOWN se não existir
    DataType lookup(const std::string& name);

    // Verifica se a variável existe
    bool exists(const std::string& name);

    // Limpa a tabela
    void clear() { table.clear(); }
};

// Variável global para a tabela de símbolos
extern SymbolTable symTable;
