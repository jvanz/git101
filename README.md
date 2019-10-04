# git101

Esse repositório tem o intuito de ajudar as desenvolvedoras e desenvolvedores 
a entenderem o básico de 'git'. E talvez, algo a mais também! ;)

#### O que é git?
Git é um sistema de gerenciador de versões. Outros gerenciadores de versões 
disponiveis, como Subversion (SVN), Mercurial (HG), Bitkeeper e CVS.

#### O que é um sitema de gerenciador de versões?
Um sistema de gerenciamento de versões são ferramentas que auxiliam na 
colaboração entre usuário que estão trabalhando junto em um mesmo projeto
ou repositório. Git, como um uma dessa ferramentas permite que os usuário
possam acompanhar alterações em arquivos e compartilhar alterações com outros
usuários. Permitindo até o usário voltar a uma versão anterior dos arquivos.

https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control

#### Qual a diferença entre Git e os demais gerenciadores de versões?
Git é um gerenciador de versões distribuido. Isso significa que cada cópia 
de umrepositório contem todo os dados e meta dados para fazer qualquer 
comando. Isso é umas das principais diferenças entre ele e o SVN e CVS. 
Nesses gerenciadores de versão o usuário não é capaz de efetuar alguns 
comandos como submeter alterações nem visualizar o histórico de alterações 
sem uma conexão com o central.

Outra grande diferença entre o git e outros gerenciadores de versões é que ele
não armazena alterações. Ele "tira fotos" do estado de seu projeto. 
Em outros palavras, ao inves do git guardar as alterações dos arquivos entre 
uma versão e outra como é feito pelo SVN e similares. O guarda o estado de todo
o projeto. E quando não ha alterações no arquivos, ele faz apenas um link para
a versão identica anterior.

#### Remotes
No Git remotes são URI nos quais o git pode trazer ou mandar alterações, 
comparar versões, entre outras operações

#### O que é a "arvore de trabalho"?
É uma versão do projeto que foi tirada da base de dados do git e feita disponivel
para uso e modificação

#### Os tres estados de um arquivo no Git

- Modificado: TODO
- "Staged": TODO
- "Commited": TODO
![Estados de um arquivo](https://git-scm.com/book/en/v2/images/areas.png)

### O que é o `HEAD`?
`HEAD` é um ponteiro para o commit no qual as alterações feitas são baseadas.

#### O que é branch (ramos) ?
Podemos pensar em branches como linhas de desenvolvimento paralelas. Isso 
significa que em um mesmo repositório podemos estar desenvolvendo diversas
funcionalidade e correções sem que um afete a outra. 

#### O que é uma tag (etiqueta)?
Tags são referencias para commits no seu histórico. Elas servem para marcar pontos
importantes no desenvolvimento de seu projeto. Por exemplo, você pode usar etiquetas
para marcar as versões do programa.

#### O que é o diretório de trabalho?



Comandos
--------

Essa documentação tenta explicar como utilizar os comandos básicos do Git
através da linha de comando. Se você prefere uma interface gráfica existem 
algumas opções disponiveis na Internet. Porém, algumas informações que serão
ditas aqui podem auxiliar na utilização de tais programas.


### Criando seu repositório

#### git-init

`git init`

O comando git init server para inicializar um repositório `git` no diretorio local

#### git-clone

`git clone <url>`

Permite clonar um repositório existente. Quando o repositório é criado, o git
já adiciona um remote chamado 'origin' com a URL utilizada no comando clone.

### Adicionando e modificando seus arquivos

#### git-add

`git-add <path>`

O comando `git add` adiciona o arquivo no index, também chamada de "stage area". 
Com esse comando você está dizendo ao git o que vai submetido no próximo commit.
Ou seja, você especifica quais serão as proxímas alterações que serão gravadas 
na base de dados do git.

Coisas legais do `git add`:

- `--patch` ou `-p`: permite adicionar parcialmente as alterações de um arquivo.

#### git-status

`git status`

Mostra as diferenças entre o index e o commit `HEAD`, as diferenças entre a area
de "stage" e a arvore de trabalho. Bem como os arquivos que não estão sendo 
monitorados pelo git.

#### git-diff

`git diff`

Mostra as alterações entre commits, arvore de trabalho e index, entre branches 
e etc.

Parametros legais:

* `--check` : permite visualizar se você adiciou espaços em branco no final da linha,
no final do arquivo, antes de um <tab>, entre outras vericações que podem ser
habilitadas. Veja mais no man git-diff e man git-config
* `--word-diff` : ao inves que visualizar a linha que mudou, permite ver o que na
linha foi alterado.

#### git-commit

`git commit`

Grava as alterações que estão na area de "stage" na base de dados do repositório
O novo commit criado é colocado como filho do `HEAD` e o ponteiro do branch é
atualizado. Quando esse command é executado sem nenhum parametro, o edito padrão
configurado é aberto para que o usuário informa uma mensagem descrevendo a alteração

Parametros bacanas:

* `--all/-a`: Adiciona automaticamente no commit todos os arquivos alterados ou
removidos que ainda não foram adicionados na area de stage.
* `--message/-m`: Permite que o usuário defina a mensagem de commit no momento em que
o comando é executado. 
* `--amend`: substitui o ultimo commit do branch. Atenção! Cuidado para não fazer isso
em um commit que já foi publicado em algum remote. Outros usuário podem ter 
problemas quando você reescreve o histórico de commits.

#### git-reset

`git reset [<modo>] <commit>`

Reinicia o `HEAD` atual para o estado espeficiado. Um dos usos mais communs para 
esse comando é quando a desenvolvedora quer desfazer um commit. O git reset
possui 5 modos diferentes. Mas os 3 mais utilizados são:

* `--soft` : Não mexe no index ou na arvore que trabalho. Mas reinicia o `HEAD` para 
o <commit>. Faz com que todos os arquivos alterados fiquem como "Alterações a
serem comitadas", na area de stage.
* `--hard`: Reinicia o index e arvore de trabalho. Todas as alterações desde o 
<commit> são perdidas
* `--mixed` : Reinicia o index mas não a arvore de trabalho. Os arquivos alterados
são preservados mas não são marcados para commit. Essa é o modo padrão do comando

Existem mais alguns modos de utilização do git reset. Veja mais no man git-reset

#### git-rm

`git rm`

Remove arquivos do index ou da arvore de trabalho e do index. 

#### git-mv

`git mv <arquivo> <destino>`

Permite ao usuário mover ou renomear um arquivo. Se o mudança do local do arquivo,
o diretório de destino já deve estar presente. Ao fazer a renomeação ou mudança
de local, o index é atualizado.


### Ramificações e mesclagens

#### git-branch

`git branch [<nome>]`

O comando git branch permite ao usuário criar, listar e apagar branches no seu
repositório. Para listar os branches disponiveis repositório basta executar:

```
jvanz@earth:~/hackerspace/git101> git branch --list
  conceitos
* master
```

O branch marcado com o `*` é o branch atual.

Para criar novos branches pode ser executado o comando:

`git branch meu-branch [<ponto-de-inicio>]`

Esse comando cria um novo branch localmente com o nome especificado. Esse branch,
aponta para o mesmo commit do `HEAD`. Ou se especificado o <ponto-de-inicio>, o
branch apontara para o commit especificado. Note que ao criar o branch, o git
não troca automaticamente de branch. Para isso existe o comando git-checkout.

Para apagar um branch, basta chamar `git branch -d meu-branch`.

<!--
TODO - descrever mais sobre as opções do git-branch e como funciona.
Por exemplo:
  Explicar como fazer um branch baseado em um branch remoto.
  Explicar as opções -m e -c
-->

#### git-checkout

`git checkout`

Esse comando permite trocarmos de branches ou restaurar o diretório de trabalho.
Uma vez criado o branch, podemos usar o comando `git checkout meu-branch` para 
trocar de branch. Isso significa que o `HEAD` ira começar apontar para o comit no
topo do branch, atualiza o index e os arquivos no diretório de trabalho. 
Uma vez feito isso, os próximos commits serão adicionados no topo do branch recem
trocado. Alterações locais são mantidas para que possam ser comitadas no branch.

Outro possível uso do comando é para restaurar o diretório de trabalho. Para isso,
podemos rodar o seguinte comando:

`git checkout -- <path>`

Esse command faz com que as alterações do diretório de trabalho sejam descartadas.
Mas as mudanças que estão "staged" são mantidas. Porém, se o comando for um pouco
diferente, `git checkout HEAD -- <path>`, as alterações do index/stage também são
restauradas para a versão do `HEAD`. Note que `HEAD`, pode ser outro commit também.

#### git-merge

`git merge`

Unifica dois ou mais branches de desenvolvimento. O comando `git merge` eh 
utilizado para unificar linhas de desenvolvimento que estao ocorrendo em branches
separados em um unico branch. Por exemplo, vamos considerar o seguinte repositório:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline --graph --all
* d7d0092 (HEAD -> master) README.md
| * d603398 (soma) Soma
|/
* 9ae2dec Commit inicial
```

Note que estamos no branch master (O `HEAD` está apontando para o master). Para 
trazermos as alterações do branch `soma` para no branch master, executamos
`git merge soma`:

```
jvanz@earth:~/hackerspace/app> git merge soma
Merge made by the 'recursive' strategy.
 include/operacoes.hh |  2 ++
 main.cc              | 15 +++++++++++++--
 2 files changed, 15 insertions(+), 2 deletions(-)
 create mode 100644 include/operacoes.hh
```

Agora temos podemos ver o seguinte no `git log`:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline --graph --all
*   22186cb (HEAD -> master) Merge branch 'soma'
|\
| * d603398 (soma) Soma
* | d7d0092 README.md
|/
* 9ae2dec Commit inicial
```

O que aconteceu foi que o git pegou os commit no branch `soma` desde o commit
comum entre os dois branches, neste caso somente um commit (d603398) e 
re aplicou eles sobre o branch `master`. E criou um commit para marcar o merge.

#### git-log

`git log`

Permite visualizar o histórico de alterações. Com esse comando conseguimos
ver as mensagens de comit, o autor, data, alterações feitas e demais dados
do commit. Por exemplo:

```
jvanz@earth:~/hackerspace/git101> git log
commit 5e0b82b18d36ca16abe3ac90f90eb9bb4ee6b838 (HEAD -> master, origin/master, origin/HEAD)
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Tue Oct 1 22:35:55 2019 -0300

    README.md: git-branch e git-checkout

    Adiciona documentação sobre os comandos git-branch, utilizado para
    gerenciamento de branches. E git-checkout, usado para trocar de branch e
    restaurar o estado do diretório de trabalho

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

commit 511d09ef77f9ec8b4eb0c4c8e48080acb7181f6b
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Tue Oct 1 21:48:22 2019 -0300

    README.md: git-reset, git-commit, git-mv, git-rm

    Adiciona documentação básico sobre o comandos git-commit, git-reset,
    git-mv e git-rm

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>
```

Parametros legais:

* `--grep=<regex>`: mostra os commit no qual a mensagem de commit corresponda com
a expressão regular especificada.
* `--L <começo>,<final>:<arquivo>` ou `--L :<nome funcao>:<arquivo>` : permite acompanhar
as alterações de um range de linhas ou função de um arquivo.
* `--oneline`: Mostra apenas a versão reduzida do hash e o titulo do commit
* `--graph`: desenha uma representação gráfica da história dos commits.

#### git-tag

`git tag`

Adiciona, lista, apaga ou verifca tags. Para criar uma tag, basta executar o 
comando `git tag minha-tag [commit|objeto]`. Por exemplo:

```
jvanz@earth:~/containers/skopeo> git tag minha-tag HEAD
jvanz@earth:~/containers/skopeo> git tag minha-tag2 HEAD^1
jvanz@earth:~/containers/skopeo> git log --oneline
ee9e9df (HEAD -> master, tag: minha-tag, upstream/master, upstream/HEAD) Merge pull request #703 from marcov/fix-ostree-buildtags
0f1ded2 ostree: use both image and & storage buildtags
44bc4a9 (tag: minha-tag2) Merge pull request #701 from vrothberg/release
89d6d0c bump to v0.1.40-dev
```

Para listar todas as tags, basta rodar o command sem argumentos:

```
jvanz@earth:~/containers/skopeo> git tag
minha-tag
minha-tag2
v0.1.0
v0.1.1
v0.1.10
v0.1.11
v0.1.12
v0.1.13
v0.1.15
```

Para apagar um tag basta utilizar a flag `-d, --delete`:

```
jvanz@earth:~/containers/skopeo> git tag --delete minha-tag
Deleted tag 'minha-tag' (was ee9e9df)
```

#### git-revert

`git revert <commit>`

O comando `git revert` permite ao usuário reverter as alterações de um commit ou
uma série de commits. O que o comando faz é aplicar o patch reverso. Ou seja,
o que estava sendo adicionado no commit é removido e o que estava sendo removido
é adicionado novamente. 

Quando o commit é executado ele automáticamente já cria um commit desfazendo as 
alterações. Vejamos um exemplo. Suponha que temos o seguinte histórico:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --patch
commit 8a2de5b35a26b2d5f32c65b5bb9699f6429fb934
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 22:12:23 2019 -0300

    Subtração

    Adicionado um método que realiza a subtração de dois inteiros.

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

diff --git a/include/operacoes.hh b/include/operacoes.hh
index 89ad4d0..8d7dfdf 100644
--- a/include/operacoes.hh
+++ b/include/operacoes.hh
@@ -1,2 +1,3 @@

 int soma(int a, int b);
+int subtracao(int a, int b);
diff --git a/main.cc b/main.cc
index 9cafabc..d74daa3 100644
--- a/main.cc
+++ b/main.cc
@@ -7,6 +7,11 @@ int soma(int a, int b)
        return a + b;
 }

+int subtracao(int a, int b)
+{
+       return a - b;
+}
+
 int main(void)
 {
        auto resultado = soma(2,3);

commit 22186cbec76e0885bec3fa2e2605b53d0835a725
Merge: d7d0092 d603398
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:27:10 2019 -0300

    Merge branch 'soma'

commit d7d0092a153cda440d87a25ac2c1999ebed4d2a2
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:23:33 2019 -0300

    README.md

    Adicionando o arquivo README
    
    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

diff --git a/README.md b/README.md
new file mode 100644
index 0000000..f2e4d56
--- /dev/null
+++ b/README.md
@@ -0,0 +1 @@
+Aplicação utilizada no exemplo de como é possível usar git.
```

Se aplicarmos o seguinte comando:

`git revert 8a2de5b`

O resultado é:
```
jvanz@earth:~/hackerspace/app> git --no-pager log --patch
commit 5679b5d58f015440657979b8182563021eaab83b
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 22:15:54 2019 -0300

    Revert "Subtração"

    This reverts commit 8a2de5b35a26b2d5f32c65b5bb9699f6429fb934.

diff --git a/include/operacoes.hh b/include/operacoes.hh
index 8d7dfdf..89ad4d0 100644
--- a/include/operacoes.hh
+++ b/include/operacoes.hh
@@ -1,3 +1,2 @@

 int soma(int a, int b);
-int subtracao(int a, int b);
diff --git a/main.cc b/main.cc
index d74daa3..9cafabc 100644
--- a/main.cc
+++ b/main.cc
@@ -7,11 +7,6 @@ int soma(int a, int b)
        return a + b;
 }

-int subtracao(int a, int b)
-{
-       return a - b;
-}
-
 int main(void)
 {
        auto resultado = soma(2,3);

commit 8a2de5b35a26b2d5f32c65b5bb9699f6429fb934
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 22:12:23 2019 -0300

    Subtração

    Adicionado um método que realiza a subtração de dois inteiros.

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

diff --git a/include/operacoes.hh b/include/operacoes.hh
index 89ad4d0..8d7dfdf 100644
--- a/include/operacoes.hh
+++ b/include/operacoes.hh
@@ -1,2 +1,3 @@

 int soma(int a, int b);
+int subtracao(int a, int b);
diff --git a/main.cc b/main.cc
index 9cafabc..d74daa3 100644
--- a/main.cc
+++ b/main.cc
@@ -7,6 +7,11 @@ int soma(int a, int b)
        return a + b;
 }

+int subtracao(int a, int b)
+{
+       return a - b;
+}
+
 int main(void)
 {
        auto resultado = soma(2,3);

commit 22186cbec76e0885bec3fa2e2605b53d0835a725
Merge: d7d0092 d603398
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:27:10 2019 -0300

    Merge branch 'soma'

commit d7d0092a153cda440d87a25ac2c1999ebed4d2a2
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:23:33 2019 -0300

    README.md

    Adicionando o arquivo README
[...]
```

#### git-cherry-pick

`git cherry-pick <commit>`
 
O comando `git -cherry pick` permite ao usuário trazer as alterações de commits
e reaplica-los em cima do branch atual. Por exemplo, considere o seguinte 
histórico:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline --all --graph
* d7d0092 (HEAD -> master) README.md
| * d603398 (soma) Soma
|/
* 9ae2dec Commit inicial
```

Se executarmos o comando `git cherry-pick d603398` quando estamos no branch 
master, teremos o seguinte resultado:


```
jvanz@earth:~/hackerspace/app> git cherry-pick d603398
[master 56ee444] Soma
 Date: Thu Oct 3 21:21:25 2019 -0300
 2 files changed, 15 insertions(+), 2 deletions(-)
 create mode 100644 include/operacoes.hh
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline --all --graph
* 56ee444 (HEAD -> master) Soma
* d7d0092 README.md
| * d603398 (soma) Soma
|/  
* 9ae2dec Commit inicial
```

Note que o commit que selecionamos do branch `soma` foi aplicado no branch master.
São dois commits diferentes. Possuem hashes differentes. Porém, com as mesmas 
alterações.

#### git-format-patch

`git format-patch <commit>`

O comando `git format-patch` permite ao usuário gerar um ou vários arquivos 
de commits (patches). Por exemplo, se você quiser gerar patches dos últimos
dois commits do branch:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline
56ee444 (HEAD -> master) Soma
d7d0092 README.md
9ae2dec Commit inicial
jvanz@earth:~/hackerspace/app> git format-patch HEAD^^
0001-README.md.patch
0002-Soma.patch
jvanz@earth:~/hackerspace/app> ls
0001-README.md.patch  0002-Soma.patch  meson.build  README.md
```

Esses arquivos contem as alterações e as informações dos commits. Esses arquivos
podem ser enviados por e-mail ou alguma outra forma de comunicação e aplicado 
em outro repositório. Esse comando é geralmente utilizado por projetos que 
utilizam e-mail como principal forma de contribuição e comunicação. 

Os arquivos gerados pelo `git format-patch` podem ser aplicados novamente no 
repositório pelo comando `git am`

#### git-am

`git am`

O comando `git am` é utilizado para aplicar patches gerados a partir do 
comando `git format-patch`. Podem ser aplicados patches de um maildir, bem
como patches individuais. Podemos aplicar patches da seguinte forma:

```
jvanz@earth:~/hackerspace/app> git --no-pager log --oneline
9ae2dec (HEAD -> master) Commit inicial
jvanz@earth:~/hackerspace/app> git am < 0001-README.md.patch
Applying: README.md
jvanz@earth:~/hackerspace/app> git am < 0002-Soma.patch
Applying: Soma
jvanz@earth:~/hackerspace/app> git --no-pager log
commit 1dba6085844f47160eb3a0d0b06c0a9dbae63b3c (HEAD -> master)
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:21:25 2019 -0300

    Soma

    Adiciona um método para realizar soma de dois inteiros

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

commit 248bf1f3393aed80a472e2440889f37048f2272e
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:23:33 2019 -0300

    README.md

    Adicionando o arquivo README

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

commit 9ae2dec6377c1acbacb45c5c69662a62c50dd278
Author: José Guilherme Vanz <jvanz@jvanz.com>
Date:   Thu Oct 3 21:11:52 2019 -0300

    Commit inicial

    Adicionando arquivos iniciais

    Signed-off-by: José Guilherme Vanz <jvanz@jvanz.com>

```
Note que o commit resultante ao patch aplicado mantem o autor do patch.


