#include <iostream>
#include <string>
#include <map>
#include <algorithm> // for std::transform

using namespace std;

// Define responses for various user queries
map<string, string> responses = {
    {"hi", "Hello! Welcome to Hospital Services. How can I assist you today?"},
    {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
    {"bye", "Goodbye! Take care and stay healthy!"},
    {"name", "Our hospital's name is HealthCare Hospital."},
    {"address", "We are located at 123 Main Street, Anytown, USA."},
    {"departments", "We have several departments including Cardiology, Oncology, Neurology, Orthopedics, and Pediatrics."},
    {"emergency", "In case of emergency, please call 911 or visit the nearest emergency room immediately."},
    {"time","Weekdays:8 AM  to 8 PM and 1PM-2PM lunch break .Weekend closed"},
    {"appointments", "To schedule an appointment, please call our appointment desk at (555) 123-4567 or visit our website."},
    {"visiting hours", "Our visiting hours are from 9:00 AM to 5:00 PM every day."},
    {"insurance", "We accept most major insurance plans. Please contact our billing department for specific inquiries about insurance coverage."},
    {"services", "We offer a wide range of medical services including diagnostics, surgeries, treatments, and rehabilitation programs."},
    {"doctors", "We have a team of experienced and qualified doctors specialized in various medical fields. You can find more information about our doctors on our website."},
    {"facilities", "Our hospital facilities include state-of-the-art medical equipment, comfortable patient rooms, cafeteria, and parking."},
    {"feedback", "We value your feedback! Please share your experience with us to help us improve our services. You can leave feedback on our website or contact our patient relations department."},
    {"contact", "You can contact us at (555) 123-4567 during business hours (9 AM to 5 PM, Monday to Friday). You can also email us at info@healthcarehospital.com."},
    {"covid-19", "We have implemented strict safety measures to protect our patients and staff from COVID-19. Please follow all safety protocols when visiting the hospital."},
    {"visitors policy", "Due to COVID-19, we have restricted visitor policies in place. Please check our website or contact our front desk for the latest visitor guidelines."},
    {"billing", "For billing inquiries, please contact our billing department at (555) 987-6543 or visit our website for online bill payment options."}
};

// Function to convert a string to lowercase
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to get response from the chatbot
string getResponse(const string& userQuery) {
    string query = toLowercase(userQuery);

    // Check if user query exists in responses (case insensitive)
    auto it = responses.find(query);
    if (it != responses.end()) {
        return it->second;
    } else {
        // Iterate over the responses map and check if any key is present in the user query
        for (const auto& pair : responses) {
            if (query.find(pair.first) != string::npos) {
                return pair.second;
            }
        }
        return "Sorry, I didn't understand your query. Could you please rephrase?";
    }
}

// Main function
int main() {
    cout << "Welcome to Hospital Information Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userQuery;
    while (true) {
        cout << "User: ";
        getline(cin, userQuery);

        if (toLowercase(userQuery) == "bye") {
            cout << "Chatbot: Goodbye! Take care and stay healthy!" << endl;
            break;
        }

        string response = getResponse(userQuery);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
