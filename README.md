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
    $ g++ -std=c++17 -O2 -lm -o ./main ./main.cpp
    $ ./main < stdin > stdout


##### Python

    $ cd 1242
    $ python3 < stdin > stdout


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
