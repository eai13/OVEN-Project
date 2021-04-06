#include <windows.h>
#include <thread>

int main(){
    std::thread th([](){
        system("start /MIN wd.exe");
    });
    th.detach();
    Sleep(500);
    return 0;
}