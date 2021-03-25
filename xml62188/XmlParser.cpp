#include"pch.h"
#include "XmlParser.h"
int getFirstDelimiterIndex(const char* txt, const char* delimiters) {
	int i;
	if (txt == NULL) {
		return -1;
	}
	if (delimiters == NULL) {
		return 0;
	}
	for (i = 0; txt[i] && strchr(delimiters, txt[i]) == NULL; i++);
	return i;
}

int getLastDelimiterIndex(const char* txt, const char* delimiters) {
	int i;
	if (txt == NULL) {
		return -1;
	}
	if (delimiters == NULL) {
		return 0;
	}
	for (i = 0; txt[i] && strchr(delimiters, txt[i]) != NULL; i++);
	return i;
}

int strncasecmp(const char* s1, const char* s2, size_t n) {
	if (n == 0)
		return 0;

	while (n-- != 0 && tolower(*s1) == tolower(*s2)) {
		if (n == 0 || *s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	//tolower-pravi bukvite malki
	return tolower(*(unsigned char*)s1) - tolower(*(unsigned char*)s2);
}

const char* stristr(const char* haystack, const char* needle) {
	long i, n;//i i n sa indeksi
	for (i = 0; haystack[i]; i++) {
		if (tolower(haystack[i]) == tolower(needle[0])) {
			for (n = 0; haystack[i + n] && needle[n] && tolower(haystack[i + n]) == tolower(needle[n]); n++);
			if (n == strlen(needle))
				return(&haystack[i]);
		}
	}
	return NULL;
}

int random(int min, int max) {
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}

Child* XmlParser::createChild() {
	Child* newChild = new Child;

	newChild->key = NULL;
	newChild->value = NULL;
	newChild->next = NULL;

	if (this->children == NULL) {
		this->children = newChild;
	}
	else {
		for (Child* temp = this->children; temp != NULL; temp = temp->next) {
			if (temp->next == NULL)//ako nqma sledvasht element sledvashtiq stava toku-shto suzdadeniq
			{
				temp->next = newChild;
				break;
			}
		}
	}
	return newChild;
}

Attribute* XmlParser::createÀttribute(char* k, char* v) {
	Attribute* newAttribute = new Attribute;

	newAttribute->next = NULL;
	newAttribute->key = NULL;

	if (this->attributes == NULL) {
		this->attributes = newAttribute;
	}
	else {
		for (Attribute* temp = this->attributes; temp != NULL; temp = temp->next) {
			if (temp->next == NULL) {
				temp->next = newAttribute;
				break;
			}
		}
	}
	if (k != NULL) {
		newAttribute->key = k;
	}
	if (v != NULL) {
		newAttribute->value = v;
	}

	return newAttribute;
}

XmlParser::XmlParser() {
	this->key = NULL;
	this->value = NULL;
	this->attributes = NULL;
	this->children = NULL;
	this->parent = NULL;
}

XmlParser::XmlParser(const char* xml, XmlParser* parent) {
	this->parser(xml, parent);//suzdavame Xml-a

}

XmlParser::~XmlParser() {
	if (key != NULL) {
		delete[] key;
	}

	if (value != NULL) {
		delete[] value;
	}

	if (attributes != NULL) {
		for (Attribute* temp = attributes; temp != NULL; temp = temp->next) {
			if (temp->key != NULL) {
				delete[] temp->key;
			}
			if (temp->value != NULL) {
				delete[] temp->value;
			}
		}
	}

	if (children != NULL) {
		for (Child* temp = children; temp != NULL; temp = temp->next) {
			if (temp->key != NULL) {
				delete[] temp->key;
			}
			if (temp->value != NULL) {
				delete[] temp->value;
			}
		}
	}
}

void XmlParser::parser(const char* xml, XmlParser* parent) {
	//printf("\n\n\nXmlParser input:\n%s", xml);
	Attribute *tempAttribute = NULL;
	Child *tempChild = NULL;
	const char *current = NULL, *next = NULL, *last = NULL;
	char *buffer = NULL, *end = NULL;
	char lastChar = '\0';
	int length = 0;

	this->key = NULL;
	this->value = NULL;
	this->attributes = NULL;
	this->children = NULL;
	this->parent = parent;
	//current e teksta, koito parsvame
	current = strchr(xml, '<');//tursi otvarqsht simvol
	if (current == NULL) {
		return;//ako nqma otvarqsht simvol svurshva programata
	}

	current++;
	//duljinata na imeto na elementa
	length = getFirstDelimiterIndex(current, "> \t\r\n");
	//zapisvame imeto na key-q
	this->key = new char[length + 1];
	//length- na broi simvoli se kopirat ot current v key
	strncpy(this->key, current, length);
	this->key[length] = '\0';
	current += length;//izmestva se s length na broi pozicii
	lastChar = current[0];//purviq elemenyt ot noviq tekst

	// Read attributes
	while (current && current[0] && lastChar != '>') {
		length = getLastDelimiterIndex(current, "/> \t\r\n");
		lastChar = current[length - 1];
		current += length;

		if (lastChar == '>' || current == NULL) {
			break;
		}

		if (lastChar == '/' && current[0] == '>') {
			current += 2;//preskacha tozi simvol
			break;
		}

		length = getFirstDelimiterIndex(current, "=");//tursi purvoto ravno, koeto nameri v teksta

		if (current[length] == '=' && current[length + 1]) {
			tempAttribute = this->createÀttribute();
			tempAttribute->key = new char[length + 1];
			strncpy(tempAttribute->key, current, length);
			tempAttribute->key[length] = '\0';

			current += length + 1;//izmestva sled atributa i ravnoto
			if (current[0] == '"') {
				current++;
				length = getFirstDelimiterIndex(current, "\"");
				tempAttribute->value = new char[length + 1];
				strncpy(tempAttribute->value, current, length);
				tempAttribute->value[length] = '\0';
				current += length + 1;//imestva se s cqlata duljina +1
			}
			else {
				length = getFirstDelimiterIndex(current, "> \t\r\n");
				tempAttribute->value = new char[length + 1];
				strncpy(tempAttribute->value, current, length);
				tempAttribute->value[length] = '\0';
				current += length;
			}

			if (current) {
				lastChar = current[0];//last char stava purviq simvol
			}
		}
	}

	Attribute *attrId = this->getAttribute("id");
	//vrushta ti id-to na atributa, zashtoto vseki atribut si ima unikalno id
	if (attrId == NULL) {
		int rand = random(1000, 99999);
		char ks[6];//zapisvame int chislo v masiv ot charove-za value-to
		for (int i = 0; i < 6; i++) ks[i] = '\0';//zanulqvame masiva
		sprintf(ks, "%d", rand);//preobrazuva integer v chislo v masiv ot charove
		tempAttribute = this->createÀttribute();
		tempAttribute->key = new char[3];//zashtoto id e s 2 bukvi
		strncpy(tempAttribute->key, "id", 2);
		tempAttribute->key[2] = '\0';
		tempAttribute->value = new char[strlen(ks) + 1];
		strncpy(tempAttribute->value, ks, strlen(ks));//prisvoqvame ks na value-to
		tempAttribute->value[strlen(ks)] = '\0';
	}

	if (lastChar == '/') {
		return;
	}

	if (lastChar == '>') {
		current++;//otiva kum sledvashtiq simvol
	}

	length = getLastDelimiterIndex(current, "> \t\r\n");

	if (!current[length])//ako dostigne kraq na teksta
	{
		return;
	}

	if (current[length] == '<') {
		current += length;
		buffer = new char[strlen(this->key) + 4]; // 4 => "</>\0" - duljinata na key-q + tezi 4 simvola
		sprintf(buffer, "</%s>", this->key);//slaga key-q v buffer-a

		while (current && strncasecmp(current, buffer, strlen(buffer))) {
			next = strchr(current, '<');
			if (next == NULL) {
				delete[] buffer;//ako next e null iztriva buffera
				return;
			}

			next++;
			length = getFirstDelimiterIndex(next, "> \t\r\n");

			// Parse key (tag) name
			tempChild = this->createChild();
			tempChild->key = new char[length + 1];
			strncpy(tempChild->key, next, length);
			tempChild->key[length] = '\0';
			tempChild->value = new XmlParser(current, this);//kogato namerim Child suzdavame nov Xml-parser

			end = new char[length + 4]; // 4 => "</>\0" end-zatvarqsht tag -masiv ot charove
			sprintf(end, "</%s>", tempChild->key);
			current = stristr(current, end);
			current += strlen(end);//izmestvame current s tolkova simvoli , kolkoto e end-zatvarqshtiq tag.otivame sled nego
			delete[] end;

			current = strchr(current, '<');
		}
		delete[] buffer;
	}
	else {
		buffer = new char[strlen(key) + 4]; // 4 => "</>\0"
		sprintf(buffer, "</%s>", key);//zapisvame key v buffer-a
		next = stristr(current, buffer);
		delete[] buffer;

		if (next == NULL) {
			length = strlen(current);
			value = new char[length + 1];
			strcpy(value, current);//zapisva teksta vuv value-to
		}
		else {
			length = next - current;//izmestva ukazatelq nazad, vzima teksta i go zapisva vuv value
			value = new char[length + 1];
			strncpy(value, current, length);
			value[length] = '\0';
		}
	}

}
//funkciq , koqto se griji za unikalnostta na id-tata
void XmlParser::checkAndAssignIds(int count) {
	Child* children = this->children;
	Attribute* attributes = this->attributes;
	int childrenCount = this->getChildrenCount();
	char** map = new char*[childrenCount + 1];

	if (this->parent != NULL) {
		return;
	}

	char* id = this->getAttributeValue("id");
	map[0] = new char[strlen(id) + 1];
	strcpy(map[0], id);
	map[0][strlen(id)] = '\0';

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* child = (XmlParser*)tmp->value;
		char *id = child->getAttributeValue("id");
	}
}
//broq na decata
int XmlParser::getChildrenCount() {
	int count = 0;
	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;//proverqva value-to ako e razlichno ot null -> ima child
		if (parser != NULL) {
			count++;
		}
	}
	return count;
}
//vrushta value po zadaden key na atribut
char* XmlParser::getAttributeValue(const char* key) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->key, key) == 0) {
			return tmp->value;
		}
	}
	return NULL;
}
//vrushta celiq atribut po daden key
Attribute* XmlParser::getAttribute(const char* key) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if (strcmp(tmp->key, key) == 0) {
			return tmp;
		}
	}
	return NULL;
}
//tekstov fail i go pravim v durvo
bool XmlParser::load(const char* fileName) {
	char line[500];//polzvame go za buffer
	char* txt = NULL;
	char* tmp = NULL;
	int len = 0;
	ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		while (inputFile.getline(line, 500, 'EOF')) //chetem do kraq na faila
		{
			//cout << line <<endl;
			if (txt == NULL) {
				len = strlen(line);
				txt = new char[len + 1];
				strcpy(txt, line);//kopira line-a v txt
				txt[len] = '\0';
			}
			else {
				len = strlen(txt) + strlen(line);
				tmp = new char[len + 1];//pravim nov masiv za da subere stariq i noviq tekst
				tmp[len] = '\0';
				strcpy(tmp, txt);
				delete[] txt;
				txt = tmp;
			}
		}

		if (txt != NULL) {
			this->parser(txt);
			delete[] txt;
		}
		inputFile.close();
		return true;
	}
	return false;
}
//proverqva dali faila sushtestvuva
bool XmlParser::exists(char* strFileName) {
	ifstream isFileExist(strFileName);
	return !!isFileExist;//za da ne vrushta null- !null-stava true i posle !true stava false
}
//izvejda xml-parsera - cqloto durvo
void XmlParser::print(const int offset)
//offset-broq na izmestvaneto navutre
{
	char* intervalsOffset = NULL;//masiv ot intervali

	intervalsOffset = new char[offset + 1];//zadelqme pamet broq izmestvaniq + terminirashtata nula
	intervalsOffset[offset] = '\0';
	for (int i = 0; i < offset; i++) intervalsOffset[i] = ' ';

	if (this->value != NULL) {
		if (this->attributes != NULL) {
			printf("\n%s<%s", intervalsOffset, this->key);
			for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
				printf(" %s=\"%s\"", tmp->key, tmp->value);
			}
			printf(">%s", this->value); //teksta na samiq element
		}
		else {
			printf("\n%s<%s>%s", intervalsOffset, this->key, this->value);//ako nqma atributi izvejdame key-q i value -to
		}
	}
	//ako nqma tekst
	else {
		if (this->attributes != NULL) {
			printf("\n%s<%s", intervalsOffset, this->key);
			for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
				printf(" %s=\"%s\"", tmp->key, tmp->value);
			}
			printf(">");
		}
		else if (this->key != NULL) {
			printf("\n%s<%s>", intervalsOffset, this->key);
		}
	}

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		parser->print((offset + 4));//zashtoto vseki child e 4 intervala po navutre
	}
	if (this->key != NULL) {

		if (this->children != NULL) {
			printf("\n%s</%s>", intervalsOffset, this->key);
		}
		else {
			printf("</%s>", this->key);
		}

	}
	delete[] intervalsOffset;
}
//vrushta value-to po podadeni id i key
char* XmlParser::getValue(char* id, char* key) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			for (Attribute* tmp2 = this->attributes; tmp2 != NULL; tmp2 = tmp2->next) {
				if (strcmp(tmp2->key, key) == 0) {
					return tmp2->value;
					//pravim tova za da preminem prez vsichki atrobuti i da namerim tozi, koito tursim
				}
			}
		}
	}

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;//vzimame valueto i mu promenqme tipa
		char * res = parser->getValue(id, key);//samoizvikvame funkciqta

		if (res == NULL) {
			continue;
		}
		else {
			return res;
		}
	}
	return NULL;
}
//proverqvame dali value-to se e promenilo uspeshno
bool XmlParser::setAttributeValue(char* id, char* key, char* value) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			for (Attribute* tmp2 = this->attributes; tmp2 != NULL; tmp2 = tmp2->next) {
				if (strcmp(tmp2->key, key) == 0) {
					delete[] tmp2->value;
					tmp2->value = value;
					return true;
				}
			}
			 
			this->createÀttribute(key, value);
		}
	}

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		bool res = parser->setAttributeValue(id, key, value);

		if (res == false) {
			continue;
		}
		else {
			return res;
		}
	}
	return false;
}
//vrushta stoinostta na key-qn
char* XmlParser::getKey() {
	return this->key;
}
//izvenjda atributite na decata po dadeno id
void XmlParser::printChildrenAttributes(char* id) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			for (Child* tmp2 = this->children; tmp2 != NULL; tmp2 = tmp2->next) {
				XmlParser* parser = (XmlParser*)tmp2->value;
				char* key = parser->getKey();
				cout << "\nChild with key <" <<key<< ">" << endl;//printvame key -q na elementa, za koito shte printirame atributite
				parser->printAttributes();
			}
		}
	}

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		parser->printChildrenAttributes(id);//funkciqta izvikva sebe si - rekursiq i otiva v sledvashtiq child
	}
}
//izvejda ti atributite
void XmlParser::printAttributes() {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		cout << "\n" << tmp->key << endl;//obhojda atributite po spisuk i im izvejda key-q
	}
}
//vrushta n-toto dete
XmlParser* XmlParser::getChild(char* id, int n) {
	int cnt = 1;
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			for (Child* tmp2 = this->children; tmp2 != NULL; tmp2 = tmp2->next, cnt++) {
				if (cnt == n) {
					return this;//vrushta n-toto dete
				}
			}
		}
	}
	//sliza nadolu po durvoto
	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		XmlParser* res = parser->getChild(id, n);

		if (res == NULL) {
			continue;
		}
		else {
			return res;
		}
	}
	return NULL;
}
//vrushta teksta po zadadeno id
char* XmlParser::getText(char* id) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			return this->value;
		}
	}

	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		char* res = parser->getText(id);//za teksta

		if (res == NULL) {
			continue;
		}
		else {
			return res;
		}
	}

	return NULL;
}
//trie atribut po zadeno id i key
bool XmlParser::deleteAttribute(char* id, char* key) {
	for (Attribute* tmp = this->attributes, *q = NULL, *r = NULL; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			Attribute* tmp2 = this->attributes;
			if (strcmp(tmp2->key, key) == 0) {
				tmp2 = this->attributes->next;
				if (this->attributes->key != NULL) 
					delete[] this->attributes->key;
				if (this->attributes->value != NULL) 
					delete[] this->attributes->value;
				delete this->attributes;
				this->attributes = tmp2;
				return true;
			}
			else {
				for (tmp2 = this->attributes; tmp2 != NULL; tmp2 = tmp2->next) {
					if (tmp2->next != NULL && strcmp(tmp2->next->key, key) == 0) {
						Attribute* tmp3 = tmp2->next;
						tmp2->next = tmp3->next;
						if (tmp3->key != NULL)
							delete[] tmp3->key;
						if (tmp3->value != NULL)
							delete[] tmp3->value;
						delete tmp3;
						return true;
					}
				}
			}
			return false;
		}
	}
	//obhojdam vsichkite deca rekursivno
	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		bool res = parser->deleteAttribute(id, key);//dali e uspeshno iztrivaneto

		if (res == false) {
			continue;
		}
		else {
			return res;
		}
	}

	return false;
}
 

bool XmlParser::addChild(char* id, char* key) {
	for (Attribute* tmp = this->attributes; tmp != NULL; tmp = tmp->next) {
		if ((strcmp(tmp->key, "id") == 0) && (strcmp(tmp->value, id) == 0)) {
			Child *tmp2 = this->createChild();
			if (tmp2 != NULL) {
				int keyLen = strlen(key);
				tmp2->key = new char[keyLen + 1];
				strcpy(tmp2->key, key);
				tmp2->key[keyLen];
				int len = (keyLen * 2) + 6;
				char* element = new char[len];
				sprintf(element, "<%s></%s>", key, key);
				element[len - 1] = '\0';
				XmlParser* xmlParser = new XmlParser(element, this);
				tmp2->value = xmlParser;
				tmp2->next = NULL;
				delete[] element;
				return true;
			}
			return false;
		}
	}
	//sliza nadolu po durvoto
	for (Child* tmp = this->children; tmp != NULL; tmp = tmp->next) {
		XmlParser* parser = (XmlParser*)tmp->value;
		bool res = parser->addChild(id, key);

		if (res == NULL) {
			continue;
		}
		else {
			return res;
		}
	}
	return NULL;
}