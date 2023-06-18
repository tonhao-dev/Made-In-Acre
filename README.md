## Repositório

Esse repositório tem por objetivo armazenar os problemas utilizados na fase de preparação da equipe Last Dance, a qual representará o IFAC na maratona de programação da SBC no ano de 2022.

<hr>

### Como executar o código

1. Crie uma pasta com o numero do problema
2. Crie o seu programa de resposta
3. Crie um arquivo chamado stdin, sem extensão
4. Agora, para executar o seu programa siga os seguintes passos:

##### C++

    $ cd 1242
    $ gcc main.cpp -lstdc++ -o main.o
    $ g++ -std=c++17 -O2 -lm -o ./main ./main.cpp
    $ (linux/mac) ./main < stdin > stdout
    $ (windows) type stdin | ./main > stdout


##### Python

    $ cd 1242
    $ (linux/mac) python3 main.py < stdin > stdout
    $ (windows) type stdin | py main.py > stdout


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
"C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 2, ColumnLimit: 0}"
```

<hr>

## Repositórios de problemas
- [cses](https://cses.fi/problemset/)
- [atcoder](https://atcoder.jp/)
