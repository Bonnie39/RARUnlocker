#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <Windows.h>

#pragma comment(lib, "winmm.lib")

const int GREEN = 10;
const int RED = 12;
const int DEFAULT_GRAY = 7;

const std::string REG_CONTENT = "RAR registration data\nWinRAR\nUnlimited Company License\nUID = 4b914fb772c8376bf571\n6412212250f5711ad072cf351cfa39e2851192daf8a362681bbb1d\ncd48da1d14d995f0bbf960fce6cb5ffde62890079861be57638717\n7131ced835ed65cc743d9777f2ea71a8e32c7e593cf66794343565\nb41bcf56929486b8bcdac33d50ecf773996052598f1f556defffbd\n982fbe71e93df6b6346c37a3890f3c7edc65d7f5455470d13d1190\n6e6fb824bcf25f155547b5fc41901ad58c0992f570be1cf5608ba9\naef69d48c864bcd72d15163897773d314187f6a9af350808719796";

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

bool isPathValid(const std::string& path) {
    return std::filesystem::exists(path) && std::filesystem::is_directory(path);
}

int main() {
    std::string path, path2;

    std::cout << "Please insert the path for your WinRAR installation (where WinRAR.exe is located) to begin\nFor example: C:/Program Files/WinRAR\n> ";
    std::getline(std::cin, path);
    path2 = path + "\\rarreg.key";

    if (std::filesystem::exists(path2)) {
        setConsoleColor(GREEN);
        std::cout << "WinRAR is already registered on this system.\n";
    }
    else if (!isPathValid(path)) {
        setConsoleColor(RED);
        std::cout << "Invalid path. Please check the correctness of the entered path.\n";
    }
    else if (!std::filesystem::exists(path + "\\WinRAR.exe")) {
        setConsoleColor(RED);
        std::cout << "WinRAR.exe not found in specified path. Please check the correctness of the entered path.\n";
    }
    else {
        setConsoleColor(GREEN);
        std::ofstream outfile(path2);
        outfile << REG_CONTENT;
        outfile.close();
        std::cout << "WinRAR is now fully registered. Enjoy!\n";
    }

    setConsoleColor(DEFAULT_GRAY);
    system("pause");
    return 0;
}
