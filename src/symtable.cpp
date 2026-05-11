#include "symtable.h"

// Tabela de Símbolos Global
SymbolTable symTable;

std::string typeToString(DataType type) {
    switch(type) {
        case DataType::INT: return "int";
        case DataType::FLOAT: return "float";
        case DataType::BOOL: return "bool";
        case DataType::STRING: return "string";
        default: return "unknown";
    }
}

bool SymbolTable::declare(const std::string& name, DataType type) {
    if (table.find(name) != table.end()) {
        return false; // Variável já existe
    }
    table[name] = type;
    return true;
}

DataType SymbolTable::lookup(const std::string& name) {
    auto it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    return DataType::UNKNOWN;
}

bool SymbolTable::exists(const std::string& name) {
    return table.find(name) != table.end();
}
