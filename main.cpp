// DZ 18.12.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include "user.h"
#include "message.h"
#include "chat.h"

// Файлы для хранения данных
const std::string userFile = "user.dat";
const std::string messageFile = "messages.dat";

int main() {

    setlocale(LC_ALL, "");
    User currentUser;

    // Попытка загрузить существующего пользователя
    if (currentUser.loadFromFile(userFile)) {
        std::cout << "Загружен пользователь: " << currentUser.getName() << "\n";
    }
    else {
        // Создание нового пользователя
        std::string name, login, pass;
        std::cout << "Создайте нового пользователя.\n";
        std::cout << "Имя: ";
        std::getline(std::cin, name);
        std::cout << "Логин: ";
        std::getline(std::cin, login);
        std::cout << "Пароль: ";
        std::getline(std::cin, pass);

        currentUser.setName(name);
        currentUser.setLogin(login);
        currentUser.setPass(pass);

        currentUser.saveToFile(userFile);
    }

    // Загрузка существующих сообщений
    Chat chat;
    chat.loadFromFile(messageFile);

    // Ввод сообщения
    std::string text, sender, receiver;
    std::cout << "Введите сообщение: ";
    std::getline(std::cin, text);
    std::cout << "От кого: ";
    std::getline(std::cin, sender);
    std::cout << "Кому: ";
    std::getline(std::cin, receiver);

    // Создание сообщения и добавление в чат
    Message msg(text, sender, receiver);
    chat.addMessage(msg);

    // Сохранение сообщений
    chat.saveToFile(messageFile);

    // Вывод всех сообщений
    std::cout << "\nВсе сообщения:\n";
    chat.showMessages();

    return 0;
}