#include <iostream>
#include <vector>

class Persoana {
private:
    int varsta = 0;
    std::string nume = "";
public:
    Persoana() {};
    Persoana(std::string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
        std::cout<<"Constructor Persoana"<<std::endl;
    };
    virtual ~Persoana() {
        std::cout<<"Destructor Persoana"<<std::endl;
    };
    int getVarsta() {
        return varsta;
    };
    std::string getNume() {
        return nume;
    };
};

class Student :public Persoana {
private:
    std::string facultate;
public:
    Student() {};
    Student(std::string nume, int varsta, std::string facultate): Persoana(nume, varsta) {
        this->facultate = facultate;
        std::cout << "Constructor Student" << std::endl;
    };
    ~Student() {
        std::cout << "Destructor Student" << std::endl;
    };
    std::string getFacultate() {
        return facultate;
    };
    Student(const Student& s) {
        std::cout << "Copy Constructor Student" << std::endl;
    }; // copy constructor
    Student& operator=(const Student& s) {
        std::cout << "copy assignment operator Student" << std::endl;
    } //copy assignment operator
};

class Camin {
private:
    std::vector<Student> studenti;
    std::string nume;
public:
    Camin() {
        std::cout << "Constructor Camin" << std::endl;
    }
    ~Camin() {
        std::cout << "Destructor Camin" << std::endl;
    };
    void adaugaStudenti(Student *s) {
        studenti.push_back(*s);
    };
    std::string getNume() {
        return nume;
    };
    Camin(const Camin&) = delete;
    Camin& operator = (const Camin&) = delete;
};

int main() {
    Student m("Maria", 20, "CTI");
    Student a("Andrada", 20, "ETC");
    Student s1; //default constructor

    s1 = m; //copy assignment operator
    Student s2(m); //copy constructor

    Camin c;
    c.adaugaStudenti(&m);
    c.adaugaStudenti(&a);

    //Camin c1(c); //copy constructor
    //Camin c2 = c; //copy assignment operator

    return 0;
}
