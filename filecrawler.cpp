
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include <unordered_map> // For bonus exercise
#include <bits/stdc++.h> // For bonus exercise, string manipulation

using namespace std;
namespace fs = std::filesystem;

void search_directories()
{
}

int main()
{
    string word;

    cout << "What word are you looking for?: " << endl;
    cin >> word;

    std::string search_path = "TestData";

    // List directories and files in directory TestData:
    fs::path p;
    for (fs::directory_iterator itr(search_path); itr != fs::directory_iterator(); ++itr)
    {
        if (itr->path().filename() != "." && itr->path().filename() != "..")
        {
            p = itr->path();
            ifstream file(p.string());
            string line;

            if (fs::is_directory(p))
            {
                cout << p.string() << " is a directory." << endl;
            }

            if (!file.is_open())
            {
                cerr << "Failed to open file: " << p.string() << endl;
                continue;
            }

            if (fs::is_regular_file(p) && !p.empty())
            {
                while (getline(file, line))
                {
                    if (line.find(word))
                    {
                        cout << p.string() << endl;
                    }
                }
            }

        }
    }
}
