

#include <iostream>
#include <fstream>
#include <string.h>


namespace ds
{



    char tolower(char c)
    {
        if ('А' <= c && c <= 'Я')
            return c + 32;
        if ('Ё' == c)
            return 'ё';
        return c;
    }


    void tolower(char* str)
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);
    }


    bool isLetter(char c)
    {
        c = tolower(c);
        if (('а' <= c && c <= 'я') || c == 'ё')
            return true;
        return false;
    }

    void strcat(char* dst, char* src)
    {
        int len_dst = strlen(dst);
        int len_src = strlen(src);

        for (int i = 0; i < len_src; i++)
            dst[len_dst + i] = src[i];

        dst[len_dst + len_src] = '\0';
    }

    void strcat(char* dst, char src)
    {
        int len_dst = strlen(dst);
        dst[len_dst] = src;
        dst[len_dst + 1] = '\0';
    }


    void RemovePunctuationInaWord(char word[50])
    {
        int size = 0;

        for (int i = 0; i < strlen(word); i++)
        {
            if (ds::isLetter(word[i]) || ((ds::isLetter(word[i-1]))&&(word[i]=='-')&&(ds::isLetter(word[i + 1]))))
            {
                word[size] = word[i];
                size++;

            }
            else
            {
                if (size == 0)
                    continue;
                word[size] = '\0';
                size = 0;
            }
        }
    }
    bool isConsonant(char c)
    {
        c = tolower(c);
        char consonant[22] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч','ш', 'щ','\0'};

        for (int i = 0; i < strlen(consonant); i++)
            if (c == consonant[i])
                return true;
        return false;
    }


    int numberOfConsonants(char word[50])
    {
        int result = 0;
        int rep = 0;

        for (int i = 0; i < strlen(word); i++)
            for (int j = i + 1; j < strlen(word); j++)
                if ((ds::tolower(word[i]) == ds::tolower(word[j])) and (ds::isConsonant(word[i]) and ds::isConsonant(word[j])))
                {
                    rep++;
                    break;
                    for (int k = 0; k < strlen(word); k++)
                    {
                        if ((ds::tolower(word[j]) == ds::tolower(word[k])) and (ds::isConsonant(word[j]) and ds::isConsonant(word[k])))
                        {
                            rep--;
                            break;
                        }

                    }
                }
        for (int i = 0; i < strlen(word); i++)
        {
            if (ds::isConsonant(word[i]))
            {
                result++;
            }
        }
        result -= rep;
        return result;
    }
    bool WordWithConsonants(char word[50])
    {
        for (int i = 0; i < strlen(word); i++)
            if (ds::isConsonant(word[i]))
                return true;
        return false;
    }

    

  
}




int main()
{
    setlocale(LC_ALL, "Rus");
    

 

    std::cout << "Задача 1" << std::endl;
    int n = 0;
    char word[2000][50];
    char ch = ' ';
    std::ifstream in("input.txt");

    while (!in.eof())
    {
        in >> word[n];
        ds::tolower(word[n]);
        ds::RemovePunctuationInaWord(word[n]);
        n++;        
    }



    for (int i = 0; i < n-1; i++)
    {

        if (ds::WordWithConsonants(word[i]))
            for (int j = i + 1; j < n; j++)
            {
                if (ds::numberOfConsonants(word[i])< ds::numberOfConsonants(word[j]))
                {
                    char tmp[50];
                    strcpy_s(tmp, word[i]);
                    strcpy_s(word[i], word[j]);
                    strcpy_s(word[j], tmp);
                }
            }
    }

    std::ofstream out("output.txt", std::ios::app);
    for (int i = 0; i < n ; i++)
    {
        
        if (strcmp(word[i], word[i + 1]) != 0)
        {
            out << "<" << word[i] << ">" << " " << ds::numberOfConsonants(word[i]) << std::endl;
        }
    }

    std::cout << "слова запасаны в файл output.txt" << std::endl;
    
    
        
       

    
    
 
           

    
            


}


