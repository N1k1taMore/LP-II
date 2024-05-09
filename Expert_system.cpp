#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class MedExp{
    private:
    string pname,another_sym,input,diabetes_sym,hyper_sym,covid_sym;
    int age,sym_no,cnt;
    const int threshold=3;

    public:
    MedExp(){
        cnt=0;
    }

    void get_info(){
        cout<<"Enter Patient's name :";
        cin>>pname;
        cout<<"Enter Patient's age :";
        cin>>age;
    }
    string toLowercase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    void med_input(){
        cout<<"Various Symptoms list is given below :\n";
        cout<<"1.Cough\n2.Itchiness\n3.Headache\n";
        cout<<"Enter the number of symptoms you have from the given list:";
        cin>>sym_no;
        cout<<"Are you feeling any other symptoms also? [Enter yes/no]";
        cin>>another_sym;

        string opt=another_sym;
        toLowercase(opt);

        if(opt=="no"){
            if(sym_no==1){
                cout << "Relax you may be suffering from normal viral flu.\nMedicine: Cofsils Orange Lozenges Strip Of 10\nIf symptoms increase kindly contact the doctor\n";
            }
            else if(sym_no==0){
                cout<<"Ok then Stay Healthy !\n";
            }
            else{
                cout<<"Kindly contact the doctor you show mild symptoms of Flu.\n";
            }
        }
        else{
            cout<<"Describe your symptoms: (fever,sore throat, runny/stuffy nose, muscle/body aches, headache )\n";
            cin.ignore();
            getline(cin,input);// Get the entire line of symptoms description

             // Convert the input to lowercase for easier comparison
            toLowercase(input)

            cnt=0;
            if(input.find("fever") != string::npos){
                cnt++;
            }
            if(input.find("sore throat") != string::npos){
                cnt++;
            }
            if(input.find("runny/stuffy nose") != string::npos){
                cnt++;
            }
            if(input.find("muscle/body aches") != string::npos){
                cnt++;
            }
            if(input.find("headache") != string::npos){
                cnt++;
            }

            if(cnt >= threshold){
                cout << "\n\nYou may have Influenza (Flu).Contact the Doctor. The Treatment is: Rest, hydration, over-the-counter pain relievers (such as ibuprofen or acetaminophen) to reduce fever and relieve symptoms.\n\n";
            }
            else{
                cout<<"\n Ok .You may take some antiviral medications like 'Aspirin'.\n\n";
            }

        }
    }

    void diabetes_check(){
        cout<<"Do you have symptoms like increased thirst,frequent urination,fatigue,blurred vision,unexplained weight loss? [yes/no]\n";
        cin>>diabetes_sym;
        string opt1=diabetes_sym;
        toLowercase(opt1);
        if(opt1=="no"){
            cout<<"No worries!!\n";
        }
        else{
            cout<<"Describe your symptoms related to Diabetes: (increased thirst,frequent urination,fatigue, blurred vision, unexplained weight loss)\n";
             cin.ignore();
             getline(cin,input);
              // Convert the input to lowercase for easier comparison
            toLowercase(input);

            cnt=0;
            if(input.find("increased thirst" )!= string::npos){
                cnt++;
            }
            if(input.find("frequent urination" )!= string::npos){
                cnt++;
            }
            if(input.find("fatigue" )!= string::npos){
                cnt++;
            }
            if(input.find("blurred vision" )!= string::npos){
                cnt++;
            }
            if(input.find("unexplained weight loss" )!= string::npos){
                cnt++;
            }
             if(cnt >= threshold){
                 cout << "You may have Type 2 Diabetes. Try to contact the doctor.The Treatment: Lifestyle changes including diet modification and exercise,oral medications such as metformin to lower blood sugar levels, insulin injections in some cases, regular monitoring of blood sugar levels.\n";
            } 
            else {
                cout <<"Ok. You may have felt such symptoms due to increase in blood sugar (glucose)\nkindly check your sugar level and contact the doctors'.\n";
            }
        }
    }
    void hypertension_check(){
        cout << "\n\nDo you have symptoms like shortness of breath, nosebleeds,dizziness? [Yes/No]\n";
        cin>>hyper_sym;
        string opt2 = hyper_sym;
        toLowercase(opt2);
        if(opt2 == "no"){
            cout<<"No worries!!\n\n";
        }
        else{
            cout << "\n\n Describe your symptoms related to Hypertension: (shortness of breath, nosebleeds, dizziness) \n";
            cin.ignore();
            getline(cin, input); // Get the entire line of symptoms description

            // Convert the input to lowercase for easier comparison
            toLowercase(input);

            // Check for symptoms mentioned in the input sentence
            cnt = 0;
            if (input.find("shortness of breath") != string::npos) {
                cnt++;
            }
            if (input.find("nosebleeds") != string::npos) {
                cnt++;
            }
            if (input.find("dizziness") != string::npos) {
                cnt++;
            }

            // Check for the threshold value
            if (cnt >= threshold) {
                cout << "\nYou may have Hypertension (High Blood Pressure).Contact a specialist.The Treatment is: Lifestyle changes including a low-sodium diet, regular exercise, weight loss if overweight, medication such as ACE inhibitors, beta-blockers, calcium channel blockers, or diuretics to lower blood pressure.\n";
            }
            else {
                cout << "\nOk. You may be suffering from mild migraine headaches.Contact doctor.\n";
            }
        }
    }
    void covid_check(){
        cout<<"Do you have any symptoms like cough,sorethroat,excessive sweating,itchy throat,runny nose,headache,feeling exhausted? [yes/no]\n";
        cin>>covid_sym;
        string opt3=covid_sym;
        toLowercase(opt3);

        if(opt3=="no"){
            cout<<"No worries!!\n";
        }
        else{
            cout<<"Describe your symptoms related to cough,fever,sorethroat,excessive sweating,itchy throat,runny nose,headache,feeling exhausted :\n";
            cin.ignore();
            getline(cin,input);
            toLowercase(input);

            cnt=0;
            if(input.find("cough")!=string::npos){
                cnt++;
            }
            if(input.find("sorethroat")!=string::npos){
                cnt++;
            }
            if(input.find("fever")!=string::npos){
                cnt++;
            }
            if(input.find("excessive sweating")!=string::npos){
                cnt++;
            }
            if(input.find("runny nose")!=string::npos){
                cnt++;
            }
            if(input.find("itchy throat")!=string::npos){
                cnt++;
            }
            if(input.find("headache")!=string::npos){
                cnt++;
            }
            if(input.find("feeling exhausted")!=string::npos){
                cnt++;
            }

            if(cnt>threshold){
                cout << "Based on your answers, You are showing Symptoms of SEVERE COVID-19\n";
                cout << "You are advised to contact a COVID-19 Specialist ASAP\n";
            }
            else{
                cout << "Based on your answers, You are showing Symptoms of VERY MILD COVID-19\n";
                cout << "Please Isolate yourself Immediately on a precautionary basis\n";
            }
        }
    }
};
int main(){
    MedExp m;
    m.get_info();
    m.med_input();
    m.diabetes_check();
    m.hypertension_check();
    m.covid_check();
}