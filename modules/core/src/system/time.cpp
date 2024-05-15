
#include <cr/system/time.hpp>

#include <chrono>
#include <ctime>

using namespace std;

//日期时间格式:https://zh.wikipedia.org/wiki/ISO_8601

namespace cr {

    typedef std::chrono::system_clock sc;

    static const char *time_format = "%02d:%02d:%02d";

    string to_string(TimePoint time_point) {
        const char *fmt = "%04d-%02d-%02dT%02d:%02d:%02d.%03dZ";

        auto tc = utc_member(time_point);
        char str[128];

        sprintf(str, fmt, tc.year, tc.month, tc.day, tc.hour, tc.minute, int(tc.second), tc.msec());
        return str;
    }


    int time_zone_secs() {
        time_t utc_time = 24 * 3600;        //utc:1970-01-02

        tm tm{};
        tm.tm_year = 70;
        tm.tm_mday = 2;
        time_t local_time = mktime(&tm);    //local:1970-01-02

        return int(utc_time - local_time);
    }


    TimePoint to_time_point(InString str) {
        TimePoint tp{};
        parse(str, tp);
        return tp;
    }


    bool parse(InString str, TimePoint &tp) {
        const char *fmt = "%04d-%02d-%02dT%02d:%02d:%lfZ";
        DatetimeMember d{};
        auto n = sscanf(str.c_str(), fmt, &d.year, &d.month, &d.day, &d.hour, &d.minute, &d.second);
        if (n != 6) return false;

        tp = utc_time_point(d);
        return true;
    }


    bool parse_local_date(InString str, TimePoint &date) {
        DatetimeMember d{};
        if (!parse_date(str, d)) return false;
        date = local_time_point(d);
        return true;
    }


    Milliseconds msec(int n) {
        return Milliseconds(n);
    }


    Microseconds usec(int n) {
        return Microseconds(n);
    }


    int64_t msecs_since_epoch(TimePoint time_poin) {
        return msecs(time_poin.time_since_epoch());
    }


    int64_t msecs(Duration duration) {
        return duration.count() * ClockPeriod::num / (ClockPeriod::den / 1000);
    }


    double secs(Duration duration) {
        return 1.0 * duration.count() * ClockPeriod::num / ClockPeriod::den;
    }


    Duration scale(Duration duration, double s) {
        return duration_cast<Duration>(duration * s);
    }


    TimePoint mix(TimePoint t1, TimePoint t2, double alpha) {
        auto d = (t2 - t1).count() * alpha;
        return t1 + Duration(Duration::rep(d));
    }


    double secs_since_epoch(TimePoint time_point) {
        return secs(time_point.time_since_epoch());
    }


    DatetimeMember to_datetime_member(tm tm) {
        DatetimeMember tc = {
                .year = 1900 + tm.tm_year,
                .month = 1 + tm.tm_mon,
                .day = tm.tm_mday,
                .hour = tm.tm_hour,
                .minute = tm.tm_min,
                .second = double(tm.tm_sec),
                .day_of_week = tm.tm_wday,
        };
        return tc;
    }


    tm to_tm(DatetimeMember dtm) {
        tm t = {
                .tm_sec = int(dtm.second),
                .tm_min = dtm.minute,
                .tm_hour = dtm.hour,
                .tm_mday = dtm.day,
                .tm_mon = dtm.month - 1,
                .tm_year = dtm.year - 1900,
                .tm_wday = dtm.day_of_week,
        };
        return t;
    }


    template<typename F>
    DatetimeMember time_nember(TimePoint time_point, F fun) {
        auto msecs = msecs_since_epoch(time_point);
        time_t timep = std::max(msecs / 1000, int64_t{});    //纪元前时间不被一些函数支持
        auto tm = *fun(&timep);

        DatetimeMember dm = to_datetime_member(tm);
        dm.second += (msecs % 1000) / 1000.0;

        return dm;
    }


    DatetimeMember utc_member(TimePoint time_point) {
        return time_nember(time_point, gmtime);
    }


    DatetimeMember local_member(TimePoint time_point) {
        return time_nember(time_point, localtime);
    }


    bool parse(InString str, DatetimeMember &dm) {
        const char *fmt = "%04d-%02d-%02d%c%02d:%02d:%lf";
        string seps = " T_";

        DatetimeMember d{};
        char sep;
        auto n = sscanf(str.c_str(), fmt, &d.year, &d.month, &d.day, &sep, &d.hour, &d.minute, &d.second);
        if (n != 7 || seps.find(sep) == string::npos) return false;

        dm = d;
        return true;
    }


    bool parse_date(InString str, DatetimeMember &dm) {
        const char *fmt = "%04d-%02d-%02d";

        DatetimeMember d{};
        auto n = sscanf(str.c_str(), fmt, &d.year, &d.month, &d.day);
        if (n != 3) return false;
        dm = d;
        return true;
    }


    TimePoint utc_time_point(DatetimeMember datetime_member) {

        return local_time_point(datetime_member) + Seconds(time_zone_secs());
    }


    TimePoint local_time_point(DatetimeMember datetime_member) {
        auto tm = to_tm(datetime_member);
        time_t t = mktime(&tm);    //1970-01-01的本地时间是无效值

        Milliseconds ms(t * 1000 + datetime_member.msec());
        return TimePoint(ms);
    }


    string local_str(TimePoint time_point, bool has_msec) {
        auto tc = local_member(time_point);

        char str[128];
        if (has_msec) {
            sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d.%03d", tc.year, tc.month, tc.day, tc.hour, tc.minute,
                    int(tc.second), tc.msec());
        } else {
            sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d", tc.year, tc.month, tc.day, tc.hour, tc.minute,
                    int(tc.second));
        }
        return str;
    }


    string local_date_str(TimePoint time_point) {
        auto tc = local_member(time_point);
        char str[128];
        sprintf(str, "%04d-%02d-%02d", tc.year, tc.month, tc.day);
        return str;
    }


    string local_time_str(TimePoint time_point, bool has_msec) {
        auto tc = local_member(time_point);

        char str[128];
        if (has_msec) {
            sprintf(str, "%02d:%02d:%02d.%03d", tc.hour, tc.minute, int(tc.second), tc.msec());
        } else {
            sprintf(str, time_format, tc.hour, tc.minute, int(tc.second));
        }
        return str;
    }


    ClockTime::ClockTime(InString str)
            : m_secs() {
        int hour, min, sec;
        auto n = sscanf(str.c_str(), time_format, &hour, &min, &sec);
        if (n == 3) {
            m_secs = ClockTime(hour, min, sec).m_secs;
        }
    }


    string ClockTime::to_string() const {
        char str[64];
        sprintf(str, time_format, hour(), minute(), second());
        return str;
    }

#if 0
    string time_str_id(TimePoint time_point, bool has_msec)
    {
        string s = local_str(time_point, has_msec);
        return to_id(s);
    }
#endif

    Stopwatch::Stopwatch() {}


    void Stopwatch::start() {
        if (started_) return;
        count_++;
        start_ = secs_since_epoch();
        started_ = true;
    }


    void Stopwatch::restart() {
        reset();
        start();
    }


    double Stopwatch::stop() {
        if (!started()) return 0;
        auto d = secs_since_epoch() - start_;
        elapsed_ += d;
        started_ = false;
        return d;
    }


    void Stopwatch::reset() {
        *this = Stopwatch();
    }


    bool Stopwatch::started() const {
        return started_;
    }


    double Stopwatch::elapsed() const { return elapsed_; }


    int64_t Stopwatch::count() const { return count_; }


    double Stopwatch::average() const { return elapsed_ / count_; }


    string Stopwatch::to_string() const {
        char str[256] = {};
        sprintf(str, "Stopwatch(count:%ld elapsed:%f average:%f)",
                count(), elapsed(), average());
        return str;
    }
}
