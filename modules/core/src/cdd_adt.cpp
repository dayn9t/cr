#include <cr/cdd_adt.hpp>
#include <boost/url.hpp>

using Url = boost::url;

namespace cr
{
    bool parse_url(InString& url_str, CrEndpoint& endpoint, CrAuthInfo& auth, StrMap& params)
    {
        auto url = Url(url_str);
        strncpy(endpoint.hostname, url.host().data(), CR_HOSTNAME_MAX_LEN);
        endpoint.port_number = url.port_number();

        strncpy(auth.user, url.user().data(), CR_USER_MAX_LEN);
        strncpy(auth.password, url.password().data(), CR_PASSWORD_MAX_LEN);


        for (auto p : url.params())
        {
            params[p.key] = p.value;
        }

        return true;
    }


    ImageChannel from_c(CrImageChannel& channel)
    {
        return ImageChannel(
            get_size(channel.size),
            channel.data,
            channel.pitch,
            channel.col_step
        );
    }

    CrImageChannel to_c(ImageChannel& channel)
    {
        return CrImageChannel{
            .size = to_c(channel.size()),
            .pitch = channel.pitch(),
            .col_step = channel.col_step(),
            .data = channel.data()
        };
    }

    Image from_c(CrImage& image)
    {
        ImageChannels channels;
        for (size_t i = 0; i < image.channel_num; ++i)
        {
            channels.push_back(from_c(image.channels[i]));
        }

        return Image(
            image.format,
            get_size(image.size),
            channels
        );
    }

    CrImage to_c(Image& image)
    {
        CrImage img = {
            .format = image.format(),
            .size = to_c(image.size()),
            .channel_num = static_cast<U32>(image.channels().size()),
        };
        auto& cs = image.channels();
        for (size_t i = 0; i < cs.size(); ++i)
        {
            img.channels[i] = to_c(cs[i]);
        }
        return img;
    }
}
