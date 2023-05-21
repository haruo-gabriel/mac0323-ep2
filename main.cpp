#include <iostream>
#include "lib.h"
#include "vo.h"
#include "abb.h"
#include "tr.h"
#include "a23.h"
#include "arn.h"

int main() {
    std::string e;
    int n, q;
    std::vector<std::string> palavras;

    // Entradas
    std::cin >> e >> n;
    palavras = separaPalavras(n);
    for (const std::string& it : palavras) std::cout << it << " ";
    std::cout << std::endl << std::endl;

    // Estruturas
    if (e == "VO") {
			std::cout << "Construindo VO" << std::endl;
			VO vo = VO();
			for (const std::string &it : palavras)
					vo.add(it);
			vo.printVO(); std::cout << std::endl;
			// Consultas
			// std::cin.clear();
			std::cin >> q;
			for (int i=0; i<q; i++) {
				std::string consulta; std::cin >> consulta;
				if (consulta == "F") vo.palavrasMaisFrequentes();
				else if (consulta == "O") {
					std::string p; std::cin >> p;
					std::cout << vo.frequenciaPalavra(p) << std::endl;
				}
				else if (consulta == "L") vo.palavrasMaisLongas();
				else if (consulta == "SR") vo.maioresPalavrasSemRepeticaoLetras();
				else if (consulta == "VD") vo.menoresPalavrasSemRepeticaoVogais();
				else {
					std::cout << "Consulta inválida. Tente novamente." << std::endl;
					// i--;
				}
			}
    }
    else if (e == "ABB"){
        std::cout << "Construindo ABB" << std::endl;
        ABB abb = ABB();
        for (const std::string &it : palavras)
            abb.add(it);
        // abb.printABB();
        abb.printInordem();
				// Consultas
				// std::cin >> q;
				// for (int i=0; i<q; i++) {
				// 	std::string consulta; std::cin >> consulta;
				// 	if (consulta == "F") abb.palavrasMaisFrequentes();
				// 	else if (consulta == "O") {
				// 		std::string p; std::cin >> p;
				// 		std::cout << abb.frequenciaPalavra(p) << std::endl;
				// 	}
				// 	else if (consulta == "L") abb.palavrasMaisLongas();
				// 	else if (consulta == "SR") abb.maioresPalavrasSemRepeticaoLetras();
				// 	else if (consulta == "VD") abb.menoresPalavrasSemRepeticaoVogais();
				// 	else {
				// 		std::cout << "Consulta inválida. Tente novamente." << std::endl;
				// 		i--;
				// 	}
				// }
    }
    else if (e == "TR"){
        std::cout << "Construindo TR" << std::endl;
        TR tr = TR();
        for (const std::string &it : palavras)
            tr.add(it);
        // tr.printTR();
        tr.printInordem();
    }
    else if (e == "A23") {
        std::cout << "Construindo A23" << std::endl;
        A23 a23 = A23();
        for (const std::string &it : palavras)
            a23.add(it);
        // a23.printA23();
        a23.printInordem();
    }
    else if (e == "ARN"){
        std::cout << "Construindo ARN" << std::endl;
        ARN arn = ARN();
        for (const std::string &it : palavras)
            arn.add(it);
        arn.printARN();
    }
    else {
        std::cout << "Estrutura invalida" << std::endl;
    }


    return 0;
}