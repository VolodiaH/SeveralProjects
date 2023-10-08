#include "pwdgenerator.h"

#include <random>
#include <iostream>
#include <format>
#include <array>

static constexpr std::array Symbols { '`', '~', '!', '@', '#', '$', '%', '^', '&', '(', ')', '-', '_', '=', '+', '[', '{', '}', ']', ';', ':', '\'', '\\', '"', '<', ',', '>', '.', '?', '/', '|', '*'};

QString PwdGenerator::generatePassword(const int letters, const int numbers, const int symbols)
{
    const int length{letters + numbers + symbols};
    QString pwd;
    pwd.reserve(length);

    int numbersCount{};
    int symbolsCount{};
    int lettersCount{};

    while (pwd.size() < length)
    {
        const auto character = static_cast<Character>(randomNumber(0,2));
        switch (character)
        {
            case Character::Letter:
                processCharacter(pwd, lettersCount, letters, addLetter);
                break;
            case Character::Number:
                processCharacter(pwd, numbersCount, numbers, addNumber);
               break;
            case Character::Symbol:
                processCharacter(pwd, symbolsCount, symbols, addSymbol);
               break;
        }
    }

    return pwd;
}


int PwdGenerator::randomNumber(const int min, const int max)
{
    static std::random_device generator;
    std::uniform_int_distribution distribution(min, max);
    return distribution(generator);
}

void PwdGenerator::addLetter(QString &pwd)
{
    const bool upper = static_cast<bool>(randomNumber(0,1));
    const char letter { static_cast<char>(upper ? randomNumber('A','Z') : randomNumber('a', 'z')) };
    pwd.push_back(letter);
    std::cerr << std::format("[addLetter] letter:{}\n", letter);
}

void PwdGenerator::addNumber(QString &pwd)
{
    const char number { static_cast<char>(randomNumber(0, 9) + '0') };
    pwd.push_back(number);
    std::cerr << std::format("[addNumber] number:{}\n", number);
}

void PwdGenerator::addSymbol(QString &pwd)
{
    const int index { randomNumber(0, static_cast<int>(Symbols.size() - 1) )};
    const char symbol { Symbols[index]};
    pwd.push_back(symbol);
    std::cerr << std::format("[addSymbol] symbol:'{}', index:{}\n", symbol, index);
}

void PwdGenerator::processCharacter(QString &pwd, int &countee, int count, std::function<void(QString&)> addCharacter)
{
    if (count && countee < count)
    {
        addCharacter(pwd);
        ++countee;
    }
}

