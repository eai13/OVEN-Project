#include <windows.h>
#include <iostream>
#include <thread>

static uint16_t dead_amount = 0;
static HANDLE map_file;
uint8_t * map_buffer;
static std::thread * oven;

int main(){
    // Creating map file
    map_file = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 256, "watchdog_mapfile12");
    std::cout << "Creating map-file: " << map_file << std::endl;
    map_buffer = (uint8_t *)MapViewOfFile(map_file, FILE_MAP_ALL_ACCESS, 0, 0, 256);
    
    // Resetting the buffer
    map_buffer[0] = 0;

    // Starting thread
    std::thread * oven = new std::thread([](){
        system("release\\OVEN.exe");
    });

    // Watchdog loop
    while(true){
        // Wait
        Sleep(10000);
        std::cout << map_buffer[0] << std::endl;
        // Check the flag
        if (map_buffer[0] != 1){
            system("taskkill /F /IM OVEN.exe");
            oven->join();
            delete oven;
            oven = new std::thread([]{
                system("release\\OVEN.exe");
            });
        }
        else map_buffer[0] = 0;
    }

    return 0;
}