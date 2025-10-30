#include <iostream>
#include <cstring>
int main(int argc, char** str)
{
    if (argc != 1)
    {
        for (int i = 1; i < argc ; i++)
        {
            for (int j = 0 ; j < (int)strlen(str[i]); j++)
                str[i][j] = toupper(str[i][j]);
        }
        for (int i = 1; i < argc; i++)
            std::cout << str[i]; 
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << "\n";
}
