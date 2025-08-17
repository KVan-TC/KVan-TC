#include<bits/stdc++.h>
#include <filesystem>
#include "generator.h"
using namespace std;
namespace fs = std::filesystem;

const string BASE = "TEST";
const string EXEC_1 = "main.exe";
const string EXEC_2 = "solution.exe";
const string IN = "TEST.INP";
const string OUT = "TEST.OUT";
const string ANS = "TEST.ANS";

inline int diff(const string& file1, const string& file2) {
    ifstream f1(file1), f2(file2);
    string s1, s2;
    int line = 1;

    while (getline(f1, s1) && getline(f2, s2)) {
        if (s1 != s2) return line;
        line++;
    }

    if ((getline(f1, s1)) || (getline(f2, s2))) return line;
    return -1;
}


inline void save(int test_id) {
    char foldername[20];
    sprintf(foldername, "%s/%03d", BASE.c_str(), test_id);
    fs::create_directories(foldername);
    fs::copy_file(IN, string(foldername) + "/.INP", fs::copy_options::overwrite_existing);
    fs::copy_file(OUT, string(foldername) + "/.OUT", fs::copy_options::overwrite_existing);
    fs::copy_file(ANS, string(foldername) + "/.ANS", fs::copy_options::overwrite_existing);
}

inline void run(const string& cmd, const string& inp, const string& out) {
    string fullcmd = cmd + " < " + inp + " > " + out;
    system(fullcmd.c_str());
}

inline void compile_if_needed() {
    if (!fs::exists(EXEC_1)) system(("g++ main.cpp -o " + EXEC_1 + " -O2").c_str());
    if (!fs::exists(EXEC_2)) system(("g++ solution.cpp -o " + EXEC_2 + " -O2").c_str());
}

inline void run_tests(int T) {
    srand(time(0));
    fs::create_directories(BASE);
    compile_if_needed();

    int wrong = 0;

    for (int t = 1; t <= T; ++t) {
        gen(t, IN);

        run(EXEC_1, IN, OUT);
        run(EXEC_2, IN, ANS);

        int fail_line = diff(OUT, ANS);
        if (fail_line != -1) {
            cerr << "❌ Test " << t << " sai tại dòng " << fail_line << "\n";
            wrong++;
        } else {
            cerr << "✅ Test " << t << " đúng\n";
        }

        save(t);
    }

    cerr << "\nSố lượng test sai: " << wrong << " / " << T << "\n";
}
