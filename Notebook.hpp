#include "Direction.hpp"
#include <string>
#include <vector>

namespace ariel{
    class Notebook{
        private:
            const uint maxcolum = 100;
            std::vector<std::vector<std::vector<char>>> arr_book;
        public:
            void write(uint page, uint row, uint colum, ariel::Direction dir, const std::string &word);
            std::string static read(uint page, uint row, uint colum, ariel::Direction dir, uint length);
            void erase(uint page, uint row, uint colum, ariel::Direction dir, uint length);
            void show(uint page);
    };
}
