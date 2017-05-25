#ifndef HASHTABLE_HH
#define HASHTABLE_HH
#include <iostream>
#include <string>
#include "ihashtable.hh"
#include "measurable.hh"
#include "list.hh"

// stała określająca ilość bucketów (l. elementów tablicy list)
#define SIZE 10000

class Hashtable : public iHashtable {
  private:
  // Rozmiar tablicy haszującej (ilość bucketów)
  int numberOfBuckets;

  // Zmienna odpowiedzialna za wybór funkcji haszującej
  int hashFunction = 2;

  // bucket to wskaźnik na początek tablicy list
  List* bucket = nullptr;

  /* funkcja haszująca nr 1, jest wykorzystywana gdy zmienna hashFunction == 1
  Zamienia dwa pierwsze znaki na kod ASCII i zwraca sumę tych wartości
  modolo wartość zmiennej numberOfBuckets */
  int hash1(std::string key);

  /* funkcja haszująca nr 2, jest wykorzystywana gdy zmienna hashFunction == 2
  Implementacja algorytmu haszującego Fowler–Noll–Vo */
  int hash2(std::string key);

  public:
  Hashtable() {
    numberOfBuckets = SIZE;
    bucket = new List[SIZE];
  }
  Hashtable(int nSize) {
    numberOfBuckets = nSize;
    bucket = new List[nSize];
  }

  ~Hashtable() {
    delete [] bucket;
  }

  void insert(std::string key, std::string value);
  std::string find(std::string key);
  std::string remove(std::string key);
  void changeHashFunction(int mode);
  void restart();
};

#endif
