DIRECTORY=.
STDINS=$(find . -maxdepth 1 -name "stdin*" -print)
for stdin in $STDINS; do
    $(g++ main.cpp -o main && ./main < $stdin > "stdout${stdin: -1}")
done
