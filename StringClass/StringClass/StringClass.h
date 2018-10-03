#ifndef __STRING_H__
#define __STRING_H__

#include <cstring>

typedef unsigned int uint;

class String {

public:

	//Constructor
	String() : str(nullptr), size(0) {
		Clear();
	}
	String(const char* string) : size(strlen(string) + 1), str(new char[size]) {
		strcpy_s(str, size, string);
	}
	String(const String &String) : size(String.size), str(new char[size]) {
		strcpy_s(str, size, String.str);
	}

	//Destructor
	virtual ~String() {}

	//Methods
	bool Empty() const {
		return size == 0;
	}

	uint GetSize() const {
		return size;
	}

	void Clear() {
		str[0] = '\0';
	}

	const char* pointer() const {
		return str;
	}

	//Operators
	bool operator=(const String &String) {}

	void operator+=(const String &String) {}

	bool operator==(const String &String) const {
		return strcmp(String.str, this->str) == 0;
	}

	bool operator!=(const String &String) const {
		return strcmp(String.str, this->str) != 0;
	}

	//operator: +, >=, <=, >, <
	//cutend, cutfront, allocate

private:

	char* str;
	uint size;

};


#endif // !__STRING_H__

