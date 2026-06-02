#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "ModulesRudenko.h"

using namespace std;

struct TestCase
{
    string id;
    string action;
    string expected;
};

vector<TestCase> readTestSuite(const string& fileName)
{
    vector<TestCase> tests;

    ifstream fin(fileName);

    if(!fin.is_open())
    {
        cout << "ERROR: Cannot open file: "
             << fileName << endl;
        return tests;
    }

    string line;

    while(getline(fin, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);

        TestCase tc;

        getline(ss, tc.id, ';');
        getline(ss, tc.action, ';');
        getline(ss, tc.expected, ';');

        tests.push_back(tc);
    }

    fin.close();

    return tests;
}

int main()
{
    string testFile =
    "C:/Users/Андрій/Rudenko-Roman-KB25/lab12/TestSuite/TS_12_Rudenko_1.txt";

    string resultFile =
    "C:/Users/Андрій/Rudenko-Roman-KB25/lab12/TestSuite/TestResults.txt";

    vector<TestCase> tests =
        readTestSuite(testFile);

    cout << "Tests loaded: "
         << tests.size()
         << endl;

    ofstream fout(resultFile);

    if(!fout.is_open())
    {
        cout << "ERROR: Cannot create TestResults.txt"
             << endl;
        return 1;
    }

    ClassLab12_Rudenko obj(10, 5, 1);

    for(size_t i = 0; i < tests.size(); i++)
    {
        string result = "";

        if(tests[i].action == "getLength")
        {
            result = to_string((int)obj.getLength());
        }
        else if(tests[i].action == "getWidth")
        {
            result = to_string((int)obj.getWidth());
        }
        else if(tests[i].action == "getHeight")
        {
            result = to_string((int)obj.getHeight());
        }
        else if(tests[i].action == "getSurfaceArea")
        {
            result = to_string((int)obj.getSurfaceArea());
        }
        else if(tests[i].action == "setDimensions(20,10,2)")
        {
            obj.setDimensions(20,10,2);
            result = "OK";
        }

        bool passed =
            (result == tests[i].expected);

        fout << tests[i].id
             << " "
             << (passed ? "passed" : "failed")
             << endl;

        cout << tests[i].id
             << " -> "
             << (passed ? "passed" : "failed")
             << endl;

        if(tests[i].id == "TC09")
        {
            obj = ClassLab12_Rudenko();
        }
    }

    fout.close();

    cout << "\nResults saved to TestResults.txt"
         << endl;
    system("pause");
    return 0;
}
