#pragma once

#include <string>

namespace Employee {
    class employee{
        private:
            int bankValue;
            std::string employeeName;
        public:
            employee(){
                bankValue = 0;
            }
            employee(std::string name){
                bankValue = 0;
                employeeName = name;
            }
            inline int getBanValue() const {return bankValue;}
            inline std::string getName() const {return employeeName;}
            inline void payEmployee(int amount) { bankValue = bankValue + amount;};
    };
}
