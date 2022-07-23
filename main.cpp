#include <iostream>
#include <fstream>  
#include <string>
#include <filesystem>
#pragma comment(lib, "winmm.lib")
#include <Windows.h>

int main()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::string path;
    std::string path2;

    int green = 10;
    int red = 12;
    int default_gray = 7;

    std::string regcontent = "RAR registration data\nWinRAR\nUnlimited Company License\nUID = 4b914fb772c8376bf571\n6412212250f5711ad072cf351cfa39e2851192daf8a362681bbb1d\ncd48da1d14d995f0bbf960fce6cb5ffde62890079861be57638717\n7131ced835ed65cc743d9777f2ea71a8e32c7e593cf66794343565\nb41bcf56929486b8bcdac33d50ecf773996052598f1f556defffbd\n982fbe71e93df6b6346c37a3890f3c7edc65d7f5455470d13d1190\n6e6fb824bcf25f155547b5fc41901ad58c0992f570be1cf5608ba9\naef69d48c864bcd72d15163897773d314187f6a9af350808719796";
    
    
    std::cout << "Please insert the path for your WinRAR installation (where WinRAR.exe is located) to begin\nFor example: C:/Program Files/WinRAR\n";
    std::cout << "> ";

    std::getline(std::cin, path);
    path2 = path + "\\rarreg.key";

    if (std::filesystem::exists(path2))
    {
        SetConsoleTextAttribute(hConsole, green);
        std::cout << "WinRAR is already registered on this system.\n";
        SetConsoleTextAttribute(hConsole, default_gray);
        system("pause");
        std::cin;
    }
    else if (!std::filesystem::exists(path))
    {
        SetConsoleTextAttribute(hConsole, red);
        std::cout << "Path not found. (Could you have entered it incorrectly?)\n";
        SetConsoleTextAttribute(hConsole, default_gray);
        system("pause");
        std::cin;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, green);
        std::ofstream outfile(path2);
        outfile << regcontent;
        outfile.close();
        std::cout << "WinRAR is now fully registered. Enjoy!\n";
        SetConsoleTextAttribute(hConsole, default_gray);
        system("pause");
        std::cin;
    }
}

