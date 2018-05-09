#include <iostream>
#include <glpk.h>

using namespace std;

int main()
{
	glp_prob *lp; //Criando um ponteiro para um problema de PL
	lp = glp_create_prob(); //instancia um PL
	glp_set_prob_name(lp, "FakeSC"); //Define um nome para o problema
	glp_add_rows(lp, 2); //Número de restrições do problema
	glp_set_row_name(lp, 1, "Lotação"); //Nome da restrição 1
	glp_set_row_name(lp, 2, "Espaço"); //Nome da restrição 2
	glp_add_cols(lp, 2); //Número de variáveis de decisão
	glp_set_col_name(lp, 1, "X1");//Nome da variável 1
	glp_set_col_name(lp, 2, "X2"); //Nome da variável 2
	glp_set_obj_dir(lp, GLP_MAX); //Especifica que o LP é problema de maximização
	//Estabelece limite superior para as linhas
	glp_set_row_bnds(lp, 1, GLP_UP, 0.0, 50000);
	glp_set_row_bnds(lp, 2, GLP_UP, 0.0, 23626);
	//Estabelece limite inferior para as colunas
	glp_set_col_bnds(lp, 1, GLP_LO, 0.0, 0.0);
	glp_set_col_bnds(lp, 2, GLP_LO, 0.0, 0.0);
	//Seta os valores dos coeficientes da variaveis da função objetivo
	glp_set_obj_coef(lp, 1, 40.0);
	glp_set_obj_coef(lp, 2, 60.0);

	//Deifnindo matriz de coeficientes
	//Declara vetor + 1 pq não usa posição zero
	int ia[3];
	double coef[3];

	//Cria a matrix alimentando linha por linha
	ia[1] = 1, ia[2] = 2;
	coef[1] = 1, coef[2] = 1;
	glp_set_mat_row(lp, 1, 2, ia, coef);

	coef[1] = 1, coef[2] = 0;
	glp_set_mat_row(lp, 1, 2, ia, coef);

	//Define o tipo das variáveis no caso GLP_IV especifica que as variáveis são inteiras
	//Verificar se essa variáveis são da função objetivo ou da matriz
	//glp_set_col_kind(lp, 1, GLP_IV);
	//glp_set_col_kind(lp, 2, GLP_IV);


	//Carrega a matrix
	//glp_load_matrix(lp, 4, ia, coef);

	glp_simplex(lp, NULL); //teste de resolução, alterar para problema de corte

	double z = glp_get_obj_val(lp);
	double x1 = glp_get_col_prim(lp, 1);
	double x2 = glp_get_col_prim(lp, 2);
    std::cout <<"\nz = "<< z <<"x1 = " << x1 <<"x2 = "<< x2 <<"\n"<<endl;
    glp_delete_prob(lp);





    return 0;
}
