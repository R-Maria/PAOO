#include <iostream>
#include <vector>

class Persoana {
private:
    int varsta;
    std::string nume;
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
    Persoana(const Persoana&) {
        std::cout<<"Copy Constructor clasa Persoana"<<std::endl;
    }
    //10
    Persoana& operator+=(const Persoana& p) {
        std::cout<<"Operator += clasa Persoana"<<std::endl;
        nume += p.nume;
        varsta += p.varsta;
        return *this;
    }
    //11
    Persoana& operator = (const Persoana& p) {
        if(this == &p) {
            std::cout<<"Acelasi obiect"<<std::endl;
            return *this;
        }
        std::cout<<"Copy Assignment clasa Persoana"<<std::endl;
        nume = p.nume;
        varsta = p.varsta;
        return *this;
    }
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
    //12
    Student(const Student& s): Persoana(s) {
        std::cout << "Copy Constructor Student" << std::endl;
        this->facultate = s.facultate;
    }; // copy constructor
    Student& operator=(const Student& s) {
        if(this == &s) {
            std::cout<<"Acelasi obiect"<<std::endl;
            return *this;
        }
        std::cout << "Copy assignment operator Student" << std::endl;
        Persoana::operator=(s);
        this->facultate = s.facultate;
        return *this;
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
    //Camin c2;
    //c2 = c; //copy assignment operator

    //tema2
    Persoana p1("p1",5);
    Persoana p2("p2",6);
    Persoana p3("p3",7);
    //10
    p1 += p2 += p3;
    std::cout<<p1.getVarsta()<<std::endl;
    std::cout<<p1.getNume()<<std::endl;
    //11
    p2 = p2;
    //12
    Student s;
    s = m;
    std::cout<<s.getFacultate()<<std::endl;
    std::cout<<s.getNume()<<std::endl;
    std::cout<<s.getVarsta()<<std::endl;

    return 0;
}
