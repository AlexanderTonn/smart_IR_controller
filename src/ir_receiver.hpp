// IR Receiver handler 
#ifndef IR_HANDLE_H
#define IR_HANDLE_H

#include <Vector.h>

class IR_Handle{

    private: 

    public: 
        auto init(const uint16_t , const bool ) -> void;
        auto run() -> int;
};

#endif