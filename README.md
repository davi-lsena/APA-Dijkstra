# Projeto APA - Algoritmo de Dijkstra em C

Este projeto faz parte do curso de Análise e Projeto de Algoritmos e tem como objetivo explorar temas avançados de algoritmos, implementando e comparando diferentes variantes do **Algoritmo de Dijkstra** e outros algoritmos de caminhos mínimos em problemas reais de rotas.

> ⚠️ **Observação:** O projeto ainda está em desenvolvimento. O tema final a ser abordado será sorteado entre as opções propostas pelo enunciado.

O código atual implementa a leitura de capitais brasileiras e suas fronteiras, armazenando as distâncias entre cidades e indicando se o trajeto envolve balsa. Esta estrutura servirá como base para a implementação e comparação de algoritmos de caminhos mínimos.

## Objetivo do Trabalho

1. Implementar o **Algoritmo de Dijkstra clássico**.  
2. Comparar com outras variantes e algoritmos (a definir conforme tema sorteado):  
  - Dijkstra com heap  
  - Bellman-Ford  
  - A* (A estrela)  
  - Aplicar em problemas reais de rotas urbanas e redes de backbone em telecomunicações.  
  - Explorar implementações paralelas (memória compartilhada ou GPU), se pertinente ao tema sorteado.

## Estrutura do Projeto

- **`main.c`**: Código principal com funções de leitura, armazenamento e impressão das cidades e fronteiras.
- **`capitais.txt`**: Arquivo de entrada com os dados das cidades e suas conexões.
- **Estruturas de Dados**:
  - `Cidade`: nome da cidade, UF e lista de fronteiras.
  - `Fronteira`: destino, distância, uso de balsa e ponteiro para próxima fronteira.

## Metodologia Atual

1. Leitura do arquivo `capitais.txt` linha a linha.
2. Processamento das linhas para separar nome da cidade, UF e fronteiras.
3. Armazenamento das informações em estruturas encadeadas (`Cidade` e `Fronteira`).
4. Impressão das cidades com suas fronteiras e informações de balsa.
5. Estrutura pronta para futura implementação dos algoritmos de caminhos mínimos.

## Como Compilar e Executar

1. Abra o projeto no **Code::Blocks**.
2. Compile (`F9`) e execute o programa.
3. O programa lê `capitais.txt` e imprime as cidades e suas conexões.

## Exemplo de Saída
```
Cidade: Manaus (AM)
-> PA : 500.00 km | Usa balsa:1
-> RO : 700.00 km | Usa balsa:1
-> TO : 600.00 km | Usa balsa:0
```

## Próximos Passos

- Implementar o algoritmo de Dijkstra completo.  
- Escolher o tema final (sorteado) e adaptar o projeto conforme o tema.  
- Comparar resultados com outras variantes de algoritmos e analisar métricas como tempo de execução e qualidade da solução.  
- Explorar cenários reais de aplicação, incluindo rotas urbanas e redes de telecomunicações.  
- Avaliar implementações paralelas, se aplicável.

## Referências

- Artigo base: [https://arxiv.org/pdf/2504.17033](https://arxiv.org/pdf/2504.17033)  
- Livros de Algoritmos e Estruturas de Dados (CLRS, Cormen et al.)  
- Documentação do C padrão e Code::Blocks
