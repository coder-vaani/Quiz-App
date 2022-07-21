// A simple Quiz app - Technical Round - 2, Bugsmirror
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

string student_ans;
int total;

vector<string> v;
void insert(int roll, string name, int score);

class Questions
{
private:
    string q_text, ans1, ans2, ans3, ans4;
    string ans;
    int score;

public:
    void setQuestion(string, string, string, string, string, string, int);
    void ask();
};

int main()
{
    cout << "\n\t\t*** QUIZ PLAY ***\n"
         << endl;
    cout << "Please enter your details to proceed......\n"
         << endl;

    int uid;
    string name;
    cout << "Enter your roll no. (UID): ";
    cin >> uid;

    cout << "Enter your Name: ";
    cin >> name;

    cout << "\n---- Quiz starts now...----" << endl;
    cout << "Choose and just enter your option wisely." << endl;
    cout << "\nAll the best!\n"
         << endl;

    // creating objects for questions
    Questions q1, q2, q3, q4, q5;

    // setting question
    q1.setQuestion("1. What is the capital city of India ?\n",
                   "Mumbai\n", "Kolkata\n", "Delhi\n", "Jaipur\n",
                   "c", 5);

    q2.setQuestion("\n2. What is the currency of USA ?\n",
                   "Dollar\n", "Rupee\n", "Riyal\n", "None of these\n",
                   "a", 5);

    q3.setQuestion("\n3. Who is the father of computers ?\n",
                   "Alexander Thomas\n", "Thomas Alva Edition\n", "Charles Babbage\n", "Ramesh Kumar\n",
                   "c", 5);

    q4.setQuestion("\n4. Which is the highest mountain range in the world ?\n",
                   "Mount Everest\n", "Kanchanjunga\n", "Arabia Hills\n", "None of these\n",
                   "a", 5);

    q5.setQuestion("\n5. Where is Gateway of India located ?\n",
                   "Jaipur\n", "Gandhinagar\n", "Gangtok\n", "Mumbai\n",
                   "d", 5);

    q1.ask();
    q2.ask();
    q3.ask();
    q4.ask();
    q5.ask();

    insert(uid, name, total);
    cout << "\nYour score is: " << total << " out of 25." << endl;
    if (total < 15)
    {
        cout << "\nSorry! You didn't qualify." << endl;
    }
    else
        cout << "\nCongrats! You have passed the quiz.\n"
             << endl;
}

// function to set question
void Questions::setQuestion(string q, string a, string b, string c, string d, string ch, int marks)
{
    q_text = q;
    ans1 = a;
    ans2 = b;
    ans3 = c;
    ans4 = d;
    ans = ch;
    score = marks;
}
// function to ask question
void Questions::ask()
{
    cout << endl;

    cout << q_text << endl;
    cout << "a) " << ans1 << endl;
    cout << "b) " << ans2 << endl;
    cout << "c) " << ans3 << endl;
    cout << "d) " << ans4 << endl;
    cout << endl;
    cout << "\nYour answer ?: ";
    cin >> student_ans;

    v.push_back(student_ans);
    if (student_ans == ans)
    {
        total = total + score;
    }
}

// storing student details and score in a csv file
void insert(int roll, string name, int score)
{
    fstream fout;

    fout.open("score.csv", ios::out | ios::app);

    string ch1, ch2, ch3, ch4, ch5;
    ch1 = v[0];
    ch2 = v[1];
    ch3 = v[2];
    ch4 = v[3];
    ch5 = v[4];

    fout << roll << ", " << name << ", " << ch1 << ", " << ch2 << ", " << ch3 << ", " << ch4 << ", " << ch5 << ", " << score << endl;
}