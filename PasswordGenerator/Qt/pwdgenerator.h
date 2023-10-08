#ifndef PWDGENERATOR_H
#define PWDGENERATOR_H

#include <functional>
#include <QString>

enum class Character
{
    Letter,
    Number,
    Symbol
};

class PwdGenerator
{
public:
    static QString generatePassword(int letters, int numbers, int symbols);

private:
    static int randomNumber(const int min, const int max);
    static void addLetter(QString &pwd);
    static void addNumber(QString &pwd);
    static void addSymbol(QString &pwd);

    static void processCharacter(QString &pwd, int &countee, int count, std::function<void(QString&)> addCharacter);
};

#endif // PWDGENERATOR_H
