/**********************************************************************************
 *
 * g++ -std=c++0x -o teste_folly teste_folly.cpp -I/home/tercio/projects/tercio/folly -I/home/tercio/projects/double-conversion/src  -lfolly -lglog
 *
 *
 *
 *
 * *********************************************************************************/

#include <iostream>

#include "folly/dynamic.h"
#include "folly/json.h"

using namespace std;

int
main() {


	string json ("[{\"nome\":\"tercio\",\"end\":\"avenida\"},{\"nome\":\"marcia\",\"end\":\"mesma avenida\"}]");
	try {
		auto array = folly::parseJson(json);
		{
			folly::dynamic d = array.at(0);
			cout << d.at("nome") << endl;
			cout << d.at("end") << endl;
		}
		{
			folly::dynamic d = array.at(1);
			cout << d.at("nome") << endl;
			cout << d.at("end") << endl;
		}
	} catch (exception& e) {
		cerr << "parse incompleto..." << endl;
	}


	return 0;
}
