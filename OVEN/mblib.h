#ifndef OVEN_MODBUS_LIB_H
#define OVEN_MODBUS_LIB_H

#define READ_COILS 	0x03
#define WRITE_COILS 0x10

// Group LvoP (R)
#define STAT    0x0000
#define PV1     0x0100
#define PV2     0x0200
#define LUPV1   0x0300
#define LUPV2   0x0400
// Group LvoP (RW)
#define SP1     0x0500
#define SP2     0x0600
#define r_L1    0x0700
#define r_L2    0x0800
#define rout1   0x0900
#define rout2   0x0A00

#include <iostream>
#include <windows.h>
#include <fstream>

struct modbus_connection{
	public:
		modbus_connection(
                const wchar_t *  	serial_name,
				uint32_t 		baud,
				uint8_t 		stop_bits,
				uint8_t			parity,
				uint8_t			byte_size,
                uint8_t			slave_id,
                std::ofstream * file) : slave_id(slave_id){
            this->slave_serial = ::CreateFile(serial_name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
            this->log_file = file;
            DCB parameters;
			parameters.DCBlength = sizeof(parameters);
			if (!GetCommState(slave_serial, &parameters)){
                std::wcout << "ERROR (" << serial_name << ") : Get State" << std::endl;
				this->CONNECTED_FLAG = 0;
                CloseHandle(this->slave_serial);
                return;
			}
			parameters.BaudRate = baud;
			parameters.ByteSize = byte_size;
			parameters.StopBits = stop_bits;
			parameters.Parity = parity;
			if (!SetCommState(slave_serial, &parameters)){
                std::wcout << "ERROR (" << serial_name << ") : Setting Parameters" << std::endl;
				this->CONNECTED_FLAG = 0;
                CloseHandle(this->slave_serial);
                return;
			}
			else{
                std::wcout << "PARAMETERS SET (" << serial_name << ") : " << baud << " BR, " << (uint16_t)stop_bits << " Stop Bits, " << (uint16_t)parity << " Parity, " << (uint16_t)byte_size << " Byte Size" << std::endl;
				this->CONNECTED_FLAG = 1;
			}
            // Setting up timeouts
            _COMMTIMEOUTS timeout_params;
            timeout_params.ReadIntervalTimeout = 200;
            timeout_params.ReadTotalTimeoutConstant = 200;
            timeout_params.ReadTotalTimeoutMultiplier = 100;
            timeout_params.WriteTotalTimeoutConstant = 200;
            timeout_params.WriteTotalTimeoutMultiplier = 100;
            if (!SetCommTimeouts(this->slave_serial, &timeout_params)){
                *(this->log_file) << "Serial timeout setting error" << std::endl;
                CloseHandle(this->slave_serial);
                return;
            }
            else{
                *(this->log_file) << "Serial timeout setting successful" << std::endl;
            }
            this->busy = 0;
		}
		
        uint8_t check_connection(void){ return CONNECTED_FLAG; }

		uint8_t set_coil(uint16_t address, uint16_t value);
        uint8_t get_coil(uint16_t address, float & value);
        uint8_t get_coil(uint16_t address, int16_t & value);

        void disconnect(void);

        ~modbus_connection(void){ CloseHandle(this->slave_serial); }

	private:
        std::ofstream * log_file;

        uint8_t busy;
		// handles for serial connection
		HANDLE slave_serial;
		DWORD isize;
		// Slave id
		uint8_t slave_id;
		// COM port params
		DCB serial_parameters;
		// Connection flag
		uint8_t CONNECTED_FLAG;
		// Bytes inversion function (0x1122 -> 0x2211)
		uint16_t inverse_bytes(uint16_t data){ return (uint16_t)((data << 8) | (data >> 8)); }
		// CRC constructor
		uint16_t get_CRC(uint8_t * bytes, uint8_t bytes_amount);
};

#endif
