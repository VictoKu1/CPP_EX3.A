#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Able to open the file."){
    CHECK_NOTHROW(ifstream units_file{"units.txt"});
}
//*TODO:Write all planned test here.