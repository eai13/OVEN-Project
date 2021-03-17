#include "mblib.h"
#include <iostream>
#include <windows.h>

uint8_t modbus_connection::set_coil(uint16_t address, uint16_t value){
    if (this->busy == 1){
        std::cout << "set_coil BUSY" << std::endl;
        return 1;
    }
    this->busy = 1;
	// Preparing the package
	uint8_t 	command = WRITE_COILS;
	uint16_t 	start_reg = address;
	uint16_t 	regs_amount = 0x0100;
	uint8_t 	next_bytes = 0x02;
	uint16_t 	data = inverse_bytes(value);
	// Array for getting the CRC
	uint8_t bytes[64] = {this->slave_id, command, (uint8_t)start_reg, (uint8_t)(start_reg >> 8), 0x00, 0x01, next_bytes, (uint8_t)data, (uint8_t)(data >> 8)};
	uint16_t 	CRC = get_CRC(bytes, 9);
	// Writing the package to the net
    std::cout << "set_coil 1";
    while(WriteFile(this->slave_serial, &(this->slave_id), 1, &(this->isize), 0) == 0){std::cout << "Error writing 1" << std::endl;}
    std::cout << "2";
    while(WriteFile(this->slave_serial, &command, 1, &(this->isize), 0) == 0){std::cout << "Error writing 2" << std::endl;}
    std::cout << "3";
    while(WriteFile(this->slave_serial, &start_reg, 2, &(this->isize), 0) == 0){std::cout << "Error writing 3" << std::endl;}
    std::cout << "4";
    while(WriteFile(this->slave_serial, &regs_amount, 2, &(this->isize), 0) == 0){std::cout << "Error writing 4" << std::endl;}
    std::cout << "5";
    while(WriteFile(this->slave_serial, &next_bytes, 1, &(this->isize), 0) == 0){std::cout << "Error writing 5" << std::endl;}
    std::cout << "6";
    while(WriteFile(this->slave_serial, &data, 2, &(this->isize), 0) == 0){std::cout << "Error writing 6" << std::endl;}
    std::cout << "7";
    while(WriteFile(this->slave_serial, &CRC, 2, &(this->isize), 0) == 0){std::cout << "Error writing 7" << std::endl;}
    std::cout << "8";
    Sleep(50);
	// Read the serial port
    std::cout << "9";
    ReadFile(this->slave_serial, bytes, 8, &(this->isize), 0);\
    std::cout << "A" << std::endl;
	// If no coils were set then error
    this->busy = 0;
	if (bytes[5] != 0) return 0;
	else return 1;
}

uint8_t modbus_connection::get_coil(uint16_t address, float & value){
    if (this->busy == 1){
        std::cout << "get_coil_fl BUSY" << std::endl;
        value = 0;
        return 1;
    }
    this->busy = 1;
	// Preparing the package
	uint8_t		command = READ_COILS;
	uint16_t	start_reg = address;
	uint16_t	regs_amount = 0x0100;
	// Array for getting the CRC
	uint8_t bytes[64] = {this->slave_id, command, (uint8_t)start_reg, (uint8_t)(start_reg >> 8), 0x00, 0x01};
	uint16_t	CRC = get_CRC(bytes, 6);
    // Writing the package to the net
    std::cout << "get_coil_fl 1";
    while(WriteFile(this->slave_serial, &(this->slave_id), 1, &(this->isize), 0) == 0){std::cout << "Error writing 0" << std::endl;}
    std::cout << "2";
    while(WriteFile(this->slave_serial, &command, 1, &(this->isize), 0) == 0){std::cout << "Error writing 1" << std::endl;}
    std::cout << "3";
    while(WriteFile(this->slave_serial, &start_reg, 2, &(this->isize), 0) == 0){std::cout << "Error writing 2" << std::endl;}
    std::cout << "4";
    while(WriteFile(this->slave_serial, &regs_amount, 2, &(this->isize), 0) == 0){std::cout << "Error writing 3" << std::endl;}
    std::cout << "5";
    while(WriteFile(this->slave_serial, &CRC, 2, &(this->isize), 0) == 0){std::cout << "Error writing 4" << std::endl;}
    std::cout << "6";
    Sleep(50);
    // Read the serial port
    std::cout << "7";
    if (ReadFile(this->slave_serial, bytes, 7, &(this->isize), 0) == 0){
        this->busy = 0;
        std::cout << "8_1" << std::endl;
        return 1;
    }
	else{
        int16_t output = ((bytes[3] << 8) | bytes[4]);
        value = (float)output / 10;
        this->busy = 0;
        std::cout << "8_2" << std::endl;
		return 0;
	}
}

uint8_t modbus_connection::get_coil(uint16_t address, int16_t & value){
    if (this->busy == 1){
        std::cout << "get_coil_int BUSY" << std::endl;
        value = 0;
        return 1;
    }
    this->busy = 1;
    // Preparing the package
    uint8_t		command = READ_COILS;
    uint16_t	start_reg = address;
    uint16_t	regs_amount = 0x0100;
    // Array for getting the CRC
    uint8_t bytes[64] = {this->slave_id, command, (uint8_t)start_reg, (uint8_t)(start_reg >> 8), 0x00, 0x01};
    uint16_t	CRC = get_CRC(bytes, 6);
    // Writing the package to the net
    std::cout << "get_coil_int 1";
    while(WriteFile(this->slave_serial, &(this->slave_id), 1, &(this->isize), 0) == 0){std::cout << "Error writing 0" << std::endl;}
    std::cout << "2";
    while(WriteFile(this->slave_serial, &command, 1, &(this->isize), 0) == 0){std::cout << "Error writing 1" << std::endl;}
    std::cout << "3";
    while(WriteFile(this->slave_serial, &start_reg, 2, &(this->isize), 0) == 0){std::cout << "Error writing 2" << std::endl;}
    std::cout << "4";
    while(WriteFile(this->slave_serial, &regs_amount, 2, &(this->isize), 0) == 0){std::cout << "Error writing 3" << std::endl;}
    std::cout << "5";
    while(WriteFile(this->slave_serial, &CRC, 2, &(this->isize), 0) == 0){std::cout << "Error writing 4" << std::endl;}
    std::cout << "6";
    Sleep(50);
    // Read the serial port
    std::cout << "7";
    if (ReadFile(this->slave_serial, bytes, 7, &(this->isize), 0) == 0){
        this->busy = 0;
        std::cout << "8_1" << std::endl;
        return 1;
    }
    else{
        value = ((bytes[3] << 8) | bytes[4]);
        this->busy = 0;
        std::cout << "8_2" << std::endl;
        return 0;
    }
}

uint16_t modbus_connection::get_CRC(uint8_t * bytes, uint8_t bytes_amount){  
	// Initializing the CRC as FFFF
	uint16_t crc = 0xFFFF;
	// For each byte in the package
	for (int pos = 0; pos < bytes_amount; pos++){
		// XOR the CRC with the byte
		crc ^= (uint16_t)bytes[pos];
		// Do the operation for 8 times
		for (int i = 8; i != 0; i--) {
			// If the LSB is not zero the XOR with A001
			if ((crc & 0x0001) != 0) {
				crc >>= 1;
				crc ^= 0xA001;
			}
			// Else shift right
			else crc >>= 1;
		}
	}
	return crc;
}

void modbus_connection::disconnect(void){
    this->~modbus_connection();
}
