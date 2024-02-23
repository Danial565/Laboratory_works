

#include <iostream>

class Stringg {
    int d_n;
    char* str;
public:
    Stringg(int n)
    {  
        d_n = n;
        str = new char[n];
    }
    Stringg(const Stringg& other) :Stringg(other.d_n)
    {
        std::cout << "Copy Constr" << std::endl;
        for (int i = 0; i < d_n; i++)
        {
            str[i] = other.str[i];
        }
    }
    Stringg& operator=(const Stringg& other)
    {
        std::cout << "modified string: ";
        delete[] str;
        d_n = other.d_n;
        str=new char[d_n];
        for (int i = 0; i < d_n; i++)
        {
            str[i] = other.str[i];
        }
        return *this;
    }
    void setR()
    {
        for (int i = 0; i < d_n; i++)
        {
            std::cin >> str[i];
        }
    }

    char getR(int i)
    {
        return str[i];
    }
    

    ~Stringg()
    {
        delete[] str;
    }

};

int main()
{
    std::cout << "String D ";
    int n;
    std::cin >> n;
    Stringg D(n);
    D.setR();
    std::cout << std::endl;
    Stringg K = D;
    std::cout << "String K: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << K.getR(i);
    std::cout<< std::endl << "String M ";
    std::cin >> n;
    Stringg M(n);
    M.setR();
    std::cout << std::endl;
    std::cout << "String D" << std::endl;
    D = M;
    for (int i = 0; i < n; i++)
        std::cout << D.getR(i);

}

