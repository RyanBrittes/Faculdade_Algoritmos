# Atividade 01

| *** | *** |
| --- | --- |
| Aluno: | Ryan Ifran Brittes |
| Curso: | Engenharia da Computação |
| Professor: | Paulo Tiene |
| Disciplina | Algoritmos e Estrutura de Dados |

## Questão 01
Seu algoritmo deverá pedir ao usuário para fornecer o valor da sua hora e a quantidade de
horas trabalhadas no mês para o cálculo de salário do funcionário.
Após calcular o salário bruto do funcionário, calcule também os descontos de o do INSS,
Imposto de Renda (IR) e FGTS com base nas regras abaixo:
* O INSS corresponde a 10% do Salário Bruto
* O FGTS corresponde a 11% do Salário Bruto
* IR depende do valor salário bruto (conforme tabela abaixo):
* Salário Bruto até 1000 (inclusive) - isento
* Salário Bruto acima de 1000 desconto de 10%
* Para calcular o Salário Líquido você deve subtrair o Salário Bruto dos descontos. Vale
ressaltar que o FGTS não é descontado para o cálculo do salário líquido (é a empresa que
deposita).

## Exemplo:
Veja um exemplo de saída considerando as entradas:
* `Hora:` 15
* `Quantidade de Horas Trabalhadas:` 100

```
Salário Bruto: (15 * 100) --> R$ 1500,00
(-) IR (10%)              --> R$ 150,00
(-) INSS ( 10%)           --> R$ 150,00
FGTS (11%)                --> R$ 165,00
Total de descontos        --> R$ 300,00
Salário Liquido           --> R$ 1200,00
```
### Código:

* Importação de bibliotecas e declaração da função responsável pelo Cálculo do Salário:
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L1-L7

* Função responsável pelo cálculo do IR
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L9-L13

* Função responsável pelo cálculo do INSS 
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L9-L13

* Função responsável pelo cálculo do FGTS 
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L21-L25

* Função responsável pela chamada de outras funções e ordenação dos calculos para imprimir ao usuário o resultado dos valores
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L27-L57

* Função principal, sendo responsável por inicializar a lógica de funcionamento do código e chamada das funções.
https://github.com/RyanBrittes/Faculdade_Algoritmos/blob/d884d34fd5b99e08757bf66d631b049087f01d60/Atividade_01/Algoritmos_Atividade_01.c#L59-L65
