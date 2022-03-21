#include "Direction.hpp"
#include <string>
#include <vector>

namespace ariel{
    class Notebook{
        private:
            const unsigned int maxcolum = 100;
            std::vector<std::vector<std::vector<char>>> arr_book;
        public:
            void write(unsigned int page, unsigned int row, unsigned int colum, ariel::Direction dir, std::string word);
            std::string read(unsigned int page, unsigned int row, unsigned int colum, ariel::Direction dir, unsigned int length);
            void erase(unsigned int page, unsigned int row, unsigned int colum, ariel::Direction dir, unsigned int length);
            void show(unsigned int page);
    };
}
