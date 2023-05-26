#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> responses;
    responses["Hello"] = "Hi! How may I help you?";
    responses["Hi"] = "Hello! How may I help you?";
    responses["How are you?"] = "I am good. What about you?";
    responses["I am fine"] = "That's great! How may I help you?";
    responses["Recharge plans"] = "These are some Popular Combo Plans:\n"
                                  " Rs. 299 ------> Unlimited Calls + 1.5Gb/day for 28 days\n"
                                  " Rs. 719 ------> Unlimited Calls + 1.5Gb/day for 84 days\n"
                                  " Rs. 399 ------> Unlimited Calls + 2.5Gb/day for 28 days\n"
                                  " Rs. 499 ------> Unlimited Calls + 3Gb/day for 28 days";
    responses["Data plans"] = "These are some Popular Data Plans:\n"
                              " Rs. 151 ------> 8Gb for 30 days\n"
                              " Rs. 108 ------> 6Gb for 15 days\n"
                              " Rs. 58 ------> 3Gb for 28 days\n"
                              " Rs. 39 ------> 3Gb for 7 days\n"
                              " Rs. 75 ------> 6Gb for 7 days";
    responses["Validity plans"] = "These are some Popular Validity Plans:\n"
                                  " Rs. 99 ------> Rs. 99 talktime + 200Mb for 28 days\n"
                                  " Rs. 279 ------> Rs. 279 talktime+ 500Mb for 90 days\n"
                                  " Rs. 107 ------> Rs. 107 talktime + 200Mb for 30 days\n"
                                  " Rs. 111 ------> Rs. 111 talktime + 200Mb for 28 days";
    responses["Yearly plans"] = "These are some Popular Yearly Plans:\n"
                                " Rs. 3099 ------> Unlimited Calls + 2Gb/day for 365 days\n"
                                " Rs. 2999 ------> Unlimited Calls + 850Gb for 365 days\n"
                                " Rs. 2899 ------> Unlimited Calls + 1.5Gb/day for 365 days\n"
                                " Rs. 1799 ------> Unlimited Calls + 24Gb for 365 days";
    responses["Thank you"] = "Welcome :)";

    string input;
    cout << "Enter something to talk with the ChatBot\n";
    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        if (input == "quit" || input == "Quit" || input == "Exit" || input == "exit") {
            cout << "\nChatBot: Thank You :)\n";
            break;
        }

        if (responses.find(input) == responses.end() || input == "") {
            cout << "\nChatBot: Sorry for the inconvenience. However, I can only answer the following questions:\n"
                 << "1. Recharge plans\n"
                 << "2. Yearly plans\n"
                 << "3. Data plans\n"
                 << "4. Validity plans\n"
                 << "5. Quit/Exit\n"
                 << "Hope you understand :)\n";
        } else {
            cout << "\nChatBot: " << responses[input] << "\n";
        }
    }

    return 0;
}
