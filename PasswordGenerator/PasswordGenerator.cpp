
#include <iostream>
#include <random>

static const std::string symbols {"`~!@#$%^&*()-_=+[{}];:'\"<,>.?/\\|*"};

enum PasswordType
{
    Number = 1 << 0,
    Symbol = 1 << 1,
    Letter = 1 << 2
};

enum class Character
{
    Letter = 0,
    Number = 1,
    Symbol = 2
};

int randomNumber(int min, int max)
{
    static std::random_device generator;
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}

void addLetter(std::string &pwd)
{
    const bool upper = randomNumber(0,1);
    pwd.push_back(upper ? randomNumber('A','Z') : randomNumber('a', 'z'));
}

void addNumber(std::string &pwd)
{
    pwd.push_back(randomNumber(0, 9) + '0');
}

void addSymbol(std::string &pwd)
{
    pwd.push_back(symbols[randomNumber(1, symbols.size() - 1)]);
}

int main()
{
    std::cout << "Password length\n";

    size_t length{};
    std::cin >> length;

    std::cout << "Does it include numbers? (y,n)\n";

    PasswordType pwdType{};
    char answer{};
    std::cin >> answer;

    pwdType = static_cast<PasswordType>( static_cast<int>(pwdType) | ((answer == 'y') ? Number : 0));

    std::cout << "Does it include symbols? (y,n)\n";
    std::cin >> answer;

    pwdType = static_cast<PasswordType>(static_cast<int>(pwdType) | ((answer == 'y') ? Symbol : 0));
    
    std::string pwd;
    pwd.reserve(length);

    while (pwd.size() < length)
    {
        Character character = static_cast<Character>(randomNumber(0,2));
        switch (character)
        {
        case Character::Letter: addLetter(pwd); break;
        case Character::Number: 
            if (pwdType & Number) 
                addNumber(pwd); break;
        case Character::Symbol: 
            if (pwdType & Symbol) 
                addSymbol(pwd); break;
        }
    }

    std::cout << "\n\nPWD: " << pwd;

}

