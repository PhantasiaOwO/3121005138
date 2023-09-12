#include "file_io_module.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string load_text(string& path) {
    ifstream file;
    file.open(path, ios::in);
    string ret = "";
    string buf;
    while (getline(file, buf)) {
        ret += buf;
    }
    file.close();
    return ret;
}

void write_answer(string& path, double similarity) {
    ofstream file;
    file.open(path, ios::out);
    file << fixed << setprecision(2) << similarity << endl;
    file.close();
}
