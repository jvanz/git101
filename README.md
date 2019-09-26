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

A medida que o seu projeto vai crescendo mudanças vão acontecendo. Então chega
a hora que você altera o arquivo que já foi gravado anteriormente no repositório.
Uma vez alterado o arquivo, você pode visualizar as alterações utilizando o 
comando:

`git diff`

Esse comando mostra quais são as alterações feitas em relação ao que esta gravado
na base de dados. O `git-diff` possui várias opções que permite diferente tipos
de visualizações. Por exemplo, a flag `--word-diff` permite visualizar quais 
foram as palavras alteradas no arquivo. Mais uma vez, após feita a alteração,
você pode adicionar as alterações no index com git add, efetuar a alteração no
repositório com git commit e visualizar o hostórico de alterações com o git log.

Comforme o tempo vai passando, multiplas alterações podem serem feitas ao mesmo
tempo. Para evitar que uma alteração afeta a outra você pode ser branches (ou 
"ramos" no português). Isso é um conceito que também existe em outros controle 
de versão. Simplificando bastante, podemos dizer que branches são linhas de 
desenvolvimento paralelo no seu repositório.

Vamos dar um exemplo, digamos que você receba solicitações de duas novas 
funcionalidades no seu programa. Mas para evitar que uma alteração causa bug
na outra, você utiliza branches. Assim cada uma pode ir avançando independente 
e sem causar problemas uma na outra. Vamos como fazermos isso na pratica.

Todo repositório tem um branch padrão. Geralmente chamada do master. Quando 
você iniciou a adicionar arquivos e commitar, você estava adicionando alterações
no branch master. Agora que queremos criar outros branches, podemos executar o 
command:

`git branch funcionalidade1`

Vamos ver se o branch foi criado:

```
git branch --list
  funcionalidade1
* master
```

Note que o `*` indica o branch atual. Não se esqueça que podemos ver que o 
o branch pelo 'git-log':

```
git log --oneline
9043d17 (HEAD -> master, origin/master, origin/HEAD, funcionalidade1) README.md: documentação de comandos básicos
2aeb99b .gitignore: adiciona o arquivo
38d8d45 meson: adicionando arquivo de build
c2ec518 main.cc: imprime resultado de operações matematicas
7930238 Adiciona uma função de subtração
565b76a Adiciona uma função de multiplicação
3bcd17e Adiciona a função soma
59d71e0 main.cc: adicionando arquivo com função main
1e77941 Initial commit
```

Veja as informações que estão antes do titulo do último commit. Isso mostra 
em quais branches esse commit esta. O 'HEAD' que pode ser visto, é apenas um 
pointeiro para indicar qual eh o branch atual que está sendo utilizado. Neste
caso, é o master. Como tinhamos visto no 'git branch --list' anteriormente.
Note também que ambos o branches 'master' e 'funcionalidade1' estão no mesmo
commit. Isso acontece porque branch recem criado vai sempre apontar para o 
commit que o HEAD esta apontando. Podemos dizer então que branches são ponteiros
para uma sequencia de commits.

Legal, agora que jah criamos nosso branch temos que mudar de branch. Ou seja, 
preciamos fazer que o ponteiro 'HEAD' aponte para o branch 'funcionalidade1'.
Fazemos isso utilizando o command 'git-checkout'

```
jvanz@earth:~/hackerspace/git101> git checkout funcionalidade1
Switched to branch 'funcionalidade1'
jvanz@earth:~/hackerspace/git101> git branch --list
* funcionalidade1
  master
```

Ótimo! Agora podemos começar a codificação da nova funcionalidade sem afetar 
outros branches, como o master. Nessa nova funcionalidade, a desenvolvedora,
adicionou alterou os arquivos do projeto e comitou. Maravilha, uma alteração
simples. Nessa hora podemos ver as alterações feitas estão em outra "linha do
tempo":

```
git log --oneline
55575ae (HEAD -> funcionalidade1) README.md: git-diff, git-branch
9043d17 (origin/master, origin/HEAD, master) README.md: documentação de comandos básicos
2aeb99b .gitignore: adiciona o arquivo
38d8d45 meson: adicionando arquivo de build
c2ec518 main.cc: imprime resultado de operações matematicas
7930238 Adiciona uma função de subtração
565b76a Adiciona uma função de multiplicação
3bcd17e Adiciona a função soma
59d71e0 main.cc: adicionando arquivo com função main
1e77941 Initial commit
```

Outra forma legal de visualizar é utilizando a flag '--graph'

'''
* 77aaa73 (HEAD -> master) resumo.md: arquivo com explicação resumida dos commandos
| * d3677f8 (funcionalidade1) README.md: git-diff, git-branch
|/
* 9043d17 (origin/master, origin/HEAD) README.md: documentação de comandos básicos
* 2aeb99b .gitignore: adiciona o arquivo
* 38d8d45 meson: adicionando arquivo de build
* c2ec518 main.cc: imprime resultado de operações matematicas
* 7930238 Adiciona uma função de subtração
* 565b76a Adiciona uma função de multiplicação
* 3bcd17e Adiciona a função soma
* 59d71e0 main.cc: adicionando arquivo com função main
* 1e77941 Initial commit
'''



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
