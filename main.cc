#include "operacoes.hh"

int soma(int a, int b)
{
	return a + b;
}

int multiplicacao(int a, int b)
{
	return  a * b;
}

int subtracao(int a, int b)
{
	return a - b;
}

int main(){
	auto a = 2;
	auto b = 4;
	std::cout << soma(a,b) << std::endl;
	std::cout << multiplicacao(a,b) << std::endl;
	std::cout << subtracao(a,b) << std::endl;
}
