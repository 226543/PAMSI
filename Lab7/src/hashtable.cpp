#include "hashtable.hh"

int Hashtable::hash1(std::string key) {
  int result;
  if( key.length() < 2) {
    result = (int)key[0];
  }
  else {
    result = (int)key[0] + (int)key[1];
  }
  return result % numberOfBuckets;
}

int Hashtable::hash2(std::string key) {
  const unsigned int fnPrime = 0x811c9dc5;
	unsigned int hash = 2166136261;
	unsigned int i = 0;
	unsigned int len = key.length();

	for (i = 0; i < len; ++i) {
		hash *= fnPrime;
		hash ^= (key[i]);
	}
	return hash%numberOfBuckets;
}

void Hashtable::insert(std::string key, std::string value) {
  unsigned int index;
  if(hashFunction == 1) {
    index = hash1(key);
  }
  else if(hashFunction == 2) {
    index = hash2(key);
  }
  else {
    std::cerr << "Wybrano niewłaściwą opcję haszowania \n";
    exit(EXIT_FAILURE);
  }
  bucket[index].addBack(key, value);
}

std::string Hashtable::remove(std::string key) {
  unsigned int index;
  if(hashFunction == 1) {
    index = hash1(key);
  }
  else {
    index = hash2(key);
  }
  bucket[index].removeElem(key);
  return key;
}

std::string Hashtable::find(std::string key) {
  unsigned int index;
  if(hashFunction == 1) {
    index = hash1(key);
  }
  else {
    index = hash2(key);
  }
  return bucket[index].find(key);
}

void Hashtable::changeHashFunction(int mode) {
  hashFunction = mode;
}

void Hashtable::restart() {
  bucket->restart();
}
