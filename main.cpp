#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <thread>
#include "responses.h"

std::string previousQuery = "";

std::string generateResponse(const std::string& userInput) {
    std::string response = "I'm sorry, I don't know what you mean.";
    std::string lowerCaseInput = userInput;
    std::transform(lowerCaseInput.begin(), lowerCaseInput.end(), lowerCaseInput.begin(), ::tolower);

    for (const auto& pair : responseMap) {
        const std::string& keyword = pair.first;
        if (lowerCaseInput.find(keyword) != std::string::npos) {
            const std::vector<std::string>& possibleResponses = pair.second;
            int index = std::rand() % possibleResponses.size();
            response = possibleResponses[index];
            break;
        }
    }

    if (lowerCaseInput == previousQuery) {
        response = "We've already discussed that. Let's talk about something else.";
    }
    else if (lowerCaseInput == "ok" || lowerCaseInput == "okay") {
        response = "If you still have questions, feel free to ask!";
    }

    previousQuery = lowerCaseInput;

    return response;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    SetConsoleTitleA("Fake-AI");
    std::cout << "Chat Application\n";
    std::cout << "Enter 'exit' to quit.\n";
    std::cout << "Please only use lowercase letters - for now.\n";

    while (true) {
        std::string userInput;
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (userInput == "exit") {
            break;
        }

        if (userInput == "bye") {
            std::cout << "Goodbye.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            break;
        }

        if (userInput == "goodbye") {
            std::cout << "Goodbye.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            break;
        }

        if (userInput == "ciao") {
            std::cout << "Goodbye.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            break;
        }

        std::string response = generateResponse(userInput);
        std::cout << "AI: " << response << "\n";
    }

    return 0;
}