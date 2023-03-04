#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void directory_recursion(string &word, const fs::path &p)
{
    for (const auto &entry : fs::directory_iterator(p))
    {
        if (entry.is_directory())
        {
            directory_recursion(word, entry.path());
        }

        else if (entry.is_regular_file())
            {
                ifstream file(entry.path());
                string line;

                while (getline(file, line))
                {
                    if (line.find(word) != string::npos)
                    {
                        cout << entry << endl;
                    }
                }
            }
    }
}
int main(int argc, char const *argv[])
{
    string word;

    cout << "What word are you looking for?" << endl;
    cin >> word;

    fs::path p = "TestData";

    directory_recursion(word, p);

    return 0;
}
