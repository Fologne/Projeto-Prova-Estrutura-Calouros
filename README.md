# 📒 Agenda de Contatos em C

## 📘 Descrição
Este projeto implementa uma **agenda de contatos** em linguagem **C**, utilizando:
- **Lista encadeada** para armazenar os contatos;
- **QuickSort** para ordenar os contatos por nome;
- **Árvore binária de busca (BST)** para realizar buscas rápidas;
- Um menu interativo em terminal para cadastrar, listar, buscar e ordenar contatos.

Cada contato possui:
- **ID**
- **Nome**
- **Telefone**
- **E-mail**
- **Cidade**
- **Estado**

---

## 🧩 Estrutura de Arquivos
📂 Projeto

├── bst.h # Declarações e funções relacionadas à árvore binária de busca

├── funcoes.c # Implementação das funções principais (cadastro, busca, listagem, etc.)

├── funcoes.h # Cabeçalhos das funções gerais

├── main.c # Arquivo principal (contém a função main e o menu inicial)

├── menu.c # Implementação do sistema de menu

├── menu.h # Cabeçalho do menu

├── ordena.c # Implementação do QuickSort e outras rotinas de ordenação

├── ordena.h # Cabeçalho do módulo de ordenação

├── struct.h # Definição das structs principais (Node, Contato, etc.)

└── main.exe # Executável gerado após a compilação


---

## ⚙️ Compilação

Para compilar o programa, utilize o **GCC** (compilador padrão de C).  
Execute o seguinte comando no terminal dentro da pasta do projeto:

```bash
gcc main.c funcoes.c menu.c ordena.c -o main.exe
```
Para executar o programa execute o seguinte comando no terminal dentro da pasta do projeto:
```bash
./main.exe
```

🧠 Funcionalidades Principais

➕ Cadastrar contato	Adiciona um novo contato à lista encadeada.

📜 Listar contatos	Mostra todos os contatos cadastrados.

🔍 Buscar contato	Usa uma árvore binária de busca (BST) para localizar contatos rapidamente pelo nome.

🧮 Ordenar contatos	Utiliza o QuickSort para ordenar os contatos pelo nome.

💾 Salvar/Carregar	(Opcional) Salva os contatos em arquivo e carrega ao iniciar.


🧱 Estruturas de Dados Utilizadas
Lista Encadeada (Node)
```
typedef struct no {
    int id;
    char nome[41];
    char telefone[13];
    char email[41];
    char cidade[41];
    char estado[3];
    struct no *next;
} Node;
```
Árvore Binária de Busca (BST)
```
typedef struct bst {
    char nome[41];
    Node *ref;              
    struct bst *left;
    struct bst *right;
} BST;
```

🧩 Ordenação com QuickSort

O algoritmo de QuickSort é utilizado para ordenar os contatos com base no campo nome.
A ordenação é feita diretamente sobre o vetor de ponteiros para Node, preservando a estrutura da lista.

🕹️ Exemplo de Execução
```
Digite
1- Cadastrar Contato
2- Listar Contatos
3- Buscar Contato
4- Ordenar Contatos
0- Sair

Digite a opção desejada: 3
Digite o nome do contato que deseja buscar: Gabriel
Contato encontrado!
Nome: Gabriel Foloni
Telefone: (99)99999-9999
Email: gabriel@email.com
Cidade: Cuiabá
Estado: MT
```
👨‍💻 Autor

**[Gabriel Foloni](https://github.com/Fologne)**

Projeto desenvolvido para fins acadêmicos.

🧰 Requisitos

- Compilador GCC (ou compatível)

- Sistema operacional Windows, Linux ou macOS

- Terminal com suporte a entrada/saída padrão (stdin/stdout)
