## Rodar o input

```bash
gcc -Wall -O2 -o main main.c rb.c
./main < input.txt
```

## Fazer testes

```bash
gcc -Wall -O2 -o main main.c rb.c
./main < testes/input_teste.txt > testes/saida.txt
diff -u testes/gabarito.txt testes/saida.txt
```