#include "net/strategies/StrategyUnicity.h"
#include "base/io/log/Log.h"
#include "net/Client.h"
#include "base/net/Job.h"

xmrig::StrategyUnicity::StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass) :
    m_controller(controller),
    m_url(url),
    m_user(user),
    m_pass(pass)
{
    connect();
}

xmrig::StrategyUnicity::~StrategyUnicity()
{
    for (auto &client : m_clients) {
        delete client;
    }
}

void xmrig::StrategyUnicity::tick(uint64_t now)
{
    for (auto &client : m_clients) {
        client->tick(now);
    }
}

void xmrig::StrategyUnicity::connect()
{
    Client *client = new Client(m_controller, m_url.c_str(), m_user.c_str(), m_pass.c_str());
    client->connect();
    m_clients.push_back(client);
}

void xmrig::StrategyUnicity::submitJob(const Job &job)
{
    for (auto &client : m_clients) {
        client->submit(job);
    }
}

void xmrig::StrategyUnicity::handleResult(const JobResult &result)
{
    if (result.isAccepted()) {
        Log::info("Job accepted by Unicity chain");
    } else {
        Log::error("Job rejected by Unicity chain");
    }
}

// Implement pure virtual functions from IStrategy
bool xmrig::StrategyUnicity::isActive() const
{
    return true;
}

xmrig::IClient *xmrig::StrategyUnicity::client() const
{
    return m_clients.empty() ? nullptr : m_clients.front();
}

int64_t xmrig::StrategyUnicity::submit(const JobResult &result)
{
    return 0;
}

void xmrig::StrategyUnicity::resume()
{
}

void xmrig::StrategyUnicity::setAlgo(const Algorithm &algo)
{
}

void xmrig::StrategyUnicity::setProxy(const ProxyUrl &proxy)
{
}

void xmrig::StrategyUnicity::stop()
{
}