#pragma once

//#include <cr/geo.hpp/core/pixel.hpp>
#include <cr/geo.hpp>
#include <opencv2/core/core.hpp>

namespace ica {

	template<typename _Tp> class DataType
	{
	public:
		typedef _Tp         value_type;
		typedef value_type  work_type;
		enum {
			depth = -1,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<uchar>
	{
	public:
		typedef uchar       value_type;
		typedef int         work_type;
		enum {
			depth = CV_8U,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<ushort>
	{
	public:
		typedef ushort      value_type;
		typedef int         work_type;
		enum {
			depth = CV_16U,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<int>
	{
	public:
		typedef int         value_type;
		typedef value_type  work_type;
		enum {
			depth = CV_32S,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<float>
	{
	public:
		typedef float       value_type;
		typedef value_type  work_type;
		enum {
			depth = CV_32F,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<double>
	{
	public:
		typedef double      value_type;
		typedef value_type  work_type;
		enum {
			depth = CV_64F,
			channels = 1,
			type = CV_MAKETYPE(depth, channels)
		};
	};
#if 0
	template<> class DataType<iv::U3C>
	{
	public:
		typedef uchar       value_type;
		typedef int         work_type;
		enum {
			depth = CV_8U,
			channels = 3,
			type = CV_MAKETYPE(depth, channels)
		};
	};

	template<> class DataType<iv::U4C>
	{
	public:
		typedef uchar       value_type;
		typedef int         work_type;
		enum {
			depth = CV_8U,
			channels = 4,
			type = CV_MAKETYPE(depth, channels)
		};
	};


	template<> class DataType<iv::PointF>
	{
	public:
		typedef uchar       value_type;
		typedef int         work_type;
		enum {
			depth = CV_32F,
			channels = 2,
			type = CV_MAKETYPE(depth, channels)
		};
	};
#endif
}
