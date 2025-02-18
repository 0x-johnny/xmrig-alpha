#ifndef XMRIG_CLIENT_H
#define XMRIG_CLIENT_H

#include <string>
#include <vector>
#include <rapidjson/document.h>

namespace xmrig {

class Controller;
class Job;

class Client
{
public:
    Client(Controller *controller, const char *url, const char *user, const char *pass);
    ~Client();

    void connect();
    void tick(uint64_t now);
    void submit(const Job &job);
    void handleResponse(const std::string &response);

private:
    Controller *m_controller;
    std::string m_url;
    std::string m_user;
    std::string m_pass;
    std::vector<Client *> m_clients;
};

} // namespace xmrig

#endif // XMRIG_CLIENT_H