# git101

Esse repositório tem o intuito de ajudar as desenvolvedoras e desenvolvedores 
a entenderem o básico de 'git'. E talvez, algo a mais também! ;)

Criando seu repositório
----------------------

### git-init

`git init`

O comando git init server para inicializar um repositório `git` no diretorio local

- Adicionando seu primeiro arquivo

`git add main.cc`

O comando `git-add` é utilizado para adicionar arquivos no index. Deixando os 
arquivos com o status de 'staged'. Ou dizemos que o arquivo esta na area de 'stage'. 
Em outros palavras, é com esse comando que você diz ao 'git' quais são os 
arquivos que devem ser gravados no repositório no próximo commit.

A opção '--patch' do 'git-add' também permite a desenvolvedora adicionar 
partes do arquivo no index. Isso permite a desenvolvedora selecionar apenas as
alterações relacionadas do arquivos. Sem a necessidade de poluir o commit com
alterações não necessárias.

`git commit`

Quando o comando `git-commit` é executado o git grava todas as alterações que 
estão 'staged' ou na area de 'stage' e grava na base de dados, no repositório.

`git log`

Agora que as alterações estão gravadas no repositório, você pode visualizar o
histórico de alterações com o comando 'git-log'. Esse comando permite ver todas
as alterações já gravadas em seu repositório.

- Alterando seu primeiro arquivo
	- `git-diff`
- Visualizando seu histórico
	- `git-log`
- Criando branches
	- `git-branch`
- Unificando seus branches
	- `git-rebase`
	- `git-merge`
- Criando e aplicando patches
	- `git-format-patch`
	- `git-am`
- Guardando alterações não terminadas
	- `git-stash`
- Encontrando um bug
	- `git-bisect`
- Quero um comando para chamar de meu
	- `git-meu-command`

Compartilhando codigo
--------------------

`git-clone`
Github
Gitlab

Coisas legais a se saber
-----------------------

Hooks
`git-revisions`
