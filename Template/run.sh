DIRECTORY=.
STDINS=$(find . -maxdepth 1 -name "stdin*" -print)
for stdin in $STDINS; do
    TEST_NUMBER=${stdin: -1}
    PROGRAM_OUTPUT=$(g++ main.cpp -o main && ./main < $stdin)
    EXPECTED_OUTPUT=$(cat "stdout${TEST_NUMBER}")

    if [ "$EXPECTED_OUTPUT" = "$PROGRAM_OUTPUT" ]; then
        printf "Test Case $TEST_NUMBER are correct.\n"
    else
        printf "Test Case $TEST_NUMBER are **INCORRECT**.\n"
        echo "$PROGRAM_OUTPUT" | tee "out$TEST_NUMBER"
    fi
done
