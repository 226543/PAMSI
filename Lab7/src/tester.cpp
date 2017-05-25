#include "tester.hh"

void Tester::prepareThings(unsigned int amount,int mode) {
  std::string newKey;
  std::string newValue;
  unsigned int randomNumber;
	unsigned int i = 0;

  // ustawienie odpowiedniej funkcji haszujacej
  dictionary->changeHashFunction(mode);

  // losowanie numeru w celu wybrania losowego elementu do wyszukania
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, amount-1);
  randomNumber = dis(gen);

  // wczytywanie danych z pliku
	file.open("names.csv");

  if(!file.is_open()) {
    std::cerr << "ERROR: File Open\n";
    exit(EXIT_FAILURE);
  }

  while(file.good() && i < amount-1) {
    std::getline(file,newKey,',');
    std::getline(file,newValue,'\n');
		dictionary->insert(newKey,newValue);
    if(i == randomNumber) {
      toFind = newKey;
    }
		++i;
  }
  file.close();
}

void Tester::doThings(unsigned int amount,int mode) {
  dictionary->find(toFind);
}

void Tester::restart() {
  dictionary->restart();
}
