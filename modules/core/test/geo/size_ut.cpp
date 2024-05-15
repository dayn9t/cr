
#include <cr/geo.hpp>
#include <cr/test.hpp>


TEST(Size, ctor)
{

}

TEST(Size, bounding_size)
{
    Size tab[][3] = {
            {{4, 4}, {1, 1}, {4, 4}},
            {{4, 4}, {1, 2}, {4, 8}},
            {{4, 4}, {2, 1}, {8, 4}},
    };

	for(auto& arr : tab) {
	    TR(arr[2] == bounding_size(arr[0], arr[1]));
	}
}

