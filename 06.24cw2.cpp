//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class interfaceText {
public:
	virtual void write() = 0;
	virtual string getLine(size_t)=0;
	virtual size_t getSize()=0;
	virtual ~interfaceText() {
	}
};

void g(int &x) {

}

class SimpleText: public interfaceText {
private:
	vector<string> data;
public:
	SimpleText() {
		string str;
		while (str != "0") {
			getline(cin, str);
			data.push_back(string(str));
		}
	}
	void write() override {
		for (auto &line : data) {
			cout << line << endl;
		}
	}
	string getLine(size_t n) {
		return this->data[n];
	}
	size_t getSize() {
		return this->data.size();
	}
};

class DecoratedText: public interfaceText {
protected:
	interfaceText *father;
public:
	DecoratedText(interfaceText *_father) {
		this->father = _father;
	}
	virtual void write()=0;
	virtual ~DecoratedText() {
	}
};

class AutorText: public DecoratedText {
public:
	AutorText(interfaceText *_father) :
			DecoratedText(_father) {

	}
	void autorInterier() {
		cout << "\t\t\t Autor Aninom" << endl;
		cout << "\t\t\t since   1899" << endl;
		father->write(); //Первоначальный текст и его вывод
		cout << "xxxxxxxx" << endl;

	}
	void write() override {
		autorInterier();
	}
};

class FormattedText: public DecoratedText {
public:
	FormattedText(interfaceText *father) :
			DecoratedText(father) {
	}
	void write() {
		cout << "\t";
		for (size_t i = 0; i < this->father->getSize(); ++i) {
			string tmp = this->father->getLine(i);
			if (tmp[0] >= 'a' && tmp[0] <= 'z')
				tmp[0] -= 32;
			if (tmp[tmp.size() - 1] != '.')
				tmp += ".";
			cout << tmp << endl;
		}
	}
	string getLine(size_t n) {
		return this->father->getLine(n);
	}
	size_t getSize() {
		return this->father->getSize();
	}
};

int main() {
	cout << "Hello World!\n";
	SimpleText *st = new SimpleText;
	FormattedText ft(st);
	ft.write();

	//a - 3 метода, 2 поля с данными
	//DECORATOR:
	//	1. Он позволяет изменить уже созданный объект
	//	(а не его класс)
	//	2. И при этом сохранить первоначальный тип
}

