#include "net/strategies/StrategyUnicity.h"
#include "base/io/log/Log.h"
#include "net/Client.h"
#include "base/net/Job.h"

xmrig::StrategyUnicity::StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass) :
    Strategy(controller),
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
    // Handle periodic tasks, such as checking the connection status or submitting results
    for (auto &client : m_clients) {
        client->tick(now);
    }
}

void xmrig::StrategyUnicity::connect()
{
    // Connect to the Unicity chain
    Client *client = new Client(m_controller, m_url.c_str(), m_user.c_str(), m_pass.c_str());
    client->connect();
    m_clients.push_back(client);
}

void xmrig::StrategyUnicity::submitJob(const Job &job)
{
    // Submit a job to the Unicity chain
    for (auto &client : m_clients) {
        client->submit(job);
    }
}

void xmrig::StrategyUnicity::handleResult(const JobResult &result)
{
    // Handle the result from the Unicity chain
    if (result.isAccepted()) {
        Log::info("Job accepted by Unicity chain");
    } else {
        Log::error("Job rejected by Unicity chain");
    }
}