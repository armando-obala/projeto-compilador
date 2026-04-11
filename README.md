# Projeto: Construção de um Compilador Didático

![Status](https://img.shields.io/badge/Status-Em_Desenvolvimento-yellow)
![Nível](https://img.shields.io/badge/Posi%C3%A7%C3%A3o-S%C3%AAnior-blue)
![Referência](https://img.shields.io/badge/Ref-Compiladores_para_Humanos-orange)

## 📝 Contexto do Projeto
Este projeto foi concebido sob a liderança de um desenvolvedor sênior para a criação de um compilador didático funcional. O foco principal é a aplicação prática da teoria de compiladores, utilizando como base a estrutura conceitual do guia **Compiladores para Humanos**.

---

## 🎯 Objetivo
Desenvolver um compilador completo capaz de:
1. Ler um programa fonte em linguagem simplificada.
2. Realizar as fases de análise (Léxica, Sintática e Semântica).
3. Gerar código intermediário ou objeto para uma plataforma alvo (ex: JVM ou máquina de teste).

---

## 🏗️ Escopo e Entregáveis

### 1. Definição da Linguagem
* **Gramática:** Especificação formal via **EBNF**.
* **Regras:** Definição de tipos de dados, operações, variáveis e estruturas de controle.

### 2. Frontend do Compilador
* **Analisador Léxico:** Produção de tokens.
* **Analisador Sintático:** Construção da Árvore Sintática Abstrata (**AST**).
* **Análise Semântica:** Verificação de tipos e regras de escopo.
* **Gestão de Erros:** Mensagens significativas para falhas em qualquer fase.

### 3. Backend do Compilador
* **Geração de Código:** Criação de código alvo (Assembly, Bytecode ou similar) a partir da AST.
* **Execução:** O código deve ser transformável em executável por um assembler ou interpretador.

### 4. Ferramentas de Apoio
* Justificativa de ferramentas (JavaCC, ANTLR, Flex/Bison, etc.).
* Uso recomendado de geradores de analisadores para agilizar o desenvolvimento.

---

## 🛠️ Requisitos Técnicos (Normativos)

* **Documentação:** Módulos, interfaces e diagramas de fases.
* **Correção Funcional:** Tradução fiel de programas válidos e identificação de inválidos.
* **Qualidade:** Mensagens de erro claras, código modular e manutenível.

---

## 💡 Exemplo de Aplicação (Caso de Uso)
O compilador deve ser capaz de processar um programa que contenha:
* Declaração de variáveis.
* Estrutura condicional (`if/else`).
* Laço de repetição (`while`).
* Operações aritméticas/lógicas e impressão de saída (`print`).

---

## 📚 Referências Obrigatórias
* [Compiladores para Humanos](https://johnidm.gitbooks.io/compiladores-para-humanos) - Referência principal para fases e representações.

---
> **Nota:** Este documento serve como guia de implementação para garantir que todos os critérios de avaliação sejam atendidos.

---

## Configuração do Ambiente (Windows)

Este projeto usa Flex + C++ e foi validado em Windows com winflexbison e MSYS2 (UCRT64).

### Dependências

1. win_flex disponível no terminal (ex.: via winflexbison).
2. g++ do MSYS2 instalado (UCRT64).

Verificação rápida:

```powershell
win_flex --version
g++ --version
```

Se `g++` não for encontrado no PowerShell/CMD comum, ele pode estar instalado apenas dentro do shell do MSYS2.

### Caminho recomendado para o g++

Instalação validada neste projeto:

```text
C:\msys64\ucrt64\bin\g++.exe
```

Opcional (recomendado): adicionar `C:\msys64\ucrt64\bin` ao PATH do Windows para usar `g++` em qualquer terminal.

### Como compilar

Na pasta do projeto:

```powershell
.\compila.bat
```

O script `compila.bat` já tenta:

1. Usar `g++` do PATH.
2. Se não encontrar, usar `C:\msys64\ucrt64\bin\g++.exe` automaticamente.

### Como executar

Modo arquivo (recomendado para teste inicial):

```powershell
.\compilador.exe tests\programa.src
```

Modo interativo:

```powershell
.\compilador.exe
```

Saída do modo interativo no Windows: `Ctrl+Z` e depois `Enter`.

### Quando o executável "não abre"

Se o `compilador.exe` fecha sem saída no CMD/PowerShell, normalmente faltam DLLs do runtime do MSYS2 no PATH da sessão.

Teste temporário no PowerShell:

```powershell
$env:Path = "C:\msys64\ucrt64\bin;$env:Path"
.\compilador.exe tests\programa.src
```

Teste temporário no CMD:

```bat
set PATH=C:\msys64\ucrt64\bin;%PATH%
.\compilador.exe tests\programa.src
```

Se funcionar após isso, a correção definitiva é adicionar `C:\msys64\ucrt64\bin` ao PATH do Windows.
