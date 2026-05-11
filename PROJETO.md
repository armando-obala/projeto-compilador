Projeto: Construção de um Compilador Didático
Contexto
Você foi contratado como desenvolvedor sênior para liderar um projeto interno de criação de um compilador
didático para uma linguagem de programação simples. O objetivo principal é aplicar conceitos de teoria e
prática de compiladores conforme os estudos apresentados no Compiladores para Humanos, desenvolvendo
um compilador funcional para uma linguagem definida por você. (johnidm.gitbooks.io)
Objetivo do Projeto
Desenvolver um compilador completo que:
1. Leia um programa fonte escrito em uma linguagem de programação simplificada;
2. Analise lexicamente os tokens;
3. Analise sintaticamente a estrutura do programa;
4. Realize análise semântica básica;
5. Gere código intermediário ou objeto para uma plataforma alvo definida (por exemplo, JVM ou
máquina de teste específica). (johnidm.gitbooks.io)
Escopo e Entregáveis
1. Definição da Linguagem
• Especificar formalmente a gramática da linguagem usando EBNF.
• Definir os tipos de dados, operações, declarações de variáveis, estruturas de controle e
operadores básicos.
• Entregar um documento que descreva a gramática e as regras de sintaxe. (johnidm.gitbooks.io)
2. Frontend do Compilador
• Analisador Léxico: produzir tokens a partir do código fonte.
• Analisador Sintático: construir uma estrutura de árvore sintática abstrata (AST).
• Análise Semântica: verificar coerência de tipos e regras de escopo.
• Implementar validação de erros léxicos, sintáticos e semânticos com mensagens significativas.
(johnidm.gitbooks.io)
3. Backend do Compilador
• Geração de Código: criar código alvo (Assembly simples, bytecode JVM ou outra forma definida) a
partir da AST.
• O código alvo deve ser executável ou transformável para executável por um assembler/interpretador.
(johnidm.gitbooks.io)
4. Ferramentas de Apoio
• Justificar a escolha de ferramentas (ex.: JavaCC, JFlex, CUP, ANTLR, Flex/Bison, etc.).
• O uso de geradores de analisadores léxicos e sintáticos é fortemente recomendado para agilizar a
implementação. (johnidm.gitbooks.io)
5. Testes
• Conjunto de programas voz definidos para testar cada fase do compilador.
• Testes de regressão para assegurar que alterações não quebrem outras partes do compilador.
Requisitos Técnicos (Normativos)
A. Documentação Técnica
• Descrever arquitetura do compilador: módulos e interfaces.
• Diagrama de fases (análise, semântica, geração de código).
• Especificação da gramática em EBNF ou formato compatível com a ferramenta escolhida.
B. Critérios de Qualidade
• Correção Funcional: compilador deve traduzir programas válidos sem erros e identificar programas
inválidos.
• Mensagens de Erro Claras: feedback para erros léxicos, sintáticos e semânticos deve ser
compreensível e informativo.
• Modularidade e Manutenibilidade: usar boas práticas de engenharia de software para permitir
evolução futura.
Cronograma Sugerido
Fase Atividades Semana
1 Levantamento do escopo e definição da linguagem 1
2 Projetar a gramática e preparar ambiente de desenvolvimento 2
3 Implementação do analisador léxico 3–4
4 Implementação do analisador sintático 5–6
5 Desenvolvimento da análise semântica 7–8
6 Backend: geração de código 9–10
7 Testes integrados 11
8 Documentação e entrega final 12
Critérios de Avaliação
1. Funcionalidade Completa do Compilador
o Suporta as construções definidas na gramática.
o Produz saída correta para todos os testes válidos.
2. Qualidade da Implementação
o Uso apropriado de geradores de analisadores.
o Arquitetura modular.
3. Documentação
o Gramática corretamente especificada.
o Relatórios de testes e logs de erros.
4. Desempenho e Usabilidade
o O compilador deve ser capaz de compilar programas de forma adequada sem travamentos.
Exemplo de Aplicação (Caso de Uso)
Desenvolver um pequeno programa na linguagem alvo que implemente:
• Declaração e uso de variáveis;
• Estrutura condicional (if/else);
• Laço while;
• Operações aritméticas e lógicas;
• Impressão de saída.
O compilador deve gerar um código executável ou equivalente para esse exemplo, provando a sua operação
completa desde a leitura do código fonte até a geração de código objeto. (johnidm.gitbooks.io)
Referências Obrigatórias
Você deve utilizar o conteúdo e a estrutura conceitual do Compiladores para Humanos como principal
referência teórica, sobretudo para entendimento de fases, representação e ferramentas. (johnidm.gitbooks.io)
Outras referências podem ser incluídas conforme necessidade, desde que citadas adequadamente.