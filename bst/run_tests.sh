#!/bin/bash

# Compilar o código (se necessário)
# gcc -o main main.c bst.c

for i in {1..6}
do
  echo "Executando teste t$i..."
  ./main < t${i}_input.txt > saida_t${i}.txt

  echo -n "Comparando com saída esperada... "
  if diff -q saida_t${i}.txt t${i}_output.txt > /dev/null; then
    echo "✅ OK"
  else
    echo "❌ Diferente"
    echo "Esperado:"
    cat t${i}_output.txt
    echo "Obtido:"
    cat saida_t${i}.txt
  fi

  echo ""
done
