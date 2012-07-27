/************************************************************************************************
 * Exemplo de uso do boost serialization
 *
 * compilando: g++ -o boost_serialization boost_serialization.cpp -lboost_serialization
 * 
 * Um exemplo:
 *   http://visualgrid.de/wp/2012/02/03/xml-serialization-with-boost-tested-with-version-1-48/
 *
 ************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory>

#include <boost/config.hpp>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;

class IRPF {

public:

    IRPF (string ex, string banco, string ag, string sit) :
	Exercicio(ex),Banco(banco),Agencia(ag),Situacao(sit){}

    IRPF (){}


    string getExercicio() {return Exercicio;}
    string getBanco() {return Banco;}
    string getAgencia() {return Agencia;}
    string getSituacao() {return Situacao;}


    // 
    // parte do codigo referente ao boost
    friend class boost::serialization::access;

    template<class Archive> 
    void serialize (Archive & ar, const unsigned int version) {
	ar & BOOST_SERIALIZATION_NVP(Exercicio);
	ar & BOOST_SERIALIZATION_NVP(Banco);
	ar & BOOST_SERIALIZATION_NVP(Agencia);
	ar & BOOST_SERIALIZATION_NVP(Situacao);
    }
    // fim da parte referente ao boost


private:
    string Exercicio;
    string Banco;
    string Agencia;
    string Situacao;

};

int main () {

    {
	IRPF ir ("2012","Itau","3750","Em processamento");

	ofstream ofs ("/tmp/irpf.xml");

	boost::archive::xml_oarchive oa (ofs);

	cout << "\n\nSalvando dados no xml..." << endl;
	oa << BOOST_SERIALIZATION_NVP(ir);
	
	cout << "Arquivo gerado... De um cat /tmp/irpf.xml para visualizar." << endl;

    }

    {
	IRPF ir;

	ifstream ifs ("/tmp/irpf.xml");

	boost::archive::xml_iarchive ia (ifs);

	cout << "\n\n\n\nRecuperando dados do xml..." << endl;
	ia >> BOOST_SERIALIZATION_NVP(ir);

	cout << "Dados recuperados..." << endl;
	cout << "Exercicio: " << ir.getExercicio()<<endl;
	cout << "Banco    : " << ir.getBanco()<<endl;
	cout << "Agencia  : " << ir.getAgencia()<<endl;
	cout << "Situacao : " << ir.getSituacao()<<endl;

    }
    
    return 0;
}
