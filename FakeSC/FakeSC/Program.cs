﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FakeSC
{
    /* Legenda de variáveis:
     * largObj -> largura do objeto (plano de distribuição)
     * compObj -> comprimento do objeto (plano de distribuição)
     * cadeira [i] -> Cadeira por tipo controlado pelo índice
     * larg_Item -> Largura da cadeira
     * comp_Item -> Comprimento da cadeira
     * iLinha ->
     * lLinha ->
     * wLinha ->
     * comp_usado_faixa -> Tamanho de largura utilizada na faixa de corte criada
     * y -> Largura do primeiro item de cada faixa
     * y_faixa -> qtd_paineis + 1
     * qtd_paineis -> Quantidade de Objetos
     * sobra_comp[j] ->
     * sobra_larg[k] ->
     */
    class Program
    {
        void ordena()
        {
            int maior = 0; //identifica qual o maior item para ordenar
            for (int i = 1; i <= n; i++)
            {
                for (iLinha = 1; iLinha <= n; iLinha ++)
                {
                    if (comp_Item > maior)
                    {
                        maior = w[i];
                        indice = iLinha;
                    }
                }
                lLinha[i] = l[indice];
                wLinha[i] = w[indice];
                z = indice;
                l[indice] = 0;
                w[indice] = 0;
                maior = 0;
            }
        }
        void cria_faixa(){
            comp_usado_faixa = 0;
            y = 0;
            qtd_paineis = 0;
            y_faixa = 
        }

        static void Main(string[] args)
        {
            
           
        }
    }
}
