Jogo Snake desenvolvido para a disciplina Estrutura de Dados, ministrada pelo professor Geraldo Braz Junior, do curso de Ciência da Computação da Universidade Federal do Maranhão, como parte da avaliação da primeira unidade. 

O jogo consiste em uma cobra numa tela 30x30 células que deve comer as frutas ao longo do jogo até alcançar a pontuação máxima (900 frutas) ou tamanho abaixo do mínimo (0 células).

As operações de crescimento e redução da cobra respeitam a lógica da estrutura fila de dados(primeiro a entrar na estrutura é o primeiro a sair dela).

**Como jogar:**
A cobra deve comer as frutinhas que aparecem na tela (Só aparece uma quando a anterior deixa de existir) e evitar as paredes. Cada vez que há colisão com os limites da tela do jogo a cobra perde 5 células e se seu tamanho for menor ou igual a 0 células, o jogo termina com a pontuação correspondente ao maior tamanho alcançado. O jogo também acaba se a pontuação/tamanho máximo (900 células) for atingido com uma mensagem especial de vitória.

w, a, s, d - são as teclas que movimentam a cobra para cima, esquerda, baixo e direita respectivamente. Se a cobra estiver indo para cima, ela não poderá virar para baixo e se estiver indo para a esquerda, não poderá ir para a direita, e vice-versa.

q - termina a execução do jogo

**Problemas**
- A identificação das teclas pressionadas ocorre apenas em um momento muito específico do loop do jogo, isso faz com que o movimento da cobra só aconteça se a tecla for apertada no momento certo, por isso, às vezes o jogador deverá apertá-la várias vezes até que a direção do movimento mude.
-
