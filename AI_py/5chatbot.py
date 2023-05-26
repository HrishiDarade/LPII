def main():
    responses = {
        "Hello": "Hi! How may I help you?",
        "Hi": "Hello! How may I help you?",
        "How are you?": "I am good. What about you?",
        "I am fine": "That's great! How may I help you?",
        "Recharge plans": "These are some Popular Combo Plans:\n"
                          " Rs. 299 ------> Unlimited Calls + 1.5Gb/day for 28 days\n"
                          " Rs. 719 ------> Unlimited Calls + 1.5Gb/day for 84 days\n"
                          " Rs. 399 ------> Unlimited Calls + 2.5Gb/day for 28 days\n"
                          " Rs. 499 ------> Unlimited Calls + 3Gb/day for 28 days",
        "Data plans": "These are some Popular Data Plans:\n"
                      " Rs. 151 ------> 8Gb for 30 days\n"
                      " Rs. 108 ------> 6Gb for 15 days\n"
                      " Rs. 58 ------> 3Gb for 28 days\n"
                      " Rs. 39 ------> 3Gb for 7 days\n"
                      " Rs. 75 ------> 6Gb for 7 days",
        "Validity plans": "These are some Popular Validity Plans:\n"
                          " Rs. 99 ------> Rs. 99 talktime + 200Mb for 28 days\n"
                          " Rs. 279 ------> Rs. 279 talktime+ 500Mb for 90 days\n"
                          " Rs. 107 ------> Rs. 107 talktime + 200Mb for 30 days\n"
                          " Rs. 111 ------> Rs. 111 talktime + 200Mb for 28 days",
        "Yearly plans": "These are some Popular Yearly Plans:\n"
                        " Rs. 3099 ------> Unlimited Calls + 2Gb/day for 365 days\n"
                        " Rs. 2999 ------> Unlimited Calls + 850Gb for 365 days\n"
                        " Rs. 2899 ------> Unlimited Calls + 1.5Gb/day for 365 days\n"
                        " Rs. 1799 ------> Unlimited Calls + 24Gb for 365 days",
        "Thank you": "Welcome :)"
    }

    print("Enter something to talk with the ChatBot")
    while True:
        user_input = input("\nYou: ")

        if user_input.lower() in ["quit", "exit"]:
            print("\nChatBot: Thank You :)")
            break

        if user_input in responses:
            print("\nChatBot:", responses[user_input])
        else:
            print("\nChatBot: Sorry for the inconvenience. However, I can only answer the following questions:\n"
                  "1. Recharge plans\n"
                  "2. Yearly plans\n"
                  "3. Data plans\n"
                  "4. Validity plans\n"
                  "5. Quit/Exit\n"
                  "Hope you understand :)")

if __name__ == "__main__":
    main()
