## Repositório

Esse repositório tem por objetivo armazenar os problemas utilizados na fase de preparação da equipe Last Dance, a qual representará o IFAC na maratona de programação da SBC no ano de 2022.

<hr>

### Como executar o código

1. Crie uma pasta com o numero do problema
2. Crie o seu programa de resposta
3. Crie um arquivo chamado stdin.txt
4. Agora, para executar o seu programa siga os seguintes passos:

##### C++

    $ cd 1242
    $ gcc main.cpp -lstdc++ -o main.o
    $ g++ -std=c++17 -O2 -lm -o ./main ./main.cpp
    $ (linux/mac) ./main < stdin.txt > stdout.txt
    $ (windows) type stdin.txt | ./main > stdout.txt


##### Python

    $ cd 1242
    $ (linux/mac) python3 main.py < stdin.txt > stdout.txt
    $ (windows) type stdin.txt | py main.py > stdout.txt


### Pós-Accepted

Agora, você deve commitar as suas alterações e subir para o repositório

    git add .
    git commit -m "sua mensagem"
    git push

<hr>


### Visual Studio Code

Link para o formatter do c++, caso queira editar as configurações de code-format style do seu editor
[Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)

Exemplo
```cpp
if (condition == true)
{
  DoStuff();
}
```

```cpp
if (condition == true) {
  DoStuff();
}
```

_Uma estilização rápida para que as chaves não quebrem a linha é a seguinte_
```json
Settings (JSON)
"C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}"
```

<hr>

## Repositórios de problemas

- [cses](https://cses.fi/problemset/)
- [atcoder](https://atcoder.jp/)
- [UNESP LPC](https://github.com/pedropaiola/unesp-progcomp)
- [beecrowd](https://www.beecrowd.com.br/judge/pt)
- [codeforces](https://codeforces.com/)


## Material

1. [Merge Markdown](https://github.com/knennigtri/merge-markdown)
2. [md-to-pdf](https://github.com/simonhaenisch/md-to-pdf)
3. [markdown-toc](https://github.com/jonschlinkert/markdown-toc)

Merge Markdown

    cd Material
    merge-markdown -m .\ -o material

Markdown Table Of Content

    markdown-toc -i .\merged\Material.out.md

Markdown to PDF

    md-to-pdf .\merged\Material.out.md


