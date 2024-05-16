#pragma once

#include <cr/basic.hpp>
#include <cr/reflect/struct.hpp>
#include <chrono>

namespace cr {

	/// 系统时钟
	using SystemClock = std::chrono::system_clock;

	/// 时间点
	using TimePoint = SystemClock::time_point;

	/// 时长
	using Duration = SystemClock::duration;

	/// 时间单位
	using ClockPeriod = SystemClock::period;

	/// 微妙
	using Microseconds = std::chrono::microseconds;

	/// 毫秒
	using Milliseconds = std::chrono::milliseconds;

	/// 秒
	using Seconds = std::chrono::seconds;

	/// 分钟
	using Minutes = std::chrono::minutes;

	/// 小时
	using Hours = std::chrono::hours;

	/// 时间区间转换
	using std::chrono::duration_cast;

	/// 时间区间
	struct TimeRange
	{
		TimePoint begin;
		TimePoint end;

		/// 区间长度
		Duration size() const { return end - begin; }

		/// 时间点所处区间位置
		double position(TimePoint tp) const 
		{
			return 1.0 * (tp - begin).count() / size().count();
		}

		/// 获取时间点
		TimePoint at(double position) const
		{
			return begin + duration_cast<Duration>(size() * position);
		}
	};


	/// 获取时区秒数
	int time_zone_secs();
	
	/// 时间点转为字符串
	string to_string(TimePoint tp);

	/// 字符串转为时间点
	TimePoint to_time_point(InString s);

	/// 字符串解析为时间，时间格式：YYYY-MM-DDTHH:MM:SS.SSSZ
	bool parse(InString str, TimePoint& tp);

	/// 字符串解析为日期，时间格式：YYYY-MM-DD
	bool parse_local_date(InString str, TimePoint& date);

	/// 获取指定毫秒的时长
	Milliseconds msec(int n);

	/// 获取指定微秒的时长
	Microseconds usec(int n);

	/// 当前时间点
	inline TimePoint now() { return SystemClock::now(); }

	/// 时间的本地表示
	string local_str(TimePoint time_point, bool has_msec = false);

	/// 日期的本地表示
	string local_date_str(TimePoint time_point = now());

	/// 时间（无日期）的本地表示
	string local_time_str(TimePoint time_point, bool has_msec = false);

	/// 纪元至今的秒数
	double secs_since_epoch(TimePoint time_point = now());

	/// 持续时间代表的秒数
	double secs(Duration duration);

	/// 纪元至今的毫秒数
	int64_t msecs_since_epoch(TimePoint time_point = now());

	/// 混合两个时间点
	TimePoint mix(TimePoint t1, TimePoint t2, double alpha);

	/// 持续时间代表的毫秒数
	int64_t msecs(Duration duration);

	/// 持续时间缩放
	Duration scale(Duration duration, double s);


	/// 日期时间成员
	struct DatetimeMember
	{
		int year;			/// <年
		int month;			/// <月
		int day;			/// <日
		int hour;			/// <时
		int minute;			/// <分
		double second;		/// <秒

		int day_of_week;	/// <星期几

		/// 获取毫秒部分
		int msec() const {	return int((second - int(second)) * 1000); }
	};
	cr_struct_7f(DatetimeMember, year, month, day, hour, minute, second, day_of_week);

	/// DatetimeMember 转字符串
	string to_string(DatetimeMember m);

	/// 字符串解析为日期时间成员，时间格式：YYYY-MM-DD[ _T]HH:MM:SS.SSS
	bool parse(InString str, DatetimeMember& dm);

	/// 字符串解析为日期成员，时间格式：YYYY-MM-DD
	bool parse_date(InString str, DatetimeMember& dm);

	/// UTC DatetimeMember转换为时间点
	TimePoint utc_time_point(DatetimeMember datetime_member);

	/// 本地DatetimeMember转换为时间点
	TimePoint local_time_point(DatetimeMember datetime_member);

	/// 获取GMT时间结构
	DatetimeMember utc_member(TimePoint time_point);

	/// 获取本地时间结构
	DatetimeMember local_member(TimePoint time_point);

	/// struct tm转化成DatetimeMember
	DatetimeMember to_datetime_member(tm tm);

	/// DatetimeMember转化成struct tm
	tm to_tm(DatetimeMember dtm);

	/// 时钟时间（时分秒）
	class ClockTime
	{
	public:
		/// 默认构造
		ClockTime() = default;

		/// 根据时分秒构造
		explicit ClockTime(int hour, int min, int sec)
			: m_secs(hour * 3600 + min * 60 + sec)
		{}

		/// 根据DatetimeMember构造
		explicit ClockTime(DatetimeMember dm)
			: m_secs(dm.hour * 3600 + dm.minute * 60 + int(dm.second))
		{}

		/// 根据TimePoint构造
		explicit ClockTime(TimePoint time_point)
			: ClockTime(local_member(time_point))
		{}

		/// 根据字符串构造
		explicit ClockTime(InString str);
	public:
		/// <获取小时
		int hour() const { return m_secs / 3600; }
		
		/// <获取分钟
		int minute() const { return m_secs / 60 % 60; }
		
		/// <获取秒
		int second() const { return m_secs % 60; }

		/// <获取自零点以来的秒数
		int seconds_since_0() const { return m_secs; }
	public:
		/// 判断是否为空
		explicit operator bool() const { return m_secs != 0; }
	public:
		/// 小于比较
		bool operator<(ClockTime ct) const { return m_secs < ct.m_secs; }
		
		/// 大于比较
		bool operator>(ClockTime ct) const { return m_secs > ct.m_secs; }

		/// 小于等于比较
		bool operator<=(ClockTime ct) const { return m_secs <= ct.m_secs; }

		/// 大于等于比较
		bool operator>=(ClockTime ct) const { return m_secs >= ct.m_secs; }

		/// 等于比较
		bool operator==(ClockTime ct) const { return m_secs == ct.m_secs; }
	public:
		/// 转化为字符串
		string to_string() const;
	private:
		int m_secs{};	//自零点以来秒数
	};


	/// 时间字符串作为ID
	string time_str_id(TimePoint time_point = now(), bool has_msec = false);


    /// 秒表
	class Stopwatch
	{
	public:
		Stopwatch();
	public:
		/// 启动计时，总时间累计
		void start();

		/// 重新启动计时
		void restart();

		/// 停止计时
		double stop();

		/// 复位
		void reset();
	public:
		/// 是否已经启动
		bool started() const;

		/// 流逝的时间
		double elapsed() const;

		/// 计数次数
		int64_t count() const;

		/// 平均时间
		double average() const;

		/// 获取描述字符串
		string to_string() const;
	private:
		bool started_ = false;
		double elapsed_ = 0;
		double start_ = 0;
		int64_t	count_ = 0;
	};
}
