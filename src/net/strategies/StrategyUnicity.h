#ifndef XMRIG_STRATEGYUNICITY_H
#define XMRIG_STRATEGYUNICITY_H

#include "base/net/strategies/Strategy.h"
#include "net/Client.h"
#include <string>
#include <vector>

namespace xmrig {

class StrategyUnicity : public Strategy
{
public:
    StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass);
    ~StrategyUnicity() override;

    void tick(uint64_t now) override;
    void connect() override;
    void submitJob(const Job &job);
    void handleResult(const JobResult &result);

private:
    std::string m_url;
    std::string m_user;
    std::string m_pass;
    std::vector<Client *> m_clients;
};

} // namespace xmrig

#endif // XMRIG_STRATEGYUNICITY_H