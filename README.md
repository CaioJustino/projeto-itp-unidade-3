# PROJETO - ITP - UNIDADE 3

O presente projeto consiste em dois programas: um "encoder" para gerar uma imagem no formato PBM com um código de barra no padrão EAN-8 (representando um determinado identificador), e um "decoder" para extrair o identificador representado na imagem.
<br><br>

## Configuração e Instalação
<br>

1. Clone este repositório em sua máquina local.

```
git clone [https://github.com/<>](https://github.com/CaioJustino/projeto-itp-unidade-3.git)
```
<br>

2. Navegue até a pasta do projeto.

```
cd projeto-itp-unidade-3
```
<br>

3. Em seguida, execute o comando `gcc` (GNU Compiler Collection) para compilar cada um dos programas separadamente, gerando arquivos executáveis para ambos.

```
gcc -o Encoder Encoder.c Utils.c
```

```
gcc -o Decoder Decoder.c Utils.c
```
<br>

4. Se preferir, outro compilador pode ser utilizado.
## Execução
<br>

1. A princípio, na linha de comando, insira os argumentos abaixo para gerar a imagem com o código de barras. Lembre-se que os parâmetros de Espaçamento lateral, Largura e Altura das barras são opcionais.

```
./Encoder <Identificador EAN-8> <Arquivo de Saída .pbm> [Espaçamento (Opcional)] [Largura (Opcional)] [Altura (Opcional)]
```

```
Exemplo: ./Encoder 40170725 barcode.pbm 4 3 50
```
<br>

2. Se o identificador for válido, a imagem será gerada e já será possível extrair o identificador do seu código de barras.

```
./Decoder <Nome do Arquivo da Imagem>
```

```
Exemplo: ./Decoder barcode.pbm
```
<br>

3. Por fim, o programa irá retornar a sequência binária que foi decodificada e o identificador extraído.

<br>
Discentes: Caio Justino e Júlia Lima
