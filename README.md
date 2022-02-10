# GSP - EP2

Olá, dev! Esse é o repositório de um dos possíveis EPs que vocês podem fazer ao final do curso!

## Instruções gerais

* Vocês deverão escolher um dos EPs para fazer, este ou o [outro](https://github.com/guia-de-sobrevivencia-do-programador/EP1).
* Antes de escolher, dê uma olhada na lista de tarefas e veja qual possui os tópicos de seu interesse. Elas são diferentes para cada EP e alguns tópicos que cobrimos durante o curso podem não estar presentes em um ou outro.
* Escolhido o EP, você deve realizar todas as tarefas listadas, exceto as tarefas bônus (recomendamos as tarefas bônus sejam feitas também para reforçar o conteúdo do curso).
* Marque as tarefas realizadas no README.
* Crie um arquivo .zip contendo todo o código deste repositório (**não é necessário adicionar a pasta node_modules no zip**) com os arquivos adicionais das tarefas abaixo.

## Como gerar os arquivos de entrada e rodar o EP

Primeiro você precisa gerar os arquivos de entrada. Esses podem ser gerados utilizando o script `generate_input.sh`:

```bash
./generate_input.sh input1 input2 output
```

Depois você precisa compilar o programa. Ele já está compilando com as flags `-Og` e `-ggdb3` para melhor depuração. Compilando com `make` o executável `./merge_files` vai ser gerado:

```bash
make
```

Por ultimo, para rodar o programa você pode utilizar os mesmos argumentos passados para `./generate_input.sh` ao executável `./merge_files`:

```bash
./merge_files input1 input2 output
```

## Tarefas

- No código em `src/main.c`:
	- [ ] Arrumar o bug
	- [ ] Arrumar o memory leak
- No `generate_input.sh`:
	- [ ] Modificar o script para suportar múltiplos arquivos como entrada (em vez de somente 2)
- Com relação à performance:
	- Identificar gargalos de performance no programa quando...
		- [ ] tem vários arquivos pequenos como entrada, em varios diretórios diferentes
		- [ ] tem arquivos muito grandes como entrada
- Tarefas bônus:
	- No `Makefiles`:
		- [ ] Fazer um alvo e as configurações necessárias para rodar o `generate_input.sh` automaticamente
	- [ ] Utilizar um dos 3 editores de texto expostos nas aulas
	- [ ] Utilizar o GitHub para hospedar o EP e registrar o progresso em commits
	- [ ] Utilizar o recurso de CI/CD do GitHub para verificar bugs e memory leaks no código
