#include <cr/cdd_adt/net_adt.hpp>
#include <boost/url.hpp>
#include <iostream>

using Url = boost::url;

using namespace std;

namespace cr
{
    void show_parts(const Url& url)
    {
        cout << "    Scheme: " << url.scheme() << endl;
        cout << "    User: " << url.user() << endl;
        cout << "    Password: " << url.password() << endl;
        cout << "    Host: " << url.host() << endl;
        cout << "    Port: " << url.port() << endl;
        cout << "    Path: " << url.path() << endl;
        cout << "    Query: " << url.query() << endl;
        //cout << "Params: " <<  url.params() << endl;
        //cout << "Fragment: " <<  url.fragment() << endl;
    }

    bool parse_url(string_view url_str, CrEndpoint& endpoint, CrAuthInfo& auth, string& path, StrMap& params)
    {
        auto url = Url(url_str);

        show_parts(url);

        StrX(endpoint.host) = url.host().data();
        endpoint.port = url.port_number();

        StrX(auth.user) = url.user().data();
        StrX(auth.password) = url.password().data();

        path = url.path();

        for (auto p : url.params())
        {
            params[p.key] = p.value;
        }

        return true;
    }

}
