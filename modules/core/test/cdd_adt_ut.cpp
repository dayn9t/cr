
#include <cr/cdd_adt.hpp>
#include <cr/test.hpp>


TEST(cdd, parse_url) {

    auto url = "hikn://admin:pass@10.1.0.21:8000/record/101?start_time=2024-07-28T12:00:00&end_time=2024-07-28T12:10:00";
    string host("10.1.0.21");
    auto port = 8000;
    string user("admin");
    string password("pass");
    string path1("/record/101");
    StrMap queries1 = {{"start_time", "2024-07-28T12:00:00"}, {"end_time", "2024-07-28T12:10:00"}};

    CrEndpoint endpoint = {};
    CrAuthInfo auth = {};
    string path;
    StrMap queries;
    TR(parse_url(url, endpoint, auth, path, queries));

    EQ(endpoint.host, host);
    EQ(endpoint.port, port);

    EQ(auth.user, user);
    EQ(auth.password, password);

    EQ(path, path1);

    EQ(queries, queries1);

}


TEST(CrPoint, all) {
    CrPoint p0 = {1, 1};
    auto q0 = get_point(p0);
    p0 = to_c(q0);

    auto r1 = 1.0;
            EQ(r1, 1.0);


}

