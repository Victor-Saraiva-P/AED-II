#!/usr/bin/env bash
mkdir -p tests

# ── PRE-ORDER ───────────────────────────────────────────────────────────────────
cat > tests/pre_input.txt <<'EOF'
1
8
1
4
1
12
1
2
1
6
1
10
1
14
2
99
EOF
echo '[8][4][2][6][12][10][14]' > tests/pre_output.txt

# ── IN-ORDER ────────────────────────────────────────────────────────────────────
cat > tests/in_input.txt <<'EOF'
1
50
1
30
1
70
1
20
1
40
1
60
1
80
3
99
EOF
echo '[20][30][40][50][60][70][80]' > tests/in_output.txt

# ── POST-ORDER ──────────────────────────────────────────────────────────────────
cat > tests/post_input.txt <<'EOF'
1
5
1
3
1
8
1
1
1
4
1
7
1
9
4
99
EOF
echo '[1][4][3][7][9][8][5]' > tests/post_output.txt

# ── qtdFolhas — árvore vazia ───────────────────────────────────────────────────
cat > tests/folhas_vazio_input.txt <<'EOF'
6
99
EOF
echo '0' > tests/folhas_vazio_output.txt

# ── qtdFolhas — árvore balanceada (4 folhas) ───────────────────────────────────
cat > tests/folhas_bal_input.txt <<'EOF'
1
10
1
5
1
15
1
3
1
7
1
12
1
18
6
99
EOF
echo '4' > tests/folhas_bal_output.txt

# ── qtdFolhas — árvore degenerada (1 folha) ────────────────────────────────────
cat > tests/folhas_deg_input.txt <<'EOF'
1
5
1
4
1
3
1
2
1
1
6
99
EOF
echo '1' > tests/folhas_deg_output.txt
