#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

class HTTP {

	private:
		HTTP(){};
		string url;

	public:

		~HTTP () {cout << " ---> destructor <----"<<endl;}
		void setUrl(string _url) {url = _url;}
		string getUrl () { return url;}
		static HTTP& getInstance(); 


};

HTTP& HTTP::getInstance() {

	static auto_ptr<HTTP> http_singleton;
	if (http_singleton.get() == NULL) {
		cout << "+++ Creating the HTTP instance: " << endl;

		http_singleton = auto_ptr<HTTP> (new HTTP() );
	}
	return *http_singleton.get();
}


void func2 () {

	HTTP& http = HTTP::getInstance();
	http.setUrl ("http://localhost/");
	cout << "--- func2 " << http.getUrl() << endl;

}

int main () {


	/*
	 * Mostra um exemplo de criacao de um singleton usando auto_ptr
	 * Nesse exemplo o objeto HTTP instanciado e usado tanto aqui no main
	 * quanto na func2()
	 * A instancia e deletada automaticamente nao deixando leak (testado com valgrind
	 */

	func2();
	HTTP& http = HTTP::getInstance();
	//http.setUrl ("http://localhost/");
	cout << "---- main " << http.getUrl() << endl;

	return 0;
}
