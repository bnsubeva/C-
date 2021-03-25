#pragma once
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;
//vrushta indeksa na purviq nameren razdelitel
int getFirstDelimiterIndex(const char* txt, const char* delimiters);
//vrushta indeksa na posledniq razdelitel
int getLastDelimiterIndex(const char* txt, const char* delimiters);
//sravnqvame dva stringa be znachenie ot malki i glavni bukvi i kazvame kolko na broi simvola sa sravni
int strncasecmp(const char* s1, const char* s2, size_t n);
//tursim duma v teksta i vrushtame ukazatel kum purviq element ot taq duma
const char* stristr(const char* haystack, const char* needle);
//generira random chislo v intervala ot min do max
int random(int min, int max);
//atribut-vseki parent si ima atribut i "deca"
typedef struct Attribute {
	char* key;
	char* value;
	Attribute* next;
} Attribute;
//vutreshni elementi-deca
typedef struct Child {
	char* key;
	void* value;  
	Child* next;
} Child;

class XmlParser {
private:
	char* key;//imeto -primer- name
	char* value;//stoinostta-primer-John Swith
	Attribute* attributes;
	Child* children;
	XmlParser* parent;
public:
	XmlParser();
	//xml-teksta
	XmlParser(const char* xml, XmlParser* parent);
	//suzdavame dete
	Child* createChild();
	//k-key i v-value - dadeni sa mu stoinosti po podrazbirane
	Attribute* createÀttribute(char* k = NULL, char* v = NULL);
	//zarejda Xml-a v dvurvovidna struktura
	void parser(const char* xml, XmlParser* parent = NULL);

	void checkAndAssignIds(int count = 0);
	//ukazva na koi atribut vrushta value-to
	char* getAttributeValue(const char* key);
	//vrushta celiq atribut
	Attribute* getAttribute(const char* key);
	//vrushta broq na decata
	int getChildrenCount();
	//vzima tekstov fail i go pravi v durvo
	bool load(const char* fileName);
	//proverqvame dali faila veche sushtestvuva
	bool exists(char* strFileName);
	//printira ti xml-a zaedno s childovete , atributi i tn
	void print(const int offset = 0);
	//vrushta valueto po dadeni id i key
	char* getValue(char* id, char* key);
	//vrushta key-q
	char* getKey();
	//obhojda atributite i im printira key-q
	void printAttributes();
	//proverqvame dali uspeshno sme promenili stoinostta na value-to ili ne
	bool setAttributeValue(char* id, char* key, char* value);
	//izvejdane na decata po dadeno id
	void printChildrenAttributes(char* id);
	//vrushta n-toto dete
	XmlParser* getChild(char* id, int n);
	//vrushta teksta po zadadeno id
	char* getText(char* id);
	//proverqvame dali trieneto na  atribut po zadadeno id i key e uspeshno
	bool deleteAttribute(char* id, char* key);
	bool addChild(char* id, char* key);
	//destruktor
	~XmlParser();
};