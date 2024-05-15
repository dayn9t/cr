
#include <cr/geo.hpp>

#include <cr/test.hpp>


namespace {

	template<typename T>
	void test()
	{
		Point2D<T> p0;
		Size2D<T> s0;
		Size2D<T> s1(1, 1);
		Rectangle<T> r0;

		TR(r0.location() == p0);
		TR(r0.size() == s0);
	}
}

TEST(Rect, ctor)
{
	test<int>();
	test<float>();
	test<double>();
}

TEST(Rect, add_sub)
{
	Rect r0{};
	Rect r1{1, 1, 0, 0};
	Point p1{ 1, 1 };

	TR(r1 - p1 == r0);

	TR(r1 == r0 + p1);
}


TEST(Rect, rect_blocks)
{
	Rect r{ 12, 12 };

	vector<Rect> rs11{r};
	TR(rs11 == rect_blocks(r, 1, 1));
	TR(rs11 == to_blocks(r, Size(12, 12)));

	vector<Rect> rs12{ {0, 0, 12, 6}, {0, 6, 12, 6} };
	TR(rs12 == rect_blocks(r, 1, 2));
	TR(rs12 == to_blocks(r, Size(12, 6)));

	vector<Rect> rs32{ 
		{ 0, 0, 4, 6 },{ 4, 0, 4, 6 },{ 8, 0, 4, 6 },
		{ 0, 6, 4, 6 },{ 4, 6, 4, 6 },{ 8, 6, 4, 6 },
	};
	TR(rs32 == rect_blocks(r, 3, 2));
	TR(rs32 == to_blocks(r, Size(4, 6)));
}


TEST(Rect, bounding_rect)
{
	Rect tab[][3] = {
			{{0, 0, 4, 4}, {0, 0, 4, 4}},
			{{0, 0, 4, 4}, {0, -2, 4, 8}},
			{{0, 0, 4, 4}, {-2, 0, 8, 4}},
	};

	Size aspect[] = {
			{1, 1},
			{1, 2},
			{2, 1},
	};

	for(int i = 0; i < 3; ++i) {
		TR(tab[i][1] == bounding_rect(tab[i][0], aspect[i]));
		TR(tab[i][1].center() == tab[i][0].center());
	}
}
